#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover image \n");
        return 1;
    }

    char *file_name = argv[1];
    char img_name[] = "000.jpg";
    BYTE buffer[512];

    int num_bytes_read, num_images = 0;

    // open input file
    FILE *raw_image = fopen(file_name, "r");
    if (raw_image == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", file_name);
        return 1;
    }

    FILE *image = fopen(img_name, "w");

    for(;;){
        num_bytes_read = fread(&buffer, 1, 512, raw_image);
        if (num_bytes_read < 512)
        {
            fwrite(&buffer, num_bytes_read, 1, image);
            break;
        }
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            fclose(image);
            image = fopen(img_name, "w");
            fwrite(&buffer, sizeof(buffer), 1, image);
            num_images++;
            sprintf(img_name, "%03i.jpg", num_images);
        } else {
            fwrite(&buffer, sizeof(buffer), 1, image);
        }
    }

    fclose(raw_image);
    fclose(image);

    return 0;
}
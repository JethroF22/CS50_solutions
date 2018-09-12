#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    } else {
        string cipher = argv[1];
        int cipher_len = strlen(cipher);

        for (int i = 0; i < cipher_len; ++i)
        {
            if (!isalpha(cipher[i]))
            {
                printf("Usage: ./vigenere k\n");
                return 1;
            }
        }
        string text = get_string("plaintext: ");
        int str_len = strlen(text);
        char cipher_text[str_len + 1];
        int cipher_index = 0;

        for (int i = 0; i < str_len; ++i)
        {
            char c = text[i];
            int is_uppercase = isupper(c);
            char limit = (is_uppercase ? 'Z' : 'z');
            if (isalpha(c))
            {
                char cipher_c = is_uppercase ? toupper(cipher[cipher_index]) : cipher[cipher_index];
                int difference = cipher_c - (is_uppercase ? 65 : 97);
                if (c + difference > limit)
                {
                    int adjusted_shift = c + difference - limit - 1;
                    cipher_text[i] = (char) (adjusted_shift + (is_uppercase ? 'A' : 'a'));
                } else {
                    cipher_text[i] = ((int) (c) + difference);
                }

                cipher_index = cipher_index == cipher_len - 1 ? 0 : cipher_index + 1;
            } else {
                cipher_text[i] = c;
            }
        }
        cipher_text[str_len] = '\0';
        printf("ciphertext: %s\n", cipher_text);
    }

    return 0;
}
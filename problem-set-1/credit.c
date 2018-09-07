#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  string num_string;
  int even_sum = 0, odd_sum = 0, total_sum = 0, len;

  do
   {
     num_string = get_string("Number: ");
   } while (atoll(num_string) <= 0);

  len = strlen(num_string);

  if (len < 13)
  {
    printf("INVALID\n");
  } else {
    bool isEven = len % 2 == 0;

   for (int i = len - 1; i >= 0; --i)
   {
    int digit = (int) (num_string[i] - '0');

    if ((i + 1) % 2 == (isEven ? 1 : 0))
    {
      int product = digit * 2;
      char product_str[12];
      sprintf(product_str, "%d", product);
      for (int j = 0, n = strlen(product_str); j < n; ++j)
      {
        digit = (int) (product_str[j] - '0');
        even_sum += (int) (product_str[j] - '0');
      }
    } else {
      odd_sum += digit;
    }
   }

   total_sum = even_sum + odd_sum;
   if (total_sum % 10 == 0)
   {
    char identifier[3];
    strncpy(identifier, num_string, (num_string[0] == '4' ? 1 : 2));

    switch (atoi(identifier))
     {
      case 51:
      case 52:
      case 53:
      case 54:
      case 55:
        printf("MASTERCARD\n");
        break;
      case 34:
      case 37:
        printf("AMEX\n");
        break;
      case 4:
        printf("VISA\n");
        break;
      default:
        printf("INVALID\n");
        break;
     }
   } else {
      printf("INVALID\n");
   }
  }

   return 0;
}
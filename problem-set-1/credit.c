#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
  string num_string;

  do
   {
     num_string = get_string("Number: ");
   } while (atoll(num_string) <= 0);

   printf("%s\n", num_string);
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
  if (argc != 2)
  {
    return 1;
  }

  int shift = atoi(argv[1]) % 26;
  int str_len;
  string text;

  text = get_string("plaintext: ");
  str_len = strlen(text);
  char cipher_text[str_len + 1];

  for (int i = 0; i < str_len; ++i)
  {
    char c = text[i];
    if (isalpha(c))
    {
      char limit = (isupper(c) ? 'Z' : 'z');
      int difference = (isupper(c) ? 64 : 96);
      if (c + shift > limit)
      {
        int adjusted_shift = c + shift - limit;
        cipher_text[i] = (char) (adjusted_shift + difference);
      } else {
        cipher_text[i] = (c + shift);
      }
    } else {
      cipher_text[i] = c;
    }
  }
  cipher_text[str_len] = '\0';

  printf("ciphertext: %s\n", cipher_text);

  return 0;
}

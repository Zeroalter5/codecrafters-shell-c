#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  // Flush after every printf
  setbuf(stdout, NULL);

  while (1)
  {
    // Uncomment this block to pass the first stage
    // printf("$ ");
    printf("$ ");
    // Wait for user input
    char input[100];
    fgets(input, 100, stdin);
    // fgets will read a '\n' into the string
    // if the input is not empty
    int len = strlen(input);
    if (len != 0)
    {
      input[len - 1] = '\0'; // delete the last '\n'
      if (len == 7 && !strncmp(input, "exit 0", 6)) // len is the length of string when the string still has '\n'
      {
        return 0;
      }
      if (!strncmp(input, "echo ", 5))
      {
        if (len > 5)
        {
          printf("%s\n", &input[5]);
          // '\n'!!!
        }
      }
      else
      {
        printf("%s: command not found\n", input);
      }
    }
    // memset(input, 0, sizeof(input));
  }
  return 0;
}

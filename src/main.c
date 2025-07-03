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
      if (!strcmp(input, "exit 0")) {
        break;
      }
      printf("%s: command not found\n", input);
    }
    // memset(input, 0, sizeof(input));
  }
  return 0;
}

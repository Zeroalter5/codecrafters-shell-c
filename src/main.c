#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int type(char *, int);
int echo(char *, int);
int my_exit(char *, int);

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
      len = strlen(input);

      if (my_exit(input, len)) // len is the length of string when the string still has '\n'
      {
        return 0;
      }
      if (!(echo(input, len) || type(input, len)))
      {
        printf("%s: command not found\n", input);
      }
    }
    // memset(input, 0, sizeof(input));
  }
  return 0;
}

int type(char *input, int len)
{
  if (!strncmp(input, "type ", 5))
  {
    if (len > 5)
    {
      const char* str = &input[5];
      if (len - 5 == 4)
      {
        if (!strncmp(str, "type", 4)) // Attention! strncmp return 0 when the two strings are equal
        {
          printf("type is a shell builtin\n");
        }
        else if (!strncmp(str, "echo", 4))
        {
          printf("echo is a shell builtin\n");
        }
        else if (!strncmp(str, "exit", 4))
        {
          printf("exit is a shell builtin\n");
        }
      }
      else
      {
        printf("%s: not found\n", str);
      }
    }
    return 1;
  }
  return 0;
}

int echo(char *input, int len)
{
  if (!strncmp(input, "echo ", 5))
  {
    if (len > 5)
    {
      printf("%s\n", &input[5]);
      // '\n'!!!
    }
    return 1;
  }
  return 0;
}

int my_exit(char *input, int len)
{
  return len == 6 && !strncmp(input, "exit 0", 6);
}
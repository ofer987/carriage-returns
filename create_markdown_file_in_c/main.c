#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static char *file_name = "text2.md";

static char NEWLINE = 10;
static char CARRIAGE_RETURN = 13;

FILE *open_file(char *file_name, char *mode);
void close_file(FILE *fptr);
void write(char *message, int size, FILE *fptr);

int main(int argc, char **argv)
{
  FILE *markdown_file = open_file(file_name, "wb");

  char *message = "Hello World";

  fwrite(message, strlen(message), 1, markdown_file);
  fwrite(&NEWLINE, sizeof(char), 1, markdown_file);
  fwrite(&CARRIAGE_RETURN, sizeof(char), 1, markdown_file);

  close_file(markdown_file);

  FILE *read_markdown_file = open_file(file_name, "rb");

  char character_code;
  int size = 0;
  while ((size = fread(&character_code, sizeof(char), 1, markdown_file)) != 0)
  {
    printf("Character is:\t%c.\tCode is:\t%d.\n", character_code, character_code);
  }

  close_file(read_markdown_file);

  return 0;
}

FILE *open_file(char *file_name, char *mode)
{
  FILE *result = fopen(file_name, mode);
  if (result == NULL)
  {
    printf("Error opening file '%s'\n", file_name);

    exit(1);
  }

  return result;
}

void close_file(FILE *fptr)
{
  if (fclose(fptr) != 0)
  {
    printf("Error closing file\n");

    exit(1);
  }
}

void write(char *message, int size, FILE *fptr)
{
  if (fwrite(message, size, 1, fptr) == 0)
  {
    printf("Error writing to file\n");

    exit(1);
  }
}

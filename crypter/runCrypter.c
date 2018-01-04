#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc (warning)
#include "crypto.h"

int main(int argi, char* argv[]) {
  if (argi == 1) {
    printf("No parameters \n");
    return 0;
  }
  KEY key = {1, argv[1]};
  char input[255];
  int error = 0;
  int forEncrypt = (strstr(argv[0], "encrypt") != 0);
  char* result;
  if (argi == 2) {
    fgets(input, 254, stdin);
    input[strlen(input) - 1] = '\0';
    result = (char*) malloc(sizeof(char) * (strlen(input) + 1));
    error = (forEncrypt) ? encrypt(key, input, result) : decrypt(key, input, result);
    printf("%s\n", result);
    free(result);
  }

  if (argi == 3) {
    FILE* inputText = fopen(argv[2], "r");

    if (inputText == NULL) {
      fprintf(stderr, "Error: File '%s' not found\n", argv[2]);
      return 5;
    }

    while (fgets(input, 254, inputText) && error == 0) {
      input[strlen(input) - 1] = '\0';
      result = (char*) malloc(sizeof(char) * (strlen(input) + 1));

      error = (forEncrypt) ? encrypt(key, input, result) : decrypt(key, input, result);
      printf("%s\n", result);
      free(result);
    }
    fclose(inputText);
  }

  if (error == E_KEY_ILLEGAL_CHAR)
    fprintf(stderr, "Error: Key contains illegal characters\n");

  if (error == E_CYPHER_ILLEGAL_CHAR)
    fprintf(stderr, "Error: crypted text contains illegal chars\n");

  if (error == E_KEY_TOO_SHORT)
    fprintf(stderr, "Error: key too short\n");

  if (error == E_MESSAGE_ILLEGAL_CHAR)
    fprintf(stderr, "Error: Message contains illegal characters\n");

  //free(output);
  return error;
}

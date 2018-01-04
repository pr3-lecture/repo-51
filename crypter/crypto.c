#include <stdio.h>
#include "crypto.h"
#include <string.h>

int xorCrypt(KEY key, const char* input, char* output){

  int step = 64;
  int i;
  int lenKey = strlen(key.chars);
  int lenInput = strlen(input);
  for(i = 0; i < lenInput; i++){
    int indexKey = i % lenKey;
    output[i] = (step + ((input[i] - step)^(key.chars[indexKey] - step)));
  }
  return 0;
}

int decrypt(KEY key, const char* input, char* output){

  if(strlen(key.chars) < 1){
    return E_KEY_TOO_SHORT;
  }

  if(illegalChars(key.chars, KEY_CHARACTERS)){
    return E_KEY_ILLEGAL_CHAR;
  }

  if(illegalChars(input, CYPHER_CHARACTERS)){
    return E_CYPHER_ILLEGAL_CHAR;
  }

  xorCrypt(key, input, output);

  return 0;
}

int encrypt(KEY key, const char* input, char* output){

  if(strlen(key.chars) < 1){
    return E_KEY_TOO_SHORT;
  }

  if(illegalChars(key.chars, KEY_CHARACTERS)){
    return E_KEY_ILLEGAL_CHAR;
  }

  if(illegalChars(input, MESSAGE_CHARACTERS)){
    return E_MESSAGE_ILLEGAL_CHAR;
  }

  xorCrypt(key, input, output);

  return 0;
}

int illegalChars(const char* input, const char* allowedchars){

  int i;
  int lenInput = strlen(input);
  int lenAllowed = strlen(allowedchars);
  int found;
  for(i = 0; i < lenInput; i++){

    int j;
    found = 0;
    for(j = 0; j < lenAllowed; j++){

      if(input[i] == allowedchars[j]){
        found = 1;
        break;
      }
    }

    if(found == 0){
      return 1;
    }
  }

  return 0;
}

/*
int main(){

    char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cypher[] = "URFVPJB[]ZN^XBJCEBVF@ZRKMJ";
    char tpeKey[] = "TPERULES";
    KEY key;
    key.type = 1;
    key.chars = tpeKey;

    char output[32] = "";
    char encrypted[8] = "";
    decrypt(key,input,output);
    //encrypt(key, input, &output);
    printf("\nOutput = %s\n", output);

    //decrypt(key, output, &encrypted);
    //printf("\nOutput = %s\n", output);
    return 0;
}*/

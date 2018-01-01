#include <stdio.h>

typedef struct {
    int type; /* Type of the key. */
    char* chars; /* Key characters. */
} KEY;

int currentKeyChar(KEY key, const int *index, char *c){
 
    int length = sizeof(key.chars);
    int currentIndex = index;
    if(index >= length){
        int factor = currentIndex/length;
        currentIndex = currentIndex-length*factor;
    }
    *c = key.chars[currentIndex];
    return 0;
}

int crypt(KEY key, const char* input, char* output){
    printf("crypted: ");
    for(int i = 0; i < strlen(input); i++){
        currentKeyChar(key, i, output);
        int a = *output - 64;
        int b = input[i] - 64;
        int result = a^b;
        char c = (result + 64);
        output[i] = c;
        printf("%c",c);
    }
    return 0;
}

int decrypt(KEY key, const char* cypherText, char* output){
    printf("\ndecrypted: ");
     for(int i = 0; i < strlen(cypherText); i++){        
        currentKeyChar(key, i, output);
        int a = *output - 64;
        int b = cypherText[i] - 64;
        int result = a^b;
        char c = result + 64;
        printf("%c",c);
    }
    return 0;
}

int main(){
    
    char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *tpeKey = "TPERULES";
    KEY key;
    key.chars = tpeKey;
    
    char output[32] = "a";
    char encrypted[32] = "a";
    
    crypt(key, input, &output);
    printf("\nOutput = %s\n", output);
    
    decrypt(key, output, &encrypted);
    printf("\nOutput = %s\n", output);
    return 0;
}

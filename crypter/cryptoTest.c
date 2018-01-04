#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

#include "crypto.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int tests_run = 0;

static char* test_key_too_short(){
  KEY key = { 0, "" };
  char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ+";
  char output[32] = "";
  int result = encrypt(key, input, output);
  mu_assert("key error: key too shoort", result == E_KEY_TOO_SHORT);

  return 0;
}

static char* test_key_illegal_char(){
  KEY key = { 1, "#" };
  char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ+";
  char output[32] = "";
  int result = encrypt(key, input, output);
  mu_assert("key error: key has illegal chars", result == E_KEY_ILLEGAL_CHAR);

  return 0;
}

static char* test_message_illegal_char(){
  KEY key = { 1, "TPERULES" };
  char input[] = "#ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char output[32] = "";
  int result = encrypt(key, input, output);
  mu_assert("encrypt error: input has illegal chars", result == E_MESSAGE_ILLEGAL_CHAR);

  return 0;
}

static char* test_cypher_illegal_char(){
  KEY key = { 1, "TPERULES" };
  char input[] = "#URFVPJB[]ZN^XBJCEBVF@ZRKMJ";
  char output[32] = "";
  int result = decrypt(key, input, output);
  mu_assert("decrypt error: input has illegal chars", result == E_CYPHER_ILLEGAL_CHAR);

  return 0;
}

static char* test_decrypt(){
  KEY key = { 1, "TPERULES" };
  char input[] = "URFVPJB[]ZN^XBJCEBVF@ZRKMJ";
  char output[32] = "";
  decrypt(key, input, output);
  mu_assert("decrypt output error", strcmp(output, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0);

  return 0;
}

static char* test_encrypt(){
  KEY key = { 1, "TPERULES" };
  char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char output[32] = "";
  encrypt(key, input, output);
  mu_assert("encrypt output error", strcmp(output, "URFVPJB[]ZN^XBJCEBVF@ZRKMJ") == 0);

  return 0;
}

static char* allTests() {
    mu_run_test(test_key_too_short);
    mu_run_test(test_key_illegal_char);
    mu_run_test(test_cypher_illegal_char);
    mu_run_test(test_message_illegal_char);
    mu_run_test(test_encrypt);
    mu_run_test(test_decrypt);
    /* weitere Tests */
    return 0;
}

int main() {
    char *result = allTests();

    if (result != 0) printf("%s\n", result);
    else             printf("ALL TESTS PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

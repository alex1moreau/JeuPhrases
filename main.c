# include <stdio.h>
# include <stdlib.h>
# include "game.h"
# include "op.h"

#include <ctype.h>
#include <string.h>

void EscapePrint(int ch) {
  // Delete or adjust these 2 arrays per code's goals
  // All simple-escape-sequence C11 6.4.4.4
  static const char *escapev = "\a\b\t\n\v\f\r\"\'\?\\";
  static const char *escapec = "abtnvfr\"\'\?\\";
  char *p = strchr(escapev, ch);
  if (p && *p) {
    printf("\\%c", escapec[p - escapev]);
  } else if (isprint(ch)) {
    fputc(ch, stdout);
  } else {
    // Use octal as hex is problematic reading back
    printf("\\%03o", ch);
  }
}

void EscapePrints(const char *data, int length) {
  while (length-- > 0) {
    EscapePrint((unsigned char) *data++);
  }
}

int main(int argc, char const *argv[]) {
    for (int i = 0; i < argc; i++)
        printf("%s   ", argv[i]);
    printf("\n");

    char *sentence = load_sentence();
    char *sentence_clean = clean_sentence(sentence); //malloc
    char *sentence_hide = hide_sentence(sentence_clean); //malloc
    print_sentence(sentence_hide);

    free(sentence_clean);
    free(sentence_hide);

    return 0;
}

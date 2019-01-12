# include <stdio.h>
# include <stdlib.h>
# include "game.h"
# include "op.h"

#include <ctype.h>
#include <string.h>

int main() {
    int life = 3;
    char *sentence = load_sentence();
    char *sentence_clean = clean_sentence(sentence); //malloc
    //printf("%s\n", sentence_clean);
    char *sentence_hide = hide_sentence(sentence_clean); //malloc
    print_sentence(sentence_hide, life);

    while (!state(sentence_hide)) {
        char c = getchar();
        if (c != '\n') {
            int try = try_letter(c, sentence_clean, sentence_hide);
            if (try == 0)
                life--;
            system("clear");
            print_sentence(sentence_hide, life);
            if (life == 0)
                break;
        }
    }
    if (life > 0)
        printf("You won!\n");
    else
        printf("Game Over!\nAnswer was : \"%s\"\n", sentence_clean);

    free(sentence_clean);
    free(sentence_hide);

    return 0;
}

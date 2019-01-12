# include <stdio.h>
# include <stdlib.h>

int len_sentence(char *s) { //nb of elmts in sentence
    int res = 0;
    while (*(s+res) != '\0')
        res++;
    return res;
}

char *clean_sentence(char *s) { //replace lower case and delete '\n'
    char *res = malloc(50*sizeof(char));
    int len = len_sentence(s), j = 0;

    for (int i = 0; i < len-1; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            res[j] = s[i] - 32;
        else
            res[j] = s[i];
        j++;
    }
    res[j] = '\0';
    return res;
}

char *hide_sentence(char *s) { //hide consonants => replace by '_'
    char *res = malloc(50*sizeof(char));
    char list[5] = {' ', '-', '!', '.', '\''};
    int len = len_sentence(s), j = 0;

    for (int i = 0; i < len; i++) {
        int bool = 0;
        for (int k = 0; k < 5; k++) {
            if (list[k] == s[i]) {
                bool = 1;
                res[j] = s[i];
            }
        }
        if (!bool) {
            int r = rand() % 10;
            if (r > 7)
                res[j] = s[i];
            else
                res[j] = '_';
        }
        j++;
    }
    res[j] = '\0';
    return res;
}

void print_sentence(char *s, int life) { //print sentence
    char pendu[4][30] = {   "  Ö\n/[ ]\\\n / \\",
                            "  Ö\n/[ ]\\",
                            "  Ö",
                            "\0"};
    printf("\n%s\n\n", pendu[life]);
    int len = len_sentence(s);
    for (int i = 0; i < len+6; i++)
        printf("=");
    printf("\n|  %s  |\n", s);
    for (int i = 0; i < len+6; i++)
        printf("=");
    printf("\n");
}

int try_letter(char c, char *s, char *h) { //insert letter if possible
    if (c >= 'a' && c <= 'z')
        c -= 32;
    int len = len_sentence(s), bool = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == c) {
            h[i] = c;
            bool = 1;
        }
    }
    return bool;
}

int state(char *h) { //return 1 if victory
    int len = len_sentence(h);
    for (int i = 0; i < len; i++) {
        if (h[i] == '_')
            return 0;
    }
    return 1;
}

#ifndef GAME_H
#define GAME_H

void print_sentence(char *s, int life);
char *clean_sentence(char *s);
char *hide_sentence(char *s);
int try_letter(char c, char *s, char *h);
int state(char *h);

#endif

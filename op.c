# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <err.h>

int random_line(int nblines) {
    srand(time(0));
    int r = rand() % nblines;
    return r;
}

int getline(char **lineptr, size_t *n, FILE *stream);

int nblines() {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    int nblines = 0;

    fp = fopen("data", "r");
    if (fp == NULL)
        errx(1, "Data file doesn't exist!");

    while ((getline(&line, &len, fp)) != -1)
        nblines++;

    fclose(fp);
    if (line)
        free(line);

    return nblines;
}

char* load_sentence() {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;

    fp = fopen("data", "r");
    if (fp == NULL)
        errx(1, "Data file doesn't exist!");

    int n = nblines();
    int r = random_line(n);

    int count = 0;
    while (count != r + 1) {
        count++;
        getline(&line, &len, fp);
    }
    fclose(fp);

    return line;
}

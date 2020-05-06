#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>

#define SIZE 256
#define BUFSIZE 256

void score_init(double *s, const char *f)
{
    int fd;
    unsigned char ch;
    unsigned char buffer[BUFSIZE];
    size_t bufs = 0, bufi = 0;
    double nb = 0;

    fd = open(f, O_RDONLY);
    assert(fd != -1);

    for(size_t i = 0; i < SIZE; i++)
        s[i] = 0;

    do {
        if (bufs == bufi) {
            ssize_t n = read(fd, buffer, BUFSIZE);
            assert(n >= 0);
            if (n == 0)
                break;
            bufs = n;
            bufi = 0;
        }
        ch = buffer[bufi];
        bufi += 1;
        s[ch] += 1;
        nb += 1;
    } while(true);

    for(size_t i = 0; i < SIZE; i++)
        s[i] = 100.0 * 100.0 * s[i] / nb;

    fd = close(fd);
    assert(fd != -1);
}

double calculate_distance(double *s, double *t) {
    double distance = 0.0;

    for(size_t i = 0; i < SIZE; i++) {
        double si = s[i];
        double ti = t[i];
        double di = si - ti;
        distance += di * di;
    }

    return (sqrt(distance));
}

double print_distance(double *s, const char *n, const char *f) {
    double t[SIZE];
    double distance;

    score_init(t, f);
    distance = calculate_distance(s, t);

    printf("Distance between \"%s\" and \"%s\" is : %.02f\n", n, f, distance);

    return distance;
}

void which_language(double *s1, const char *n1, double *s2, const char *n2, const char *f) {
    double d1, d2;

    d1 = print_distance(s1, n1, f);
    d2 = print_distance(s2, n2, f);

    printf("Guessed language: %s : %s\n\n", d1 > d2 ? n2 : n1, f);
}

int main()
{
    double scoreEN[SIZE];
    double scoreFR[SIZE];

    score_init(scoreEN, "candide-EN.txt");
    score_init(scoreFR, "candide-FR.txt");

    which_language(scoreEN, "EN", scoreFR, "FR", "candide-EN.txt");
    which_language(scoreEN, "EN", scoreFR, "FR", "candide-FR.txt");
    
    which_language(scoreEN, "EN", scoreFR, "FR", "artFR01.txt");
    which_language(scoreEN, "EN", scoreFR, "FR", "artFR02.txt");
    which_language(scoreEN, "EN", scoreFR, "FR", "artFR03.txt");
    
    which_language(scoreEN, "EN", scoreFR, "FR", "artEN01.txt");
    which_language(scoreEN, "EN", scoreFR, "FR", "artEN02.txt");
    which_language(scoreEN, "EN", scoreFR, "FR", "artEN03.txt");

    which_language(scoreEN, "EN", scoreFR, "FR", __FILE__);
    which_language(scoreEN, "EN", scoreFR, "FR", "Makefile");
    which_language(scoreEN, "EN", scoreFR, "FR", ".gitignore");

    return (0);
}
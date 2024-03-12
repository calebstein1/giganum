#ifndef GIGANUM_GIGANUM_H
#define GIGANUM_GIGANUM_H

#include <stdbool.h>

#define MAX_DIGITS 256

typedef struct {
    char val[MAX_DIGITS];
    int ndigits;
} giganum_t;

giganum_t* giga_init(char* num_str);
void giga_print(giganum_t* giganum);

#endif //GIGANUM_GIGANUM_H

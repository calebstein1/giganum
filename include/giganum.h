#ifndef GIGANUM_GIGANUM_H
#define GIGANUM_GIGANUM_H

#include <stdbool.h>

#define MAX_DIGITS 256
#define giga_init(...) giga_init_args((init_args){__VA_ARGS__});

typedef struct {
    char val[MAX_DIGITS];
    int ndigits;
} giganum_t;

typedef struct {
    char* num_str;
    bool already_reversed;
} init_args;

giganum_t* giga_init_args(init_args args);
void giga_print(giganum_t* giganum);
giganum_t* giga_add(giganum_t* a, giganum_t* b);

#endif //GIGANUM_GIGANUM_H

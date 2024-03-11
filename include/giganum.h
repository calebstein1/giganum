#ifndef GIGANUM_GIGANUM_H
#define GIGANUM_GIGANUM_H

#include <stdbool.h>

typedef struct {
    char val[256];
    int ndigits;
    bool is_negative;
} giganum_t;

giganum_t* giga_init(char* num_str);
void giga_print(giganum_t* giganum);

#endif //GIGANUM_GIGANUM_H

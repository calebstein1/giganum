#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "giganum.h"

giganum_t* giga_init(char* num_str) {
    int i = 0;
    giganum_t* new_giganum;
    char* str_reversed;

    for (; num_str[i] != '\0'; i++) {
        if (num_str[i] < 0x30 || 0x39 < num_str[i]) {
            printf("giganum string cannot contain non-digit characters\n");
            return NULL;
        }
        if (i >= MAX_DIGITS) {
            printf("number too large\n");
            return NULL;
        }
    }

    if ((new_giganum = calloc(1, sizeof(*new_giganum))) == NULL) {
        perror("calloc");
        return NULL;
    }
    new_giganum->ndigits = i;

    if ((str_reversed = calloc(new_giganum->ndigits, sizeof(char))) == NULL) {
        perror("calloc");
        return NULL;
    }

    for (; i > 0; i--) {
        str_reversed[new_giganum->ndigits - i] = num_str[i - 1];
    }

    strncpy(new_giganum->val, str_reversed, new_giganum->ndigits);
    if (memcmp(new_giganum->val, str_reversed, new_giganum->ndigits) != 0) {
        free(str_reversed);

        return NULL;
    }
    free(str_reversed);

    return new_giganum;
}

void giga_print(giganum_t *giganum) {
    char str_reversed[giganum->ndigits];
    int i;
    for (i = giganum->ndigits; i > 0; i--) {
        str_reversed[giganum->ndigits - i] = giganum->val[i - 1];
    }
    printf("%s\n", str_reversed);
}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "giganum.h"

giganum_t* giga_init(char* num_str) {
    int i = 0;
    giganum_t* new_giganum;

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
    strncpy(new_giganum->val, num_str, i);

    return new_giganum;
}

void giga_print(giganum_t *giganum) {
    printf("%s\n", giganum->val);
}
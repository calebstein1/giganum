#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "giganum.h"

giganum_t* giga_init_base(char* num_str, bool already_reversed) {
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

    if (!already_reversed) {
        char str_reversed[new_giganum->ndigits];

        for (; i > 0; i--) {
            str_reversed[new_giganum->ndigits - i] = num_str[i - 1];
        }

        strncpy(new_giganum->val, str_reversed, new_giganum->ndigits);
        if (memcmp(new_giganum->val, str_reversed, new_giganum->ndigits) != 0) {
            return NULL;
        }
    } else {
        strncpy(new_giganum->val, num_str, new_giganum->ndigits);
        if (memcmp(new_giganum->val, num_str, new_giganum->ndigits) != 0) {
            return NULL;
        }
    }

    return new_giganum;
}

giganum_t* giga_init_args(init_args args) {
    return giga_init_base(args.num_str, args.already_reversed ? args.already_reversed : false);
}

void giga_print(giganum_t *giganum) {
    char str_reversed[giganum->ndigits];
    int i;
    for (i = giganum->ndigits; i > 0; i--) {
        str_reversed[giganum->ndigits - i] = giganum->val[i - 1];
    }
    printf("%s\n", str_reversed);
}

giganum_t* giga_add(giganum_t *a, giganum_t *b) {
    int i, a_pos, b_pos, result_size = (a->ndigits > b->ndigits ? a->ndigits : b->ndigits) + 1;
    char result[result_size], interim, carry, shorter_finished;
    i = a_pos = b_pos = 0;
    carry = shorter_finished = 0x00;

    while (a->val[a_pos] != '\0' || b->val[b_pos] != '\0') {
        if (a->val[a_pos] == '\0' || b->val[b_pos] == '\0') {
            shorter_finished = 0x30;
        }
        interim = a->val[a_pos] + b->val[b_pos] + carry + shorter_finished;
        if (carry == 0x01) {
            carry = 0x00;
        }
        if (interim > 0x69) {
            interim -= 0x0A;
            carry = 0x01;
        }

        result[i] = interim - 0x30;
        i++;

        if (i == result_size - 1 && carry == 0x01) {
            result[result_size - 1] = 0x31;
            break;
        }

        if (a->val[a_pos] != '\0') {
            a_pos++;
        }
        if (b->val[b_pos] != '\0') {
            b_pos++;
        }
    }

    return giga_init(result, true)
}

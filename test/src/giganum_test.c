#include <stdio.h>
#include <stdlib.h>

#include "giganum.h"

int main() {
    giganum_t *my_giganum1 = giga_init("256");
    if (my_giganum1 == NULL) {
        printf("Something went wrong bruh\n");
        return -1;
    }
    giganum_t *my_giganum2 = giga_init("147");
    if (my_giganum2 == NULL) {
        printf("Something went wrong bruh\n");
        return -1;
    }

    giganum_t* add_result = giga_add(my_giganum1, my_giganum2);
    //giga_print(add_result);

    giganum_t* subtract_result = giga_subtract(my_giganum1, my_giganum2);
    giga_print(subtract_result);

    free(my_giganum1);
    free(my_giganum2);
    free(add_result);
    free(subtract_result);

    return 0;
}

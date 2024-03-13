#include <stdio.h>
#include <stdlib.h>

#include "giganum.h"

int main() {
    giganum_t *my_giganum1 = giga_init("1654787323298409348728723982398742309842398723457265");
    if (my_giganum1 == NULL) {
        printf("Something went wrong bruh\n");
        return -1;
    }
    giganum_t *my_giganum2 = giga_init("92346287628347628781298796875437256437428376422234259");
    if (my_giganum2 == NULL) {
        printf("Something went wrong bruh\n");
        return -1;
    }

    giganum_t* add_result = giga_add(my_giganum1, my_giganum2);
    giga_print(add_result);

    free(my_giganum1);
    free(my_giganum2);
    free(add_result);

    return 0;
}
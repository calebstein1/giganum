#include <stdio.h>
#include <stdlib.h>

#include "giganum.h"

int main() {
    giganum_t *my_giganum = giga_init("-12345678901234567890123458345349853457349587345435");
    if (my_giganum == NULL) {
        printf("Something went wrong bruh\n");
        return -1;
    }

    giga_print(my_giganum);

    free(my_giganum);

    return 0;
}
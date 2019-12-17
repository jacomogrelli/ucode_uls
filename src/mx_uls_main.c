#include "uls.h"

int main (int argc, char** argv) {
    int flag_count = mx_flag_check(argc, argv);
    printf("flag count = %d\n", flag_count);
}

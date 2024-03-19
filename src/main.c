#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "utils.h"
#include "store.h"
#include "persist.h"

int main(int argc, char const *argv[]) {
    if(argc > 1){
        if(strcmp(argv[1], "--test") == 0){
            test();
            return 0;
        }
    }
    return 0;
}
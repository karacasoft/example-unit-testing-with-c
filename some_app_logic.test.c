#include <stdio.h>

#include "some_app_logic.h"

const static int add_test_cases[4][3] = {{1, 2, 3}, {10, 15, 25}, {150, -150, 0}, {-100, -150, -250}};

int test_my_app_logic();
int test_add();

int test_my_app_logic() {
    int ret = my_app_logic();
    if(ret != 0) {
        printf("\tmy_app_logic returns a non-zero value\n");
        return 1; // error case
    }
    return 0;
}

int test_add() {
    int i;
    for(i = 0; i < 4; i++) {
        int ret = add(add_test_cases[i][0], add_test_cases[i][1]);
        if(ret != add_test_cases[i][2]) {
            printf("\t%d))) %d + %d = %d but add returns %d\n", i+1, add_test_cases[i][0], add_test_cases[i][1], add_test_cases[i][2], ret);
            return 1;
        }
    }
    return 0;
}


int main() {
    printf("Running tests for #my_app_logic\n");
    if(test_my_app_logic()) {
        printf("Tests failed for #my_app_logic\n");
        return 1; // return with error code 1
    }

    printf("Running tests for #add\n");
    if(test_add()) {
        printf("Tests failed for #add\n");
        return 2;
    }

    return 0;
}
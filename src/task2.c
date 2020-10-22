// License: CC BY-NC-SA 4.0
/*
 * task2.c
 *
 * Write a recursive line reversal function.
 *
 * Written by AlexeyFilich
 * 10 oct 2020
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Interactions.h"

char * reverse(char * str, int s, int n) {
    static char out[100];
    out[s] = str[n - 1];
    if (n > 1) reverse(str, s + 1, n - 1);
    else return out;
}

int length(char * str) {
    int len = 0;
    while (str[++len] != '\0'); // Get string length
    return len;
}

int main(int argc, char* args[]) {
    for (int i = 1; i < argc; i++) { // Reverse all strings in arguments
        char * out = reverse(args[i], 0, length(args[i]));
        printf("Reversed: ");
        for (int i = 0; i < length(args[i]); i++) printf("%c", out[i]);
        printf("\n");
    }
    while (true) {
        char str[100];
        int len = 0;
        printf("Input string: ");
        gets(str); // Read string
        char * out = reverse(str, 0, length(str));
        printf("Reversed: ");
        for (int i = 0; i < length(str); i++) printf("%c", out[i]);
        printf("\n");
        if (aQToExit()) break; // Exit prompt
    }
    printf("Done!\n");
    return 0;
}

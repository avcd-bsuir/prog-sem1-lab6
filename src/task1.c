// License: CC BY-NC-SA 4.0
/*
 * task1.c
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

void reverse(char * out, char * str, int n) {
    out[0] = str[n - 1];
    if (n > 1) reverse(out + 1, str, n - 1);
}

int length(char * str) {
    int len = 0;
    while (str[++len] != '\0'); // Get string length
    return len;
}

int main(int argc, char* args[]) {
    for (int i = 1; i < argc; i++) { // Reverse all strings in arguments
        char * out = calloc(length(args[i]), sizeof(char));
        reverse(out, args[i], length(args[i]));
        printf("Reversed: ");
        puts(out);
    }
    while (true) {
        char str[100];
        int len = 0;
        printf("Input string: ");
        gets(str); // Read string
        char * out = calloc(length(str), sizeof(char));
        reverse(out, str, length(str));
        printf("Reversed: ");
        puts(out);
        if (aQToExit()) break; // Exit prompt
    }
    printf("Done!\n");
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createTextFile() {
    FILE* file = fopen("words.txt", "w");
    if (file == NULL) {
        printf("Error: could not create file\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "in vitae turpis massa sed elementum tempus egestas sed sed risus");

    fclose(file);
}

void task() {
    FILE* file = fopen("words.txt", "rb");

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* str = malloc(sizeof(char) * (size + 1)); // allocate memory for null terminator

    fread(str, sizeof(char), size, file);

    fclose(file);

    str[size] = '\0'; // add null terminator
    file = fopen("words.txt", "wb");

    char* tok = NULL, * sav = NULL;
    tok = strtok_s(str, " ", &sav);
    while (tok != NULL) {
        int len = strlen(tok);
        fprintf(file, "%d ", len);
        tok = strtok_s(NULL, " ", &sav);
    }
    fclose(file);

    free(str); // free dynamically allocated memory
}

int main() {
    createTextFile();
    task();
    return 0;
}
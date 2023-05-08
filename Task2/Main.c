#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct sportsman {
    char name[10];
    int number;
    int score;
};

void createFile() {
    srand(time(0));
    struct sportsman arr[5];
    puts("before:");
    for (int i = 0; i < 5; ++i) {
        strcpy(arr[i].name, "test name");
        arr[i].number = i + 1;
        arr[i].score = rand() % 100 + 1;
        printf("name = %s num = %d score = %d\n", arr[i].name, arr[i].number,
            arr[i].score);
    }
    FILE* file;
    file = fopen("zav2.txt", "wb");
    fwrite(arr, sizeof(arr[0]), 5, file);
    fclose(file);
}

int main() {
    createFile();
    struct sportsman arr[5];

    FILE* file;
    file = fopen("zav2.txt", "rb");
    fread(arr, sizeof(arr[0]), 5, file);
    fclose(file);

    file = fopen("zav2.txt", "wb");
    struct sportsman temp = arr[1];
    arr[1] = arr[0];
    arr[0] = temp;
    fwrite(arr, sizeof(arr[0]), 5, file);
    fclose(file);
    puts("after:");
    for (int i = 0; i < 5; ++i) {
        printf("name = %s num = %d score = %d\n", arr[i].name, arr[i].number,
            arr[i].score);
    }
    return 0;
}

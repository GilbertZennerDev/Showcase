#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_SIZE 1024 * 1024 // 1 MB

void generate_random_file(const char *filename, size_t size) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < size; ++i) {
        char random_char = ' ' + (rand() % 95); // Generate a random printable character
        fputc(random_char, file);
    }

    fclose(file);
}

int main() {
    generate_random_file("filledfile.txt", FILE_SIZE);
    printf("Random file 'filledfile.txt' of size %zu bytes generated.\n", FILE_SIZE);

    return EXIT_SUCCESS;
}
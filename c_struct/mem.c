#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, World!";
    char destination[20];

    // Using memcpy to copy a string
    memcpy(destination, source, sizeof(source));
    printf("Copied string: %s\n", destination);

    // Using memmove to handle overlapping memory regions
    char text[] = "abcdef";
    memmove(text + 2, text, 6);
    printf("Overlapping memmove: %s\n", text);

    // Using memcmp to compare two strings
    char str1[] = "apple";
    char str2[] = "banana";
    int result = memcmp(str1, str2, 5);
    if (result < 0) {
        printf("str1 is less than str2\n");
    } else if (result > 0) {
        printf("str1 is greater than str2\n");
    } else {
        printf("str1 is equal to str2\n");
    }

    // Using memset to set memory to a value
    int numbers[5];
    memset(numbers, 0, sizeof(numbers));
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Using memchr to search for a character
    char text2[] = "Searching";
    char *found = memchr(text2, 'c', sizeof(text2));
    if (found != NULL) {
        printf("Found 'c' at position: %ld\n", found - text2);
    } else {
        printf("'c' not found\n");
    }

    return 0;
}

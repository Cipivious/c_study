#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "chtbl.h"

/* Count the number of letters in a string */
int count_letters(const char *str) {
    int count = 0;
    while (*str != '\0') {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

/* Hash function that uses the count of letters */
int hash_function(const void *key) {
    const char *str = (const char *)key;
    return count_letters(str);
}

/* Simple matching function that compares two strings */
int match_function(const void *key1, const void *key2)
{
    const char *str1 = (const char *)key1;
    const char *str2 = (const char *)key2;
    return strcmp(str1, str2) == 0;
}

/* Function to print the contents of the hash table */
void printHashTable(const Chtbl *htbl)
{
    for (int i = 0; i < htbl->buckets; ++i)
    {
        printf("Bucket %d: ", i);
        ListElmt *element = list_head(&htbl->table[i]);
        while (element != NULL)
        {
            printf("%s ", (char *)list_data(element));
            element = list_next(element);
        }
        printf("\n");
    }
}

int main()
{
    // Test hash table
    Chtbl htbl;
    chtbl_init(&htbl, 10, hash_function, match_function, free);

    char *values[] = {"apple", "banana", "cherry", "date", "elderberry"};
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
    {
        chtbl_insert(&htbl, values[i]);
    }

    printf("Hash Table contents:\n");
    printHashTable(&htbl);

    // Remove a value from the hash table
    char *value_to_remove = "banana";
    if (chtbl_remove(&htbl, (void **)&value_to_remove) == 0)
    {
        printf("\nRemoved %s from the hash table.\n", value_to_remove);
    }
    else
    {
        printf("\n%s not found in the hash table.\n", value_to_remove);
    }

    printf("\nHash Table contents after removal:\n");
    printHashTable(&htbl);

    // Clean up
    chtbl_destroy(&htbl);

    return 0;
}

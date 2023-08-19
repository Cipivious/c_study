#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "set.h"

int match(const void *ptr1, const void *ptr2) {
    const int *int_ptr1 = ptr1;
    const int *int_ptr2 = ptr2;
    if (int_ptr1 == NULL || int_ptr2 == NULL)
      {
        return 0;
      }
    return *int_ptr1 == *int_ptr2;
}

int main() {
    Set set1;
    Set set2;
    Set seti;
    Set setd;
    Set setu;
    ListElmt *setelmt;
    int a[10];
    int b[10];
    //void *data;
    int i;
    int j;

    for (i = 0; i < 10; ++i)
        a[i] = i;
    for (j = 0; j < 10; ++j)
        b[j] = j + 5;

    set_init(&set1, match, free);
    set_init(&set2, match, free);

    for (i = 0; i < 10; ++i) {
        set_insert(&set1, (const void *)&a[i]);
    }
    for (i = 0; i < 10; ++i) {
        set_insert(&set2, (const void *)&b[i]);
    }
    printf("set1 and set2's union : ");
    set_intersection(&setd, &set1, &set2);
    setelmt = setd.head;
    for (int i = 0; i < 15 && setelmt != NULL; ++i) {
        printf("%d ", *(int *)(setelmt->data));
        setelmt = setelmt->next;
    }
    printf("\n");
    i = set_is_subset(&set1, &setd);
    printf("set_is_subset(&set1, &setd) = %d\n", i);
    i = set_is_subset(&setd, &set1);
    printf("set_is_subset(&setd, &set1) = %d\n", i);
    i = set_is_equal(&set1, &set1);
    printf("set_is_equal(&set1, &set1) = %d\n", i);

    /*    setelmt = set.head;
    printf("第一次遍历的结果：");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", *(int *)(setelmt->data));
        setelmt = setelmt->next;
    }
    printf("\n");

    set_remove(&set, (void **)&a[0]);
    printf("第二次遍历的结果：");
    setelmt = set.head;
    for (int i = 0; i < 9; ++i) {
        printf("%d ", *(int *)(setelmt->data));
        setelmt = setelmt->next;
    }
    printf("\n");



    set_destroy(&set);
    printf("链表的长度：%d\n", set.size);*/

    return 0;
}

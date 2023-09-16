#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

// 定义一个用于销毁整型数据的测试函数
void destroy_int_data(void *data) {
    free(data);
}

int main() {
    Bitree tree;
    bitree_init(&tree, destroy_int_data);

    // 插入节点和其他操作
    int *data1 = (int *)malloc(sizeof(int));
    *data1 = 10;
    bitree_ins_left(&tree, NULL, data1);

    int *data2 = (int *)malloc(sizeof(int));
    *data2 = 20;
    bitree_ins_left(&tree, bitree_root(&tree), data2);

    int *data3 = (int *)malloc(sizeof(int));
    *data3 = 30;
    bitree_ins_right(&tree, bitree_root(&tree), data3);

    // 打印树的大小
    printf("Tree size: %d\n", bitree_size(&tree));

    // 打印树的节点数据
    printf("Root data: %d\n", *(int *)bitree_data(bitree_root(&tree)));
    printf("Left child data: %d\n", *(int *)bitree_data(bitree_left(bitree_root(&tree))));
    printf("Right child data: %d\n", *(int *)bitree_data(bitree_right(bitree_root(&tree))));

    // 合并两棵树
    Bitree merged_tree;
    bitree_init(&merged_tree, destroy_int_data);
    int *data4 = (int *)malloc(sizeof(int));
    *data4 = 40;
    bitree_merge(&merged_tree, &tree, &tree, data4);
    printf("Merged tree size: %d\n", bitree_size(&merged_tree));

    // 删除左子树
    //BitreeNode *left_child = bitree_left(bitree_root(&merged_tree));
    bitree_rem_left(&merged_tree, bitree_right(bitree_root(&merged_tree)));

    // 打印删除后的树状态
    printf("Tree size after removing left child: %d\n", bitree_size(&merged_tree));
    printf("Root data: %d\n", *(int *)bitree_data(bitree_root(&merged_tree)));
    //printf("Right child data: %d\n", *(int *)bitree_data(bitree_right(bitree_root(&merged_tree))));



    // 销毁树
    //bitree_destroy(&merged_tree);

    return 0;
}

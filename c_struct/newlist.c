#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void addNode(Node *head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}

void clearList(Node *head) {
    Node *p = head;
    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
}

int main(){
  Node *head = (Node*)malloc(sizeof(Node));
  head->data = 10;
  head->next = NULL;
  printf("%d\n", head->data);
  addNode(head, 20);
  Node *p;
  p = head->next;
  printf("%d\n", p->data);
  clearList(head);
  printf("%d\n", p->data);
  return 1;
}

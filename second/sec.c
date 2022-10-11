// #include <assert.h>
// #include <limits.h>
// #include <math.h>
// #include <stdbool.h>
// #include <stddef.h>
// #include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

char* readline();

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    node->data = node_data;
    node->next = NULL;
    return node;
}

void insert_node_into_singly_linked_list(int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);
    SinglyLinkedList* llist = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    llist->head = NULL;
    llist->tail = NULL;
    if (llist->head==NULL) {
        llist->head = node;
    } else {
        llist->tail->next = node;
    }

    llist->tail = node;
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}
void printLinkedList() {
    SinglyLinkedList* llist = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    SinglyLinkedListNode* p=llist->head;
    printf("head: %d\n",p->data);
    while (p!=NULL){
        printf("%d\n",(p->data));
        p=p->next;
    }
   printf("tail: %d\n",p->data);
}

int main(){
    insert_node_into_singly_linked_list(10);
    insert_node_into_singly_linked_list(20);
    insert_node_into_singly_linked_list(20);
    insert_node_into_singly_linked_list(20);
    //printLinkedList();
    return 0;
}


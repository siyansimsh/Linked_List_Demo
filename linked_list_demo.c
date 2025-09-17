/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// linked_list_demo.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int x){
    Node *n = (Node*)malloc(sizeof(Node));
    if(!n){ perror("malloc"); exit(1); }
    n->data = x;
    n->next = NULL;
    return n;
}

void insert_head(Node **head, int x){
    Node *n = create_node(x);
    n->next = *head;
    *head = n;
}

void insert_tail(Node **head, int x){
    Node *n = create_node(x);
    if(*head == NULL){ *head = n; return; }
    Node *p = *head;
    while(p->next) p = p->next;
    p->next = n;
}

Node* search(Node *head, int target){
    for(Node *p = head; p; p = p->next)
        if(p->data == target) return p;
    return NULL;
}

// 刪除「第一個」值等於 target 的節點；成功回傳 true，否則 false
bool delete_value(Node **head, int target){
    Node *prev = NULL, *cur = *head;
    while(cur){
        if(cur->data == target){
            if(prev) prev->next = cur->next;
            else     *head = cur->next; // 刪 head
            free(cur);
            return true;
        }
        prev = cur;
        cur  = cur->next;
    }
    return false;
}

void traverse_print(Node *head){
    for(Node *p = head; p; p = p->next) printf("%d ", p->data);
    puts("");
}

void free_list(Node **head){
    Node *p = *head, *nxt;
    while(p){ nxt = p->next; free(p); p = nxt; }
    *head = NULL;
}

int main(void){
    Node *head = NULL;

    // 建立串列：尾插 3,5,11,19
    insert_tail(&head, 3);
    insert_tail(&head, 5);
    insert_tail(&head, 11);
    insert_tail(&head, 19);
    printf("初始串列: "); traverse_print(head);

    // 頭插 2
    insert_head(&head, 2);
    printf("頭插 2 之後: "); traverse_print(head);

    // 搜尋
    int q1 = 11, q2 = 42;
    printf("search %d -> %s\n", q1, search(head, q1) ? "Found" : "Not Found");
    printf("search %d -> %s\n", q2, search(head, q2) ? "Found" : "Not Found");

    // 刪值：刪 3（中間）、刪 2（頭）、刪 19（尾）
    printf("delete 3 -> %s\n", delete_value(&head, 3) ? "OK" : "MISS");
    traverse_print(head);

    printf("delete 2 -> %s\n", delete_value(&head, 2) ? "OK" : "MISS");
    traverse_print(head);

    printf("delete 19 -> %s\n", delete_value(&head, 19) ? "OK" : "MISS");
    traverse_print(head);

    free_list(&head);
    return 0;
}

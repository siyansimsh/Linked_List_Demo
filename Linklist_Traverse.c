#include <stdio.h>
#include <stdlib.h>

// 節點結構定義 (一個節點應該包含一個值與一個指向下一個節點的指標)
typedef struct Node {
    int val;
    struct Node *next;
} Node;

// 函式：走訪鏈結串列，印出每個節點的值並回傳節點總數 
int traverse(Node *head) {
    int cnt = 0;
    for (Node *p = head; p != NULL; p = p->next) {
        printf("%d ", p->val);
        cnt++;
    }
    printf("\n");
    return cnt;
}

// 函式：釋放整個鏈結串列的記憶體
void free_list(Node *head) {
    Node *tmp;
    while (head != NULL) {                // NULL 代表鏈結串列的結尾
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// 主程式進入點
int main() {
    // 建立三個節點的記憶體空間
    Node *head   = (Node*)malloc(sizeof(Node));
    Node *second = (Node*)malloc(sizeof(Node));
    Node *third  = (Node*)malloc(sizeof(Node));

    // 檢查記憶體是否成功分配
    if (head == NULL || second == NULL || third == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // 回傳錯誤碼
    }

    // 設定節點的值，並將它們串接起來
    // head -> second -> third -> NULL
    head->val = 10;
    head->next = second;

    second->val = 20;
    second->next = third;

    third->val = 30;
    third->next = NULL; // 標記為鏈結串列的結尾

    // 呼叫 traverse 函式來印出串列並計數
    printf("鏈結串列的內容為: ");
    int node_count = traverse(head);

    // 印出節點總數
    printf("節點總數為: %d\n", node_count);
    
    // 釋放所有節點佔用的記憶體，避免 memory leak
    free_list(head);

    return 0; // 程式結束
}
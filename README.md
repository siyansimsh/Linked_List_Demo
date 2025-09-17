# C Singly Linked List Implementation

這是一個使用 C 語言實作的基礎單向鏈結串列 (Singly Linked List) 範例。專案包含了一個 `main` 函式，用於展示並測試鏈結串列的各項核心功能，包括節點的建立、插入、刪除、搜尋與記憶體釋放。

此程式碼旨在作為學習資料結構與指標操作的教學範例，特別強調了 C 語言中「指標的指標 (pointer to pointer)」在修改串列結構時的應用。

## Features

  - **節點建立**: 動態配置記憶體以建立新節點。
  - **頭部插入**: 在鏈結串列的開頭新增一個節點 (O(1) 時間複雜度)。
  - **尾部插入**: 在鏈結串列的末端新增一個節點 (O(n) 時間複雜度)。
  - **節點搜尋**: 根據給定的值搜尋串列中的節點。
  - **節點刪除**: 刪除串列中第一個符合指定值的節點。
  - **串列走訪**: 遍歷並印出所有節點的資料。
  - **記憶體管理**: 提供函式以安全地釋放整個串列佔用的記憶體，避免洩漏。

## 如何編譯與執行 (Compilation & Execution)

此專案僅包含一個原始碼檔案 `linked_list_demo.c`。您可以使用任何標準的 C 編譯器（例如 GCC）來進行編譯。

1.  **編譯程式碼**

    由於程式碼中使用了 C99 標準的 `<stdbool.h>`，建議在編譯時指定標準。打開您的終端機並執行以下指令：

    ```bash
    gcc linked_list_demo.c -o linked_list_demo -std=c99
    ```

      - `gcc`: C 編譯器指令。
      - `linked_list_demo.c`: 您的原始碼檔案。
      - `-o linked_list_demo`: 指定輸出的執行檔名稱。
      - `-std=c99`: 指定使用 C99 標準來編譯。

2.  **執行程式**

    ```bash
    ./linked_list_demo
    ```

### 預期輸出 (Expected Output)

執行後，您應該會看到以下輸出，展示了對鏈結串列的一系列操作結果：

```
初始串列: 3 5 11 19 
頭插 2 之後: 2 3 5 11 19 
search 11 -> Found
search 42 -> Not Found
delete 3 -> OK
2 5 11 19 
delete 2 -> OK
5 11 19 
delete 19 -> OK
5 11 
```

## API 文件 (API Documentation)

#### `Node* create_node(int x)`

建立一個新的節點，並將其資料初始化為 `x`。成功時回傳指向新節點的指標，若記憶體分配失敗則終止程式。

#### `void insert_head(Node **head, int x)`

在串列的頭部插入一個值為 `x` 的新節點。此函式會修改 `head` 指標。

#### `void insert_tail(Node **head, int x)`

在串列的尾部插入一個值為 `x` 的新節點。若串列為空，新節點將成為頭節點。

#### `Node* search(Node *head, int target)`

在串列中搜尋值為 `target` 的節點。若找到，回傳指向該節點的指標；否則回傳 `NULL`。

#### `bool delete_value(Node **head, int target)`

刪除串列中第一個值等於 `target` 的節點。若刪除成功，回傳 `true`；若找不到該節點，回傳 `false`。

#### `void traverse_print(Node *head)`

走訪整個串列，並將每個節點的 `data` 印出至螢幕。

#### `void free_list(Node **head)`

釋放整個串列所有節點佔用的記憶體，並將原始的 `head` 指標設為 `NULL`，以避免懸置指標 (Dangling Pointer) 的問題。

-----

## 核心觀念：為何使用 `Node **head`

在此專案中，凡是**可能會修改到串列頭部 `head` 指標**的函式（如插入、刪除、清空），其參數皆為 `Node **head`（指標的指標）。

  - **C 語言的傳值呼叫 (Pass-by-Value)**: 當你將一個指標 `Node *ptr` 傳遞給函式時，函式接收到的是該指標的「副本」。在函式內部修改這個副本（例如 `ptr = new_node;`）並不會影響到函式外部原始的指標。

  - **解決方案**: 為了讓函式能修改原始的 `head` 指標，我們必須傳遞 `head` 指標**本身的記憶體位址**，也就是 `&head`。這個位址的型別就是 `Node **`。在函式內部，我們可以使用解參考運算子 `*` 來存取並修改原始的 `head` 指標，例如 `*head = n;`。

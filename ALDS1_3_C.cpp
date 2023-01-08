#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *prev, *next;
};

Node *nil;

void init() {
    nil = (Node *)malloc(sizeof(Node));
    nil->prev = nil;
    nil->next = nil;
}

void printList() {
    Node *cur = nil->next;
    if(cur == nil) return;
    while(1){
        printf("%d", cur->key);
        if(cur->next != nil){
            printf(" ");
            cur = cur->next;
        } else {
            break;
        }
    }
    printf("\n");
}

void insert(int key){
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    x->prev = nil;
    nil->next = x;
}

Node* listSearch(int key){
    Node *cur = nil->next;
    while(cur != nil && cur->key != key){
        cur = cur->next;
    }
    return cur;
}

void deleteNode(Node *t) {
    if(t == nil) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void deleteFirst() {
    deleteNode(nil->next);
}

void deleteLast() {
    deleteNode(nil->prev);
}

int main() {
    int n, key;
    char com[20];

    scanf("%d", &n);
    init();
    for(int i = 0; i < n; i++){
        scanf("%s%d", com, &key);
        if(com[0] == 'i'){
            insert(key);
        } else if(com[0] == 'd'){
            if(strlen(com) > 6){
                if(com[6] == 'F'){
                    deleteFirst();
                } else if(com[6] == 'L'){
                    deleteLast();
                }
            } else {
                deleteNode(listSearch(key));
            }
        }
    }
    printList();
    return 0;
}
    
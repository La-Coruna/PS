/* 
[Reverse a linked list]
- date: 24.08.21
- tag: easy, Linked list, Pointers
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'reverse' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

// Just to write the necessary parts.
typedef struct {
    int data;
    SinglyLinkedListNode* next;
} SinglyLinkedListNode;

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* prevNode = nullptr;
    SinglyLinkedListNode* curNode = llist;
    while(curNode != nullptr){
        SinglyLinkedListNode* next_tmp = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = next_tmp;
    }
    return prevNode;
}
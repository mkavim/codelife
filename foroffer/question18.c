// 删除链表的节点
// 给定单链表的头指针和一个节点指针，在O(1)时间内删除该链表节点
// 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
// 返回删除后的链表的头节点。

#include <stdio.h>
#include <stdlib.h>
#include "../algorthms/linklist/linklist.h"


/**
 * T(n) = ((n-1)*O(1) * O(n))/n = O(1)
 */
void deleteNode(struct  LinkNode **pHead, struct  LinkNode *pDeleteNode){
    if(pHead == NULL || pDeleteNode == NULL){
        return ;
    }

    LinkList *p = *pHead;
    // 1、pDeleteNode不是尾节点
    if(pDeleteNode->next != NULL){
        LinkList *pNext = pDeleteNode->next;
        pDeleteNode->val = pNext->val;
        pDeleteNode->next = pNext->next;
        free(pNext);
        pNext = NULL;
    }
    else if(*pHead == pDeleteNode){
        // 2、链表只有一个节点，且为头节点，尾节点
        free(pDeleteNode);
        pHead = NULL;
        pDeleteNode = NULL;
    }else{
        // 尾结点
        while(p->next != pDeleteNode){
            p = p->next;
        }
        p->next = NULL;
        free(pDeleteNode);
        pDeleteNode = NULL;
    }
}


/**
 * 删除值重复的节点
 * 由于头结点也有可能被删除，因此传入为pHead的指针的指针，这样可以直接修改头节点
 */ 
void delelteDuplication(LinkList **pHead){
    if(pHead == NULL || *pHead == NULL){
        return ;
    }

    LinkList *pPreNode = NULL;
    LinkList *pNode = *pHead;

    while(pNode != NULL){
        LinkList *pNext = pNode->next;
        int needDelete = 0;

        if(pNext != NULL && pNext->val == pNode->val){
            needDelete = 1;
        }
        // 不需要删除
        if(!needDelete){
            pPreNode = pNode;
            pNode = pNode->next;
        }else{
            // 循环删除值重复的节点
            int value = pNode->val;
            LinkList *pToBeDel = pNode;
            while(pToBeDel != NULL && pToBeDel->val == value){
                pNext = pToBeDel->next;
                free(pToBeDel);
                pToBeDel = NULL;
                pToBeDel = pNext;
            }


            if(pPreNode == NULL){
                *pHead = pNext;
            }else{
                pPreNode->next = pNext;
            }
            pNode = pNext;
        }
    }

}

LinkList* deleteNode(LinkList* head, int val){
    if(head == NULL) return NULL;
    LinkList* p = head;

    // 头结点
    if(head->val == val){
        return head->next;
    }
    // 找到该节点
    while(p->next != NULL && p->next->val != val ){
        p = p->next;
    }
    // 找到该节点
    if(p->next != NULL){
        p->next = p->next->next;
    }
    return head;
}

void test_deleteNode(){
    const int len = 10;
    LinkList *pHead = randomCreate(len);
    struct  LinkNode *pDeleteNode = pHead;
    int i = len >> 1;
    while(i > 0){
        pDeleteNode = pDeleteNode->next;
        --i;
    }
    printLinkList(pHead);
    printf("pDeleteNode = %d", pDeleteNode->val);
    deleteNode(&pHead, pDeleteNode);
    printLinkList(pHead);
}


void test_delelteDuplication(){
    const int len = 10;
    int arr[len] = {1,1,2,3,4,4,5,5,7,9};
    LinkList *pHead = createLinkList(arr, len);
    
    printLinkList(pHead);
    delelteDuplication(&pHead);
    printLinkList(pHead);
}

int main(void){
    // test_deleteNode();

    test_delelteDuplication();

    return 0;
}
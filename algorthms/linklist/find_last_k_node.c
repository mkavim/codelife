// 求单链表倒数第K个节点

#include <stdio.h>
#include "linklist.h"


/**
 * 两个指针，一个先走K步，然后再同步走
 * 注意：空链表或链表长度小于K
 */
LinkList *findLastKNode(LinkList *head, const int k){
    if(head == NULL || k <= 0){
        return NULL;
    }
    LinkList *p1 = head;
    LinkList *p2 = head;

    // 向前走k-1步
    int step = k - 1;
    while(step > 0){
        if(p1->next == NULL){
            return NULL;
        }
        p1 = p1->next;
        step--;
    }

    while(p1->next!=NULL){
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

void testFindLastKNode(){
    // 创建一个有环的链表
    LinkList *head = randomCreate(10);
    // LinkList *head = NULL;
    const int k = 4;
    // const int k = 11;

    LinkList *res = findLastKNode(head, k);

    if(res != NULL){
        printf("last k = %d\n", res->val);
    }else{
        printf("error\n");
    }

    freeLinkList(head);
}


int main(void){
    testFindLastKNode();
    return 0;
}
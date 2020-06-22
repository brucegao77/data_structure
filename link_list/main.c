#include <stdio.h>
#include "link_list.h"

void PrintList(LinkList L);

int main()
{
    ElemType e;
    LinkList L = NULL, Lb = NULL, Lc = NULL;
    CreateList(&L, 100);
    CreateList(&Lb, 100);
    PrintList(L);
    PrintList(Lb);
    //GetElem(L, 59, &e);
    //printf("e: %d\n", e);
    //Insert(&L, 33, 777);
    //printf("New L: ");
    //PrintList(L);
    //Delete(&L, 33, &e);
    //printf("e: %d\n", e);
    //printf("New L: ");
    //PrintList(L);
    Merge(&L, &Lb, &Lc);
    PrintList(Lc);
    return 0;
}

void PrintList(LinkList L)
{
    LNode *p = L->next;
    while (p) {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}
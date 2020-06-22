#include <stdlib.h>
#include "link_list.h"

void CreateList(LinkList *L, int n)
{
    int i, j = n;
    *L = (LinkList)malloc(sizeof(LNode));
    if (!*L) {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    for (i = 0; i < n; i++) {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        if (!p) {
            exit(OVERFLOW);
        }
        p->data = j--;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

Status GetElem(LinkList L, int i, ElemType *e)
{
    int j = 0;
    LNode *p = L;
    while (p && j < i) {
       p = p->next;
       j++;
    }
    if (!p || j > i) {
       return ERROR;
    }
    *e = p->data;
    return OK;
}

Status Insert(LinkList *L, int i, ElemType e)
{
    int j = 0;
    LNode *q, *p = *L;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i) {
        return ERROR;
    }
    q = (LinkList)malloc(sizeof(LNode));
    if (!q) {
        exit(OVERFLOW);
    }
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}

Status Delete(LinkList *L, int i, ElemType *e)
{
   int j = 0;
   LNode *temp, *p = *L;
   while (p && j < i - 1) {
       p = p->next;
       j++;
   }
   if (!p || j > i) {
       return ERROR;
   }
   temp = p->next;
   *e = temp->data;
   p->next = temp->next;
   free(temp);
   return OK;
}

void Merge(LinkList *La, LinkList *Lb, LinkList *Lc)
{
    LNode *pa = (*La)->next, *pb = (*Lb)->next, *pc = *La;
    *Lc = pc;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pc->next;
            pa = pa->next;
        }
        else {
            pc->next = pb;
            pc = pc->next;
            pb = pb->next;
        }
    }
    if (!pa) {
        pc->next = pb;
    }
    else {
        pc->next = pa;
    }
    free(*Lb);
}
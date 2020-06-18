#include <stdio.h>
#include "sqlist.h"

/* function:  print each elem */
void PrintList(SqList *L);
/* function:  generate the list */
void GenerateList(SqList *L);
void GenerateAnotherList(SqList *L);

int main()
{
    ElemType e;
    int i;
    SqList L, Lb, Lc;
    printf("Generating a new list...\n");
    Init(&L);
    Init(&Lb);
    GenerateList(&L);
    PrintList(&L);
    GenerateAnotherList(&Lb);
    PrintList(&Lb);
    //printf("Before insert\n");
    //PrintList(&L);
    ///* Insert */
    //Insert(&L, 100, 999);
    //printf("After insert\n");
    //PrintList(&L);
    ///* Delete */
    //Delete(&L, 32, &e);
    //printf("After delete\n");
    //printf("Deleted elem: %d\n", e);
    //PrintList(&L);
    ///* Locate Elem */
    //i = LocateElem(L, 56, &compare);
    //printf("Located position: %d\n", i);
    /* Merge two lists */
    Merge(L, Lb, &Lc);
    PrintList(&Lc);
    return 0;
}

void PrintList(SqList *L)
{
    printf("elem: %p\nlength: %d\nlistsize: %d\n", L->elem, L->length, L->listsize);
    int i;
    for (i = 0; i < L->length; i++) {
        printf("%4d", *(L->elem + i));
    }
    printf("\n");
}

void GenerateList(SqList *L)
{
    int i, j = 1;
    for (i = 0; i < L->listsize; i++) {
        *(L->elem + i) = j * 2;
        L->length++;
        j++;
    }
}

void GenerateAnotherList(SqList *L)
{
    int i, j = 1;
    for (i = 0; i < L->listsize; i++) {
        *(L->elem + i) = j * 3;
        L->length++;
        j++;
    }
}

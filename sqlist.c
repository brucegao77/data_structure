/* function: Implemention of Linear List
 * author:   Bruce
 * date:     2020-06-17 */
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define TRUE           1
#define FALSE          0
#define OK             1
#define ERROR          0
#define INFEASIBLE     -1
#define OVERFLOW       -2

typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType *elem;
    int      length;
    int      listsize;
}SqList;

/* result:    create an empty linear list L */
Status Init(SqList *L);
/* condition: list L exists, 1 <= i <= length + 1
 * result:    insert a new element e before i, length + 1 */
Status Insert(SqList *L, int i, ElemType e);
/* condition: list L exists, 1 <= i <= length
 * result:    delete element i, return data by e, length - 1 */
Status Delete(SqList *L, int i, ElemType *e);
/* function:  element determination */
Status compare(ElemType, ElemType);
/* condition: list L exists
 * result:    return the first position that satisfing compare() with e,
 *            return 0 if not exists */
int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));
/* condition: lists La, Lb are in none descending order
 * result:    merge La, Lb as Lc, Lc is in descending order */
void Merge(SqList La, SqList Lb, SqList *LC);
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

Status Init(SqList *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    /* failed allocate memory */
    if (!L->elem)
    {
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

Status Insert(SqList *L, int i, ElemType e)
{
    /* i is illegal */
   if (i < 0 || i > L->length) {
       return ERROR;
   }
   /* if don't have enough space to insert */
   if (L->length >= L->listsize) {
       ElemType *newbase = (ElemType *)realloc(L->elem,
               (LIST_INIT_SIZE + LISTINCREMENT) * sizeof(ElemType));
       if (!newbase) {
           exit(OVERFLOW);
       }
       L->elem = newbase;
       L->listsize += LISTINCREMENT;
   }
   ElemType *q = L->elem + i - 1;  /* q is the pointer of new elem */
   ElemType *p = L->elem + L->length;  /* q is the pointer of last elem */
   /* move each elem after q to the right */
   for (; p >= q; --p) {
      *(p + 1) = *p;
   }
   *q = e;
   ++L->length;
   return OK;
}

Status Delete(SqList *L, int i, ElemType *e)
{
    /* i is illegal */
    if (i < 0 || i > L->length) {
        return ERROR;
    }
    ElemType *q = L->elem + L->length;  /* q point to the last elem */
    ElemType *p = L->elem + i;  /* p point to the i */
    *e = *p;
    /* move each elem from p to the left */
    for (; p < q; ++p) {
        *p = *(p + 1);
    }
    --L->length;
    return OK;
}

int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    int i = 0;
    ElemType *p = L.elem;
    /* compare each elem with e from the first */
    while (i < L.length && !(*compare)(*p++, e)) {
        i++;
    }
    /* return if elem is found */
    if (i < L.length) {
        return i;
    }
    /* return 0 if not found */
    else {
        return 0;
    }
}

Status compare(ElemType a, ElemType b)
{
    if (a == b) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void Merge(SqList La, SqList Lb, SqList *Lc)
{
    ElemType *pa, *pb, *pc, *pa_last, *pb_last;
    pa = La.elem;
    pb = Lb.elem;
    pa_last = pa + La.length;
    pb_last = pb + Lb.length;
    /* init Lc */
    Lc->length = Lc->listsize = La.length + Lb.length;
    Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType));
    if (!Lc->elem) {
        exit(OVERFLOW);
    }
    pc = Lc->elem;
    /* merge */
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) {
            *pc++ = *pa++;
        }
        else {
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_last) {
        *pc++ = *pa++;
    }
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
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

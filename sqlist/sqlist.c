#include "sqlist.h"

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

#include "static_link_list.h"

void InitSpace(SLinkList space)
{
    int i;
    for (i = 0; i < MAXSIZE - 1; i++) {
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0;
}

int MallocSL(SLinkList space)
{
    int i;
    i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}

void FreeSL(SLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

void CreateListA(SLinkList space, int *S, int n)
{
    int i, j, k, r;
    j = 200;
    r = *S = MallocSL(space);
    space[r].cur = 0;
    for (i = 0; i < n; i++) {
        k = MallocSL(space);
        space[k].cur = space[r].cur;
        space[k].data = j;
        space[r].cur = k;
        j -= 2;
    }
}

void CreateListB(SLinkList space, int *S, int n)
{
    int i, j, k, r;
    j = 300;
    r = *S = MallocSL(space);
    space[r].cur = 0;
    for (i = 0; i < n; i++) {
        k = MallocSL(space);
        space[k].cur = space[r].cur;
        space[k].data = j;
        space[r].cur = k;
        j -= 3;
    }
}

int LocateElem(SLinkList space, int S, ElemType e)
{
    int k = 1;
    int i = space[S].cur;
    while (i && space[i].data != e) {
        i = space[i].cur;
        k++;
    }
    return k;
}

void Difference(SLinkList space, int Sa, int Sb, int *Sc)
{
    int ia, ib, ic;
    int temp;
    ib = space[Sb].cur;
    ic = *Sc = Sa;
    while (ib) {
        ia = space[Sa].cur;
        while (ia && space[ia].data != space[ib].data) {
            ia = space[ia].cur;
        }
        if (space[ia].data == space[ib].data) {
            temp = ib;
            ib = space[ib].cur;
            FreeSL(space, temp);
        }
        else {
            temp = space[ib].cur;
            space[ib].cur = space[ic].cur;
            space[ic].cur = ib;
            ib = temp;
        }
    }
}
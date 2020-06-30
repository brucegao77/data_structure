#include <stdio.h>
#include "static_link_list.h"

void PrintList(SLinkList space, int S);

int main()
{
    SLinkList space;
    int Sa, Sb, Sc, i;
    InitSpace(space);
    CreateListA(space, &Sa, 100);
    CreateListB(space, &Sb, 100);
    printf("Sa: ");
    PrintList(space, Sa);
    printf("Sb: ");
    PrintList(space, Sb);
    i = LocateElem(space, Sb, 33);
    printf("Position of e: %d\n", i);
    Difference(space, Sa, Sb, &Sc);
    PrintList(space, Sc);
    return 0;
}

void PrintList(SLinkList space, int S)
{
    int i = space[S].cur;
    int count = 0;
    while (i) {
        printf("%4d", space[i].data);
        i = space[i].cur;
        count ++;
    }
    printf("  total: %d\n", count);
}
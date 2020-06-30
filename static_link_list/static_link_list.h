/* function: Implemention of Static Link List
 * author:   Bruce
 * date:     2020-06-23 */
#define MAXSIZE 1000

typedef int ElemType;
typedef struct {
    ElemType data;
    int      cur;
}component, SLinkList[MAXSIZE];

void InitSpace(SLinkList space);
int MallocSL(SLinkList space);
void FreeSL(SLinkList space, int k);
void CreateListA(SLinkList space, int *S, int n);
void CreateListB(SLinkList space, int *S, int n);
int LocateElem(SLinkList space, int S, ElemType e);
void Difference(SLinkList space, int Sa, int Sb, int *Sc);
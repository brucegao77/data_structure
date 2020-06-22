/* function: Implemention of Link List
 * author:   Bruce
 * date:     2020-06-18 */
#define TRUE           1
#define FALSE          0
#define OK             1
#define ERROR          0
#define INFEASIBLE     -1
#define OVERFLOW       -2

typedef int Status;
typedef int ElemType ;
typedef struct LNode {
    ElemType        data;
    struct LNode    *next;
}LNode, *LinkList;

/* create a Link List in reverse order */
void CreateList(LinkList *L, int n);
/* get an elem of the gaven position */
Status GetElem(LinkList L, int i, ElemType *e);
/* Insert an elem */
Status Insert(LinkList *L, int i, ElemType e);
/* Delete an elem */
Status Delete(LinkList *L, int i, ElemType *e);
/* Merge two lists */
void Merge(LinkList *La, LinkList *Lb, LinkList *Lc);
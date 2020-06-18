/* function: Implemention of Linear List
 * author:   Bruce
 * date:     2020-06-17 */
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

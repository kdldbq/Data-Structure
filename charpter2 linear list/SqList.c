#include <stdio.h>
#include <stdlib.h>

typedef struct ElementType
{
    int value;
} ElemType;

# define MaxSize 50
typedef struct SeqList{
    ElemType Data[MaxSize];
    int Length;
}SqList;

void InitList(SqList *L) {
    L->Length = 0;
    return;
}

int main() {
    
    return 0;
}


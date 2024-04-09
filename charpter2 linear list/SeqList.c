#include <stdio.h>

typedef struct ElementType
{
    int value;
} ElemType;

# define InitSize 100
typedef struct SeqList{
    ElemType *Data;
    int MaxLength,Length;
}SeqList;

void InitList(SeqList *L) {
    L->Data=(ElemType*)malloc(sizeof(ElemType)*InitSize);
    return;
}

int main() {

    return 0;
}
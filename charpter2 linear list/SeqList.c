#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ElementType
{
    int value;
} ElemType;

#define MaxSize 100
#define InitSize 100

typedef struct SeqList
{
    ElemType *Data;
    int MaxLength, Length;
} SeqList;

void InitList(SeqList *L)
{
    L->Data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    L->Length = 0;
    L->MaxLength = MaxSize;
    return;
}

bool ListInsert(SeqList *L, int i, ElemType E)
{
    if (i < 1 || i > L->Length + 1 || L->Length >= MaxSize)
    {
        return false;
    }
    for (int j = L->Length; j >= i; j--)
    {
        L->Data[j] = L->Data[j - 1];
    }
    L->Data[i - 1] = E;
    L->Length++;
    return true;
}

bool ListDelete(SeqList *L, int i, ElemType *E) {
    if (i < 1 || i > L->Length)
    {
        return false;
    }
    *E = L->Data[i - 1];
    for (int j = i - 1; j < L->Length - 1; j++){
        L->Data[j] = L->Data[j + 1];
    }
    L->Length--;
    return true;
}

int LocateItem(SeqList *L, ElemType E) {
    int i;
    for (i = 0; i < L->Length; i++) {
        if (L->Data[i].value == E.value) 
            return i + 1;
    }
    return 0;
}

void show(SeqList *L)
{
    for (int i = 0; i < L->Length; i++)
    {
        if (L->Data[i].value != 0) {
            printf("index:%d, p:%p, value:%d\n", i + 1, &L->Data[i], L->Data[i].value);
        }
    }
}

int main()
{
    SeqList L = {};
    InitList(&L);

    ElemType E = {10};
    ListInsert(&L, 1, E);

    ElemType E2 = {20};
    ListInsert(&L, 1, E2);
    show(&L);

    // ElemType E3;
    // ListDelete(&L, 1, &E3);
    // show(&L);
    E.value = 30;
    int index = LocateItem(&L, E);
    printf("locate item index:%d", index);

    free(L.Data);
    return 0;
}
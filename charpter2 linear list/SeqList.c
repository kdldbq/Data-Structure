#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ElementType
{
    int value;
} ElemType;

#define MaxSize 100
#define InitSize 50
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
    // 如果index属性设置不正确
    if (i < 1 || i > L->MaxLength + 1)
    {
        return false;
    }
    // 如果i超过了Length，或者Length+1大于了当前的Size，需要扩容List
    if (i > L->Length || L->Length + 1 > sizeof(L->Data) / sizeof(ElemType))
    {
        // 如果扩容之后的大小超过了最大长度就要直接返回错误
        // 目前定义扩容的方式是将长度*2，或者刚好扩容到i的位置（如果是第一次的话）
        int CurrentAllocSize = L->Length == 0 ? i : L->Length << 1;
        if (CurrentAllocSize > MaxSize)
        {
            return false;
        }
        ElemType *temp = (ElemType *)malloc(sizeof(ElemType) * CurrentAllocSize);
        for (int j = 0; j < L->Length - 1; j++)
        {
            temp[j] = L->Data[j];
        }
        free(L->Data);
        L->Data = temp;
        L->Length = CurrentAllocSize;
    }
    // 从i开始每一个都往后挪一位
    for (int j = L->Length - 1; j >= i; j--)
    {
        L->Data[j] = L->Data[j - 1];
    }
    L->Data[i - 1] = E;
    L->Length++;
    return true;
}

int main()
{
    SeqList L = {};
    InitList(&L);
    ElemType E = {10};
    ListInsert(&L, 1, E);
    for (int i = 0; i < L.Length; i++)
    {
        printf("下标:%d,值:%s", L.Data[i], L.Data[i].value);
    }

    return 0;
}
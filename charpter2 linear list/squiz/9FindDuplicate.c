#include <stdio.h>


/**
 * 时间复杂度O(n)
 * 空间复杂度O(1)
*/
int main() {

    int A[] = {1, 2, 3};
    int B[] = {2, 3, 4};
    int C[] = {-1, 0, 2};

    int AIndex = 0, BIndex = 0, CIndex = 0;
    int ALen = sizeof(A) / sizeof(A[0]);
    int BLen = sizeof(B) / sizeof(B[0]);
    int CLen = sizeof(C) / sizeof(C[0]);

    while (AIndex < ALen && BIndex < BLen && CIndex < CLen) {
        int AValue = A[AIndex];
        int BValue = B[BIndex];
        int CValue = C[CIndex];
        // 这里直接判断，如果有三个一样的，就直接结束了
        if (AValue == BValue && BValue == CValue) {
            printf("The same number is %d\n", AValue);
            break;
        }

        // 如果没有找到，则将最小值的下标+1
        if (AValue < BValue && AValue < CValue) {
            AIndex ++;
        } else if (BValue < AValue && BValue < CValue) {
            BIndex ++;
        } else if (CValue < AValue && CValue < BValue) {
            CIndex ++;
        }
    }

    return 0;
}

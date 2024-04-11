#include <stdio.h>
#include <string.h>

/**
 * 这里的实现，是当A中的数值比较少的情况
 * 时间复杂度O(max{A})
 * 空间复杂度O(max{A})
 * 
 * 而如果比较多，可以选择排序，折中方式
*/
int main() {

    int A[] = {0, 5, 5, 3, 5, 7, 5, 5};
    // int A[] = {0, 5, 5, 3, 5, 7, 5, 1};
    int ALen = sizeof(A) / sizeof(A[0]);
    int HalfIndex = ALen >> 1;

    int max = 0;
    for (int i = 0; i < ALen; i ++) {
        if (max < A[i]) max = A[i];
    }
    int counter[max];
    memset(counter, 0, sizeof(counter));

    for (int i = 0; i < ALen; i ++) {
        if (++counter[A[i]] > HalfIndex) {
            printf("The main element is %d", A[i]);
            return 0;
        }
    }
    return 0;
}
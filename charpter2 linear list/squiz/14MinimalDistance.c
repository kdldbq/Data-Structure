#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * 时间复杂度O(S1.length + S2.length + S3.length)
 * 空间复杂度O(1)
 */
int main()
{
    int S1[] = {-1, 0, 9};
    int S2[] = {-25, -10, 10, 11};
    int S3[] = {2, 9, 17, 30, 41};

    int S1Index = 0, S2Index = 0, S3Index = 0;
    int S1Len = sizeof(S1) / sizeof(S1[0]);
    int S2Len = sizeof(S2) / sizeof(S2[0]);
    int S3Len = sizeof(S3) / sizeof(S3[0]);

    int Count = 0;

    // 初始化一个最小距离
    int MinimalDistance = 99999999;
    int Index[3];

    while (S1Index < S1Len && S2Index < S2Len && S3Index < S3Len)
    {
        int S1Value = S1[S1Index];
        int S2Value = S2[S2Index];
        int S3Value = S3[S3Index];

        int Distance = abs(S1Value - S2Value) + abs(S2Value - S3Value) + abs(S3Value - S1Value);
        if (Distance < MinimalDistance)
        {
            MinimalDistance = Distance;
            Index[0] = S1Index;
            Index[1] = S2Index;
            Index[2] = S3Index;
        }

        if (S1Value <= S2Value && S1Value <= S3Value && S1Index < S1Len - 1)
        {
            S1Index++;
        }
        else if (S2Value <= S1Value && S2Value <= S3Value && S2Index < S2Len - 1)
        {
            S2Index++;
        }
        else
            S3Index++;
    }

    printf("The minimal distance is %d, tuple is (%d, %d, %d)", MinimalDistance, S1[Index[0]], S2[Index[1]], S3[Index[2]]);
    return 0;
}
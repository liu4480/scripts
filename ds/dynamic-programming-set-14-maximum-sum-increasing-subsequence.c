// Last Update:2018-03-09 14:58:18
/**
 * @file dynamic-programming-set-14-maximum-sum-increasing-subsequence.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-09
 */
#include <stdio.h>

int maxSumIS(int arr[], int n)
{
    int i, j, max = 0;
    int msis[n];

    for(i = 0; i < n; i++)
        msis[i] = arr[i];

    for(i = 1; i < n; i++)
        for(j = 0; j < i; j++)
            if(arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];

    for(i = 0; i < n; i++)
        if(max < msis[i])
            max = msis[i];
    return max;
}

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof arr/sizeof arr[0];
    printf("Sum of maximum increasing subsequence is %d\n",
           maxSumIS(arr, n));
}
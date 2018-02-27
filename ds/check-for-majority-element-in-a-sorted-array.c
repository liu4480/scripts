// Last Update:2018-03-12 14:12:28
/**
 * @file check-for-majority-element-in-a-sorted-array.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-12
 */
#include <stdio.h>
#include <stdbool.h>

int _binarySearch(int arr[], int l, int h, int x)
{
    if ( h >= l)
    {
        int mid = (h + l) / 2;

        if ((mid == 0 || arr[mid - 1] < x) && (arr[mid] == x))
            return mid;
        else if(x > arr[mid])
            return _binarySearch(arr, mid + 1, h, x);
        else
            return _binarySearch(arr, l, mid - 1, x);
    }

    return -1;
}

bool isMajority(int arr[], int n, int x)
{
    int i = _binarySearch(arr, 0, n - 1, x);
    printf("%d\n", i);

    if (i == -1)
        return false;
    if (((i + n / 2) <= (n - 1)) && arr[i + n / 2] == x)
        return true;
    else
        return false;
}

int main()
{
    int arr[] = {1,2,3,3,3,3,10};
    int x = 3;
    int n = sizeof arr/sizeof arr[0];
    if (isMajority(arr, n, x))
        printf("%d appears more than %d times in arr[]", x, n/2);
    else
        printf("%d does not appear more than %d times in arr[]", x, n/2);

    return 0;
}

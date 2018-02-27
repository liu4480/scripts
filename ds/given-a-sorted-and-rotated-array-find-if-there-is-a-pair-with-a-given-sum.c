// Last Update:2018-02-22 17:04:35
// given a sorted and rotated array, find if there is 
// a pair with a given sum
#include<iostream>
using namespace std;
bool pairInSortedRotated(int arr[], int n, int x)
{
    int i;
    for(i = 0; i < n - 1; i++)
        if(arr[i] > arr[i + 1])
            break;

    int l = (i + 1) % n;
    int r = i;

    while(l != r)
    {
        if(arr[l] + arr[r] == x)
            return true;
        if(arr[l] + arr[r] < x)
            l = (l + 1) % n;
        else
            r = (n + r - 1) % n;
    }
    return false;
}

int main()
{
    int arr[] = {11, 15, 6, 8, 9, 10};
    int sum = 16;
    int n = sizeof(arr)/sizeof(arr[0]);
 
    if (pairInSortedRotated(arr, n, sum))
        cout << "Array has two elements with sum 16" << endl;
    else
        cout << "Array doesn't have two elements with sum 16" << endl;
 
    return 0;
}


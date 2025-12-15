#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 4, 5, 6, 7, 8, 2, 1};
    int start = 0;
    int end = sizeof(arr)/sizeof(arr[0]);
    int mid = start + (end - start) / 2;

    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    cout << start << endl;
    return 0;
}
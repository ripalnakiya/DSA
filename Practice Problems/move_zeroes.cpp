#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 1, 0, 12, 13};

    int i = 0;

    //@ Find a non-zero element for given position i
    for (int j = 0; j < 5; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    for (int x : arr)
        cout << x << " ";

    return 0;
}
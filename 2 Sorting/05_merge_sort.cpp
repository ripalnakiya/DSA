#include <bits/stdc++.h>
using namespace std;

/*
$    Merges two sorted subarrays of arr[].
#    First subarray:  leftIndex  to midIndex
#    Second subarray: midIndex+1 to rightIndex
*/
void mergeSubarrays(int *arr, int low, int mid, int high)
{
    // Sizes of the two subarrays
    int leftSize  = mid - low + 1;
    int rightSize = high - mid;

    // Temporary arrays to store copies
    vector<int> leftArray(leftSize);
    vector<int> rightArray(rightSize);

    // Copy data into temporary arrays
    for (int i = 0; i < leftSize; i++)
        leftArray[i] = arr[low + i];

    for (int j = 0; j < rightSize; j++)
        rightArray[j] = arr[mid + 1 + j];
        
    // Merge the temporary arrays back into arr[]
    int leftPointer = 0;
    int rightPointer = 0;
    int mergedIndex = low;

    while (leftPointer < leftSize && rightPointer < rightSize) {
        if (leftArray[leftPointer] <= rightArray[rightPointer]) {
            arr[mergedIndex++] = leftArray[leftPointer++];
        } else {
            arr[mergedIndex++] = rightArray[rightPointer++];
        }
    }

    // Copy remaining elements of leftArray, if any
    while (leftPointer < leftSize) {
        arr[mergedIndex++] = leftArray[leftPointer++];
    }

    // Copy remaining elements of rightArray, if any
    while (rightPointer < rightSize) {
        arr[mergedIndex++] = rightArray[rightPointer++];
    }
}

//$ Use this in Interviews: Previous one is for easy
void mergeSubarraysI(int *arr, int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else    // left > right
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low, j = 0; i <= high && j < temp.size(); ++i, ++j)
        arr[i] = temp[j];
}

void mergeSort(int *arr, int low, int high)
{
    //$ Base case: one or zero elements are already sorted
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    //$ Recursively sort both halves    
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    //$ Merge the sorted halves
    mergeSubarrays(arr, low, mid, high);
}

int main()
{
    int arr[] = {2, 1, 5, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    for (int x : arr)
        cout << x << " ";
}
#include<iostream>
using namespace std;

int findPivot(int arr[], int size)
{
    int s = 0, e = size - 1;
    int mid = s + (e-s)/2;
    while(s < e)
    {
        if(arr[mid] >= arr[0])
            s = mid + 1;
        else
            e = mid;
        
        mid = s + (e-s)/2;
    }
    return s;
}

int main(){
    int arr[6] = {4,5,6,1,2,3};
    cout<<"Pivot is at "<<findPivot(arr, 5)<<endl;
    return 0;
}
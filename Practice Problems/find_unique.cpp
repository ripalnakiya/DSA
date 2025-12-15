// https://www.codingninjas.com/studio/problems/find-unique_625159

int findUnique(int *arr, int size){
    int ans = 0;

    for(int i=0; i<size; i++)
        ans = ans^ans[i];

    return ans;
}
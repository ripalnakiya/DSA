/*
$ Average of Subarrays of Size K

Given an array of integers nums and an integer k,
return an array consisting of the average values of all contiguous subarrays of size k.

Each average should be computed as a floating-point value.

$ Example 1:
# Input: nums = [1, 3, 2, 6, -1, 4, 1, 8, 2], k = 5
# Output: [2.2, 2.8, 2.4, 3.6, 2.8]
Explanation:
Average of [1, 3, 2, 6, -1] = 11 / 5 = 2.2
Average of [3, 2, 6, -1, 4] = 14 / 5 = 2.8
Average of [2, 6, -1, 4, 1] = 12 / 5 = 2.4
Average of [6, -1, 4, 1, 8] = 18 / 5 = 3.6
Average of [−1, 4, 1, 8, 2] = 14 / 5 = 2.8

$ Example 2:
# Input: nums = [5], k = 1
# Output: [5.0]
*/

#include <bits/stdc++.h>
using namespace std;

vector<float> averageOfSubarraysOfSizeK(vector<int> &arr, int k)
{
    int n = arr.size();
    
    vector<float> result;
    result.reserve(n - k + 1); // Reserve exact space to avoid reallocations

    int windowSum = 0;

    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    float avg = static_cast<float>(windowSum) / k;
    result.push_back(avg);

    for (int right = k; right < n; right++)
    {
        windowSum += arr[right];
        windowSum -= arr[right - k];

        avg = static_cast<float>(windowSum) / k;
        result.push_back(avg);
    }

    return result;
}

int main()
{
    vector<int> arr = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int k = 5;

    vector<float> result = averageOfSubarraysOfSizeK(arr, k);

    for (auto &i : result)
        cout << i << " ";
}
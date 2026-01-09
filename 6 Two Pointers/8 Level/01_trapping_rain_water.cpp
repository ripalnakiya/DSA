/*
$ LeetCode: 42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

$ Example 1:
# Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
# Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

$ Example 2:
# Input: height = [4,2,0,3,2,5]
# Output: 9

$ Example 3:
# Input: height = [5,5,1,7,1,1,5,2,7,6]
# Output: 23
*/

/*
@   Home grown two pointer approach: Accepted on leetcode
    It's a over-engineered approach.
    ~ Time: O(n^2), Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int calculateWater(vector<int> &height, int start, int end)
{
    int l = end - start + 1;
    int h = min(height[start], height[end]);

    int area = l * h;

    // Remove the pillars from area
    for (int i = start; i <= end; i++)
    {
        int remove = height[i];

        if (remove > h) // If remove exceeds h, reduce it to h
            remove = h;

        area -= remove;
    }

    return area;
}

bool isPeakElement(vector<int> &height, int index)
{
    int n = height.size();

    bool isGreaterThanLeft = false;
    bool isGreaterThanRight = false;

    if (index == 0) isGreaterThanLeft = true;
    else isGreaterThanLeft = height[index - 1] <= height[index];

    if (index == n - 1) isGreaterThanRight = true;
    else isGreaterThanRight = height[index] >= height[index + 1];

    return isGreaterThanLeft && isGreaterThanRight;
}

// Returns next valid peak element index
int findPeak(vector<int> &height, int index, int targetHeight)
{
    int availableIndex = -1;

    while (index < height.size())
    {
        if (isPeakElement(height, index))
        {
            if (height[index] >= targetHeight)
                return index;

            if (availableIndex == -1 || height[index] > height[availableIndex])
                availableIndex = index;
        }
        index++;
    }

    return availableIndex;
}

int trap(vector<int> &height)
{
    int n = height.size();
    int totalArea = 0;

    // Find the first valid pillar
    int left = findPeak(height, 0, 0);
    int right = -1;

    // We need to find a height more than equal to targetHeight
    int targetHeight = height[left];

    while (right < n)
    {
        right = findPeak(height, left + 1, targetHeight);

        // If right goes out of bound, return the total area so far
        if (right < 0 || right >= n)
            return totalArea;

        totalArea += calculateWater(height, left, right);

        left = right;
        targetHeight = height[left];
    }
    return totalArea;
}

int main()
{
    vector<int> height = {5,5,1,7,1,1,5,2,7,6};
    int result = trap(height);
    cout << result;
}
/*
$ LeetCode: 11. Container With Most Water

You are given an integer array height of length n.
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container,
such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

$ Example 1:
# Input: height = [1,8,6,2,5,4,8,3,7]
# Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
In this case, the max area of water (blue section) the container can contain is 49.

$ Example 2:
# Input: height = [1,1]
# Output: 1
*/

/*
! Core Idea:

~ Move the pointer with the smaller height.

~ At any step:
~ The maximum area using the current shorter line has already been considered.

~ The area is limited by the shorter wall,
~ so we discard it and search for a taller one while shrinking width as slowly as possible.
*/

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int maximum = 0;
    int left = 0, right = height.size() - 1;

    while (left < right)
    {
        int area = min(height[left], height[right]) * (right - left);
        maximum = max(maximum, area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maximum;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);
    cout << result;
}
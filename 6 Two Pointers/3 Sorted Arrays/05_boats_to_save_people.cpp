/*
$ LeetCode: 881. Boats to Save People

You are given an array people where people[i] is the weight of the ith person,
and an infinite number of boats where each boat can carry a maximum weight of limit.

Each boat carries at most two people at the same time,
provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

$ Example 1:
# Input: people = [1,2], limit = 3
# Output: 1
Explanation: 1 boat (1, 2)

$ Example 2:
# Input: people = [3,2,2,1], limit = 3
# Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

$ Example 3:
# Input: people = [3,5,3,4], limit = 5
# Output: 4
Explanation: 4 boats (3), (3), (4), (5)
*/

/*
! Core Idea:
“Can I make one obvious local decision that I will never regret later?” (Greedy Approach)

Sure, try to fit in a heaviest person and lighest peron on the same boat to minimize the boat counts.

Brute Force = O(n*n)
Optimal (Greedy) = O(n log n) => Sorting makes our work easier to find the light and heavy person
*/

#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end()); // O(N log N)

    int count = 0;
    int left = 0, right = people.size() - 1;

    while (left <= right)
    {
        // Let's try to fit the heaviest and lightest person on the same boat
        if (people[left] + people[right] <= limit)
        {
            count++;
            left++;
            right--;
        }
        // Both can't go together, send the heavier person
        else
        {
            count++;
            right--;
        }
    }
    return count;
}

int main()
{
    vector<int> people = {3, 5, 4, 3};
    int limit = 3;
    int result = numRescueBoats(people, limit);
    cout << result;
}
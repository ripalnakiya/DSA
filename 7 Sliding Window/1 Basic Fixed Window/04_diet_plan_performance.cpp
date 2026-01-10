/*
$ LeetCode: Diet Plan Performance
*/

#include <bits/stdc++.h>
using namespace std;

inline int calculateScore(int windowSum, int lower, int upper)
{
    if (windowSum < lower)
        return -1;
    if (windowSum > upper)
        return 1;
    return 0;
}

int dietPlanPerformance(vector<int> &calories, int k, int lower, int upper)
{
    int n = calories.size();

    int score = 0;
    int windowSum = 0;

    for (int i = 0; i < k; i++)
        windowSum += calories[i];

    score += calculateScore(windowSum, lower, upper);

    for (int right = k; right < n; right++)
    {
        windowSum += calories[right];
        windowSum -= calories[right - k];

        score += calculateScore(windowSum, lower, upper);
    }
    return score;
}

int main()
{
    vector<int> calories = {1, 2, 3, 4, 5};
    int k = 1;
    int lower = 3;
    int upper = 3;

    int result = dietPlanPerformance(calories, k, lower, upper);

    cout << result;
}
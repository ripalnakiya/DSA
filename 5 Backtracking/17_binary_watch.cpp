/*
$ LeedCode: 401

A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.

Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM),
return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.
For example, "01:00" is not valid. It should be "1:00".

The minute must consist of two digits and may contain a leading zero.
For example, "10:2" is not valid. It should be "10:02".

$ Example 1:
# Input: turnedOn = 1
# Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

$ Example 2:
# Input: turnedOn = 9
# Output: []
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> LEDs = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};

// turnedOn: it controls the depth of recursion/backtracking, and hence we reduce it by 1 in each call
void findOnLEDs(int index, int hours, int minutes, vector<string> &result, int turnedOn)
{

    if (turnedOn == 0)
    {
        string time = to_string(hours) + ":";
        if (minutes < 10) time += "0";
        time += to_string(minutes);

        result.push_back(time);
        return;
    }

    // We never want hours to go beyond 11 and minutes to go beyond 59, hence prune those calls    
    for (int i = index; i < 10; i++)
    {
        if (i < 4)
        {
            if (hours + LEDs[i] > 11) continue; // prune un-necessary calls
            hours = hours + LEDs[i];
        }
        else
        {
            if (minutes + LEDs[i] > 59) continue; // prune un-necessary calls
            minutes = minutes + LEDs[i];
        }

        findOnLEDs(i + 1, hours, minutes, result, turnedOn - 1);

        if (i < 4)
            hours = hours - LEDs[i];
        else
            minutes = minutes - LEDs[i];
    }
}

vector<string> readBinaryWatch(int turnedOn)
{
    vector<string> result;
    findOnLEDs(0, 0, 0, result, turnedOn);
    return result;
}

int main()
{
    int turnedOn = 1;
    vector<string> result = readBinaryWatch(turnedOn);

    for (auto &v : result)
    {
        cout << v << endl;
    }
}
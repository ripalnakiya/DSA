/*
$ LeetCode: 394. Decode String
*/

#include "bits/stdc++.h"
using namespace std;

/*
    Core idea:
    - Use a stack to process characters one by one.
    - When we hit a closing bracket ']', we:
        1) Extract the substring inside the nearest '['
        2) Extract the number just before '['
        3) Repeat the substring that many times
        4) Push the expanded result back onto the stack
*/

string decodeString(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        // If current character is NOT a closing bracket,
        // just push it onto the stack.
        // This includes letters, digits, and '['
        if (s[i] != ']')
        {
            st.push(s[i]);
        }
        else
        {
            /*
            We encountered a ']'
            That means something like: k[substring]
            is complete and ready to be expanded.
            */

            string substring;
            while (st.top() != '[')
            {
                substring = st.top() + substring;
                st.pop();
            }

            st.pop(); // remove '['

            // get the number
            int multiplier = 1;
            int k = 0;
            while (!st.empty() && isdigit(st.top()))
            {
                k = (st.top() - '0') * multiplier + k;
                multiplier *= 10;
                st.pop();
            }

            string decoded;
            while (k--)
                decoded += substring;

            // Push the expanded substring back onto the stack so it can be used by outer brackets if needed    
            for (char c : decoded)
                st.push(c);
        }
    }

    string result;
    // generate the string from stack
    while (!st.empty())
    {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main()
{
    string s = "2[abc]3[ef]gh";
    string result = decodeString(s);
    cout << result << endl;
}
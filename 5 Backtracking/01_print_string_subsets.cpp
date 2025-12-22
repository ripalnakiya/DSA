#include <bits/stdc++.h>
using namespace std;

/*
$ String                = "abc"

# Sub Strings           = {a, b, c, ab, bc, abc}
~ 'ac' is not a sub-string

# Sub Sequence          = {"", a, b, c, ab, bc, ac, abc}
~ order of characters should be maintained, 'ca' is not a sub-sequence

# Sub Set / Power set   = {"", a, b, c, ab, bc, ca, abc}
~ order of character does not matter, 'ca' is a valid sub-set
~ bcz, we've studied in class 11th that order or characters doesn't matter in sub-sets (ac = ca)

! {{{sub-strings}, sub-sequences}, sub-sets}
@ Hence, all sub-sequences are sub-sets. 
@ And we can print all sub-sequnces even If we're asked to print all subsets.
*/

void printSubsets(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << " ";
        return;
    }

    //$ Generate two output templates
    string op1 = op;
    string op2 = op;

    //$ Make the decision
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    //$ Make further recursive calls
    printSubsets(ip, op1);
    printSubsets(ip, op2);
}

int main()
{
    string str = "ab";
    printSubsets(str, "");
}
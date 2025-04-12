// URL: https://leetcode.com/problems/length-of-last-word/description/
#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    int candidate = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            candidate++;
        }

        if (i != s.size() - 1 && s[i] == ' ' && s[i + 1] != ' ')
        {
            candidate = 0;
        }
    }
    return candidate;
}

int main()
{
    cout << lengthOfLastWord("World ");
    return 0;
}
// URL: https://leetcode.com/problems/number-of-senior-citizens/
#include <bits/stdc++.h>
using namespace std;

int countSeniors(vector<string> &details)
{
    int cnt = 0;
    for (auto info : details)
    {
        int number = (info[11] - '0') * 10 + (info[12] - '0');

       
        if (number > 60)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<string> s1 = {"9751302862F0693", "3888560693F7262", "5485983835F0649", "2580974299F6042", "9976672161M6561", "0234451011F8013", "4294552179O6482"};
    cout<<countSeniors(s1);

}
// URL: https://leetcode.com/problems/sort-characters-by-frequency/description/
#include <bits/stdc++.h>
using namespace std;
string frequencySort(string s)
{
    string res;
    unordered_map<char, int> mpp;

    // Step 1: Count frequencies
    for (char c : s)
    {
        mpp[c]++;
    }

    // Step 2: Move frequency data to a vector
    vector<pair<char, int>> v1(mpp.begin(), mpp.end());

    // Step 3: Sort by frequency in descending order
    sort(v1.begin(), v1.end(), [](auto a, auto b)
         { return a.second > b.second; });

    // Step 4: Build the sorted string based on frequency
    for (auto p : v1)
    {
        while (p.second--)
        {
            res += p.first;
        }
    }
    return res;
}
//"NNSWWEWSSESSWENNW"
int main()
{
    cout << frequencySort("tree");
}
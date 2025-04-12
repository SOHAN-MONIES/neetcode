// URL: https://leetcode.com/problems/even-odd-tree/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
bool checkDuplicates(vector<int> v1)
{
    map<int, int> mpp;
    for (auto num : v1)
    {
        mpp[num]++;
        if (mpp[num] > 1)
        {
            return true;
        }
    }
    return false;
}
bool checkWrongOrder(vector<int> &v1, int count)
{
    for (int i = 1; i < v1.size(); ++i)
    {
        if (count % 2 == 0) // Even level: strictly increasing
        {
            if (v1[i] <= v1[i - 1])
                return true;
        }
        else // Odd level: strictly decreasing
        {
            if (v1[i] >= v1[i - 1])
                return true;
        }
    }
    return false;
}

bool isEvenOddTree(TreeNode *root)
{
    queue<TreeNode *> q1;
    q1.push(root);
    if (root->val % 2 != 1)
    {
        return false;
    }
    int cnt = 0;
    while (!q1.empty())
    {
        int n = q1.size();
        vector<int> level(n);
        for (int i = 0; i < n; i++)
        {
            TreeNode *element = q1.front();
            q1.pop();
            level[i] = element->val;
            if (cnt % 2 == 0)
            {
                if (level[i] % 2 == 0)
                {
                    return false;
                }
            }
            if (cnt % 2 != 0)
            {
                if (level[i] % 2 != 0)
                {
                    return false;
                }
            }
            if (element->left)
            {
                q1.push(element->left);
            }
            if (element->right)
            {
                q1.push(element->right);
            }
        }
        if (checkDuplicates(level))
        {
            return false;
        }
        if (checkWrongOrder(level, cnt))
        {
            return false;
        }
        cnt++;
    }
    return true;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

void sol (TreeNode* root,vector<int>& v)
{
    if(!root) return ;
    sol(root->left,v);
    v.push_back(root->val);
    sol(root->right,v);
}
public:
    int minDiffInBST(TreeNode* root) {
       vector<int> v;
       sol(root,v);

       int min=INT_MAX;

       for (int i=1;i<v.size();i++)
       {
            if(v[i]-v[i-1]<min)
            {
                min= v[i]-v[i-1];
            }
       }

       return min;
    }
};
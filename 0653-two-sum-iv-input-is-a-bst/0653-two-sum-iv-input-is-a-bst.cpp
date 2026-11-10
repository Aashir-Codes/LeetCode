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
public:
    void sol(TreeNode *root, vector<int> &v)
    {
      if(!root) return;

      sol(root->left,v);
      v.push_back(root->val);
      sol(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        

        vector<int> v;
        sol(root,v);


        int left = 0;
        int right = v.size()-1;


        for(;left<right;)
        {
            if(v[left]+v[right]<k)left++;
            else if (v[left]+v[right] == k)return true;
            else right--;
        }
        return false;
    }
};
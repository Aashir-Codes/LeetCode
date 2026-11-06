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



   void sol(TreeNode* root, vector<int>& v)
   {
      if(!root) return;

      v.push_back(root->val);
      sol(root->left,v);
      sol(root->right,v);
   }





    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> v;

         sol(root,v);
         return v;
    }
};
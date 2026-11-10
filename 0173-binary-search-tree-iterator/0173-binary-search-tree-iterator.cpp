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
class BSTIterator {

    void sol(TreeNode *root, vector<int> &v)
    {
      if(!root) return;

      sol(root->left,v);
      v.push_back(root->val);
      sol(root->right,v);
    }
    vector<int> v;
    int current;
public:

    BSTIterator(TreeNode* root) {
  
        sol(root,v);
        current=0;

    }
    
    int next() {
 
            return v[current++];
    }
    
    bool hasNext() {
        return current < v.size();
    }
};
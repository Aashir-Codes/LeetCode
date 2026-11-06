class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
           
            if (!root->left) {
                TreeNode* child = root->right;
                delete root;
                return child;
            }
            if (!root->right) {
                TreeNode* child = root->left;
                delete root;
                return child;
            }

            TreeNode* successor = root->right;
            while (successor->left) successor = successor->left;

            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }
};
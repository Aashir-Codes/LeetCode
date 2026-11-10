class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;

        // Root is too small: the whole left side is too small too.
        // Throw away the root and keep trimming the right side.
        if (root->val < low)
            return trimBST(root->right, low, high);

        // Root is too big: the whole right side is too big too.
        if (root->val > high)
            return trimBST(root->left, low, high);

        // Root is in range: keep it, but trim both of its subtrees
        // and reattach whatever survives.
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
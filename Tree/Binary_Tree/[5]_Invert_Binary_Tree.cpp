/*
Given the root of a binary tree, invert the tree, and return its root.
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->right);
        invertTree(root->left);
        return root;
        
    }
};
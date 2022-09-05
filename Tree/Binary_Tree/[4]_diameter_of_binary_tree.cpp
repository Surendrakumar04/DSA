/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/
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
    int height(TreeNode *root){
        if(root == nullptr)
            return 0;
        int left = height(root->left) + 1;
        int right =height(root->right) + 1;
        return max(left ,right);
    }
    int diameter(TreeNode* root){
        if(root == nullptr)
            return 0;
        int h1 = height(root->left); //height of left subtree
        int h2 = height(root->right); //height of right subtree
        int op1 = h1 + h2;            //height of left subtree + height of right subtree
        int op2 = diameter(root->left); // diameter of left subtree
        int op3 = diameter(root->right); // diameter of right subtree
        return max(op1,max(op2,op3));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root);
        
    }
};
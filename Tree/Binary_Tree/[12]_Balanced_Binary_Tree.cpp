/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 
example:
    Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced

nput:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 


*/
class Solution {
public:
    bool ans = true;
    int height(TreeNode* root){
        if(root == nullptr)
            return 0;
        int h1 = height(root->left) + 1;
        int h2 = height(root->right) + 1;
        if(abs(h1-h2) > 1){
            ans = false;
            return 0;
        }
            
        return max(h1,h2);
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        int ht =  height(root);
        return ans;
        
    }
};

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center)
*/

class Solution {
public:
    bool check(TreeNode* root1, TreeNode * root2){
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(root1 == nullptr) //if root1 is null and root2 is not null
            return root2 == nullptr;
        if(root2 == nullptr) //if root2 is null and root1 is not null
            return root1 == nullptr;
        if(root1->val == root2->val){ 
            return check(root1->left,root2->right) && check(root1->right,root2->left); //check if left and right subtrees are symmetric
        }
        return false; 
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        return check(root->left, root->right);
            
        
    }
};
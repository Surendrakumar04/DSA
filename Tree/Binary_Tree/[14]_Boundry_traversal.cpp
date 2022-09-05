/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree.
 Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3

*/

class Solution {
public:
    vector<int>ans;
    void left_boundry(Node* root){
        if(root == nullptr)
            return;
        if(root->left){
            ans.push_back(root->data);
            left_boundry(root->left);
        }
        else if(root->right){
            ans.push_back(root->data);
            left_boundry(root->right);
        }
        
    }
    
    void addLeavesNode(Node* root){
        if(root == nullptr)
            return;
        addLeavesNode(root->left);
       
        if(root->left == nullptr && root->right == nullptr)
            ans.push_back(root->data);
            
        addLeavesNode(root->right);
    }
    void right_boundry(Node *root){
        if(root == nullptr){
            return;
        }
        if(root->right){
            right_boundry(root->right);
            ans.push_back(root->data);
        }
           
        else if(root->left){
            right_boundry(root->left);
            ans.push_back(root->data);
            
        }
            
       
         
    }
    vector <int> boundary(Node *root)
    {
        if(root == nullptr)
            return ans;
        if(root->left == NULL && root->right == NULL)
            return {root->data};
        ans.push_back(root->data);
        left_boundry(root->left);
        addLeavesNode(root);
        //addLeavesNode(root->right);
         right_boundry(root->right);
        return ans;
        
        
        
    }
};
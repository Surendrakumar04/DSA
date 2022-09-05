/*
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), 
that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.
Example 1:

Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13



*/

class Solution
{
public:
    int max_height = 0;
    int max_sum = 0;
    int height(Node * root, int depth) {
        if (!root) return 0;
        
        if (!root->left and !root->right) return depth;
        
        int h1 = 0; int h2 = 0;
        if (root->left) {
            h1 = height(root->left, depth + 1);
        }
        if (root->right) {
            h2 = height(root->right, depth + 1);
        }
        
        return max(h1, h2);
    }
    void m_height(Node * root, int  depth, int sum) {
        if (!root) return;
        
        if (!root->left and !root->right) {
            if (depth == max_height) {
                max_sum = max(max_sum, sum + root->data);
                return;
            }
            else
                return;
        }
        
        if (root->left) {
            m_height(root->left, depth + 1, sum + root->data);
        }
        
        if (root->right) {
            m_height(root->right, depth + 1, sum + root->data);
        }
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        max_height = height(root, 1);
        m_height(root, 1, 0);
        return max_sum;
    }
};
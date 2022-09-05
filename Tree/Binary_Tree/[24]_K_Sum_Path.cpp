/*
Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
A path may start from any node and end at any node in the downward direction.

Example 1:

Input: 
Tree = 
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
K = 5                    
Output: 8
Explanation:
The following paths sum to K.  
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 


*/
class Solution{
  public:
    int count = 0;
    void helper(Node * root, int targetSum, vector<long long> &temp) {
        if (!root) return;
        
        temp.push_back(root->data);
        helper(root->left,targetSum,temp);
        helper(root->right,targetSum,temp);
        int n = temp.size();
        long long c = 0;
        for (int i = n - 1; i >= 0; i--) {
            c += temp[i];
            if (c == targetSum)
                ++count;
        }
        temp.pop_back();
    }
    int sumK(Node *root,int targetSum)
    {
        if (!root) return 0;
        vector<long long> temp;
        helper(root, targetSum, temp);
        
        return count; 
    }
};
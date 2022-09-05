/*
Given a binary tree with a value associated with each node, 
we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint 
that no two chosen node in subset should be directly connected that is, 
if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

Example 1:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*, int>mp;
    int sumGrandChildren(Node* root){ //returns the sum of grandchildren of the node
        int sum = 0;
        
        if(root->left){
            sum += getMaxSum(root->left->left) + getMaxSum(root->left->right); // sum of grandchildren of left child of root if it exists
            
        }
        if(root->right){
            sum += getMaxSum(root->right->left) + getMaxSum(root->right->right); // sum of grandchildren of right child of root if it exists
        }
        return sum;
        
    }
    int getMaxSum(Node *root){
        if(root == nullptr)
            return 0;
        if(mp.find(root) != mp.end())
            return mp[root];
        int a = root->data + sumGrandChildren(root); // root + grandchildren sum of root if root is included in the sum
        int b = getMaxSum(root->left) + getMaxSum(root->right); // left + right children sum if root is not included in the sum
        return mp[root] = max(a,b); // return the max of a and b
        
    
    
        
    }
};

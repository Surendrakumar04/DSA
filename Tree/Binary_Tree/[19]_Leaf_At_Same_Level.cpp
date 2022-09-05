/*
Given a Binary Tree, check if all leaves are at same level or not.



Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.
*/

class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root){
        queue<Node*>q;
        q.push(root);
        int count = 0;
        int flag = 0;
        int prevcount = 0;
        while(!q.empty()){
            int n = q.size();
            count++;
            while(n--){
                Node* temp = q.front();
                q.pop();
                if(temp->left == nullptr && temp->right == nullptr && flag == 0){ // find the first leaf node
                    flag = 1;
                    prevcount = count;
                }
                if(temp->left == nullptr && temp->right == nullptr &&(prevcount != count)) // if leaf node is not at same level then return false
                    return false;
                    
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
               
                    
            }
        }
        return true;
    }
    
};
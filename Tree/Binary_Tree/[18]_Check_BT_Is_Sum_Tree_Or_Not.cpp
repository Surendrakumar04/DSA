/*
Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, 
its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. 
A leaf node is also considered a Sum Tree.
Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0
Explanation:
The given tree is not a sum tree.
For the root node, sum of elements
in left subtree is 40 and sum of elements
in right subtree is 30. Root element = 10
which is not equal to 30+40.


*/


class Solution
{
    public:
    bool isSumTree(Node* root)
    {
        if(root == nullptr)
            return 1;
        queue<Node*>q;
        stack<Node*>st;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node* temp = q.front();
                q.pop();
                if(temp->left || temp->right )
                    st.push(temp);
                if(temp->right)
                    q.push(temp->right);
                
                if(temp->left)
                    q.push(temp->left);
            }
        }
        while(!st.empty()){
            Node* temp1 = st.top();
            st.pop();
            if(temp1->left == nullptr && (temp1->data == temp1->right->data))
                temp1->data += temp1->right->data;
                
            else if(temp1->right == nullptr && (temp1->data == temp1->left->data))
                temp1->data += temp1->left->data;
                
            // below condition is important **    
            else if((temp1->left && temp1->right)&& temp1->data == (temp1->left->data + temp1->right->data))
                temp1->data += temp1->left->data + temp1->right->data;
                
            else
                return false;
        }
        return true;
        
        
    }
};
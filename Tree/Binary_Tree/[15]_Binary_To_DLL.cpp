/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30.
*/


class Solution
{
    public: 
    Node* prev = nullptr; // previous node in DLL
    Node* head = nullptr; // head of the DLL
    void solve(Node* root){
        if(root == nullptr)
            return;
        solve(root->left);
        if(prev == nullptr) // first node in DLL
            head = root;    // assign head
        else{               // not first node in DLL
            root->left = prev;
            prev->right = root;
            
        }
        prev = root; // assign previous node
        solve(root->right); // recurse on right subtree
        
    }
    Node * bToDLL(Node *root){
        solve(root);
        return head;
    }
};

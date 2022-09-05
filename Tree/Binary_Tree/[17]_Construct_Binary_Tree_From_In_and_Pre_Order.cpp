/*
Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal.
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5 

*/
class Solution{
    public:
    Node* BT_helper(int in[], int pre[],int s, int e, int &index){
        if(s > e){
            return nullptr;
        }
        int rootData = pre[index++];
        Node* root = new Node(rootData);
        int rootIndex = -1;
        for(int i = s; i <= e; i++){
            if(in[i] == rootData){
                rootIndex= i;
                break;
            }
        }
        if(s == e){
            return root;
        }
        root->left = BT_helper(in,pre,s,rootIndex-1,index);
        root->right = BT_helper(in,pre,rootIndex+1,e,index);
        return root;    
    }
    
    Node* buildTree(int in[],int pre[], int n){
        int index = 0;
        return BT_helper(in,pre,0,n-1,index);      
    }
};
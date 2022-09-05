//1. right view of binary tree
class Solution {
public:
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n){
                TreeNode* data = q.front();
                q.pop();
                if(n == 1)
                    ans.push_back(data->val);
                if(data->left != nullptr)
                    q.push(data->left);
                if(data->right != nullptr)
                    q.push(data->right);
                n--;
                
            }
        }
        return ans;
        
    }
    
};
/* 2.left view of binary tree
Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   
*/ 
vector<int> leftView(Node *root)
{
    vector<int>ans;
    if(root == nullptr)
        return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        int t = n;
        while(n){
            Node* temp = q.front();
            q.pop();
            if(t == n)
                ans.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            n--;
        }
    }

    return ans;
}
/* 3. bottom view of binary tree
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25

*/
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mp;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto temp = q.front();
                q.pop();
                mp[temp.second] = temp.first->data;
                if(temp.first->left)
                    q.push({temp.first->left,temp.second-1});
                if(temp.first->right)
                    q.push({temp.first->right,temp.second+1});
                
            }
        }
        vector<int>ans;
        for(auto it : mp)
            ans.push_back(it.second);
        return ans;
       
    }
};

/*
4. top view of binary tree
A node is included in top view if it can be seen when we look at the tree from top.

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mp;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto temp = q.front();
                q.pop();
                // if not found, then only insert, 
                //it will be the first time we see this node from the top view
                if(mp.find(temp.second) == mp.end()) 
                    mp[temp.second] = temp.first->data;
                if(temp.first->left)
                    q.push({temp.first->left,temp.second-1});
                if(temp.first->right)
                    q.push({temp.first->right,temp.second+1});
                
            }
        }
        vector<int>ans;
        for(auto it : mp)
            ans.push_back(it.second);
        return ans;
        
    }

};


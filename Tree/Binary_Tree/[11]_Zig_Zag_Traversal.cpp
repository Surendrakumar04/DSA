/*
Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 

*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        queue<Node*>q;
        q.push(root);
        int count =0;
        vector<int>ans;
        while(!q.empty()){
            count++;
            int n = q.size();
            vector<int>v;
            while(n--){
                Node* temp = q.front();
                q.pop();
                v.push_back(temp->data);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(count % 2 == 0){ //if count is even, reverse the vector
                reverse(v.begin(),v.end());
            }
            // for(int it : v)
            //     ans.push_back(it);
            ans.insert(ans.end(),v.begin(),v.end());
            
        }
        return ans;
    }
};

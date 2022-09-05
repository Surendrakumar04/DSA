/*
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>v;
        vector<int>v1;
        
        if(root == NULL)
            return v;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            v1.clear();
            while(n--){
                TreeNode* f = q.front();
                q.pop();
                v1.push_back(f->val);
                if(f->left != NULL)
                    q.push(f->left);
                if(f->right != NULL)
                    q.push(f->right);
            }
            v.push_back(v1);
            
        }
        return v;
        
    }
};
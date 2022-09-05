class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        if(root == nullptr)
            return ans;
        st.push(root); //push root to stack
        
        while(!st.empty()){
            TreeNode* popped = st.top(); //pop top element from stack
            ans.push_back(popped->val);
            st.pop();
            if(popped->right) //if right child exists, push it to stack
                st.push(popped->right);
            if(popped->left) //if left child exists, push it to stack
                st.push(popped->left);
        }
        return ans;
        
    }
};
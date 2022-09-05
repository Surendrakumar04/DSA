class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr)
            return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* popped = st.top();
            st.pop();
            ans.push_back(popped->val);
            if(popped->left)
                st.push(popped->left);
            if(popped->right)
                st.push(popped->right);
        }
        reverse(ans.begin(),ans.end()); // reverse the vector
        return ans;     
    }
};
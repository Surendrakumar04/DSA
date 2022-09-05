class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode* curr = root;
        curr = root;
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;

        }
        while(!st.empty() && curr == NULL){
            TreeNode * popped = st.top();
            st.pop();
            ans.push_back(popped->val);
            curr = popped->right;
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
        }    
        return ans;
        
    }
};
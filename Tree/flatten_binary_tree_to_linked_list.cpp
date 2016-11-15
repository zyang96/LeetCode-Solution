/*
it is basically a inorder traversal
Solution 1.
Time complexity: O(n)
Space complexity: O(n)	
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        TreeNode* tempNode;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            tempNode = stk.top();
            stk.pop();
            if (tempNode->right != NULL) stk.push(tempNode->right);
            if (tempNode->left != NULL) stk.push(tempNode->left);
            if (!stk.empty())tempNode->right = stk.top();
            tempNode->left = NULL;
        }
    }
};
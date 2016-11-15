/*
BST, and track the end of each level by using a counter
uses a queue
Solution 1.
Time complexity: O(n)
Space complexity: O(n) 	
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        TreeLinkNode * currNode;
        int counter(1);
        while (!q.empty()) {
            currNode = q.front();
            q.pop();
            if (currNode != NULL) {
                q.push(currNode->left);
                q.push(currNode->right);
            }
            if (--counter == 0) {
                counter = q.size();
                if (currNode != NULL) currNode->next = NULL;
                continue;
            } 
            if (currNode != NULL) currNode->next = q.front();
            
        }
        
    }
};
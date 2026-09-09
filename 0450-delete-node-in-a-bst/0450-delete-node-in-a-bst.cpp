/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        if(root->val != key && root->val > key){
            root->left  = deleteNode(root->left,key);
        }

        else if(root->val != key && root->val < key){
            root->right  = deleteNode(root->right,key);
        }

        else{
            //0 child
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }

            //only right child
            if(root->left == NULL){
                return root->right;
            }

            //only left child
            if(root->right == NULL){
                return root->left;
            }

            //both child
            TreeNode* predecessor = root->left;

            while(predecessor->right != NULL){
                predecessor = predecessor->right;
            }
            root->val = predecessor->val; 
            root->left = deleteNode(root->left, predecessor->val);
        }
        
        return root;
    }
};
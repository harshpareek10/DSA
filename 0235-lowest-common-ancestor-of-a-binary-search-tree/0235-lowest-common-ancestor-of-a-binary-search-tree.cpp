/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    bool FindPath(TreeNode* root,vector<TreeNode*>& path,TreeNode* p){
        if(root == NULL){
            return false;
        }
            path.push_back(root);
            if(root == p){
                return true;
            }

            if(root->val >= p->val){
                if(FindPath(root->left,path,p)){
                return true;
                }
            }else{
                if(FindPath(root->right,path,p)){
                return true;
                }
            }
        path.pop_back();
        return false;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*>path2;

        FindPath(root,path1,p);
        FindPath(root,path2,q);

        TreeNode* LCA = NULL;

        for(int i = 0 , j = 0; i < path1.size() && j < path2.size(); i++,j++){
            if(path1[i] != path2[j]){
                break;
            }
            LCA = path1[i];
        }
    return LCA;
    }
};
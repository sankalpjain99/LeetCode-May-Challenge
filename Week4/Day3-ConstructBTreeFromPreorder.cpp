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
    
    TreeNode* Helper(vector<int>& preorder, int i,int j){
        if(i>j)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        if(i==j)
            return root;
        int x = i+1;
        while(x<=j){
            if(preorder[x]>preorder[i])
                break;
            x++;
        }
        root->left = Helper(preorder,i+1,x-1);
        root->right = Helper(preorder,x,j);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(!n)
            return NULL;
        return Helper(preorder,0,n-1);
    }
};
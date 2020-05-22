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

    int level(TreeNode* root,int x,int lev){
        if(root==NULL)
            return 0;
        if(root->val == x)
            return lev;

        int l = level(root->left,x,lev+1);
        if(l!=0)
            return l;
        return level(root->right,x,lev+1);
    }

    bool sameParent(TreeNode* root,int a,int b){
        if(root==NULL)
            return false;
        if(root->left && root->right && ((root->left->val==a && root->right->val==b) || (root->left->val==b && root->right->val==a)))
            return true;

        return sameParent(root->left,a,b)||sameParent(root->right,a,b);

    }

    bool isCousins(TreeNode* root, int x, int y) {
        int l1 = level(root,x,1);
        int l2 = level(root,y,1);
        cout<<l1<<" "<<l2<<"\n";
        if(l1!=l2)
            return false;
        if(!sameParent(root,x,y))
            return true;
        return false;
    }
};

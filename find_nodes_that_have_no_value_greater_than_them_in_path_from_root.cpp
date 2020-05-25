class Solution {
public:
   
    int ans =0;
    void helper( TreeNode * root , int maxtillnow ){

        if( root == NULL ) return ;

        if( root->val >= maxtillnow ) ans++;

        helper( root->left , max( maxtillnow , root->val ) );
        helper( root->right , max( maxtillnow , root->val ) );
           
    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        
        ans =0;
        helper( root , INT_MIN);

        return ans ;

   
    }
};
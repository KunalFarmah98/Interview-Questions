#include <bits/stdc++.h>
#include <map>
#include <utility>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


TreeNode* create(){
  
   // TreeNode* root = NULL;
      string l,r;

      // if(!root)
      // 	retur root;

   int x;

   cin>>x;

   TreeNode* root = new TreeNode(x);
   cin>>l;

   if(l=="true"){
   
   	root->left = create();
   }


    cin>>r;

    if(r=="true"){
    	
    	root->right = create();
    }

    if(r=="false"){
        	if(!root)
    		return root;
    }


   return root;

}


// this funciton doesn't care if any of the values are not present

TreeNode* LCA(TreeNode* root, int c1, int c2){

  if(!root)
    return NULL;

  if(root->data == c1 || root->data ==c2)  // if root has both or one as children return root and register it as one ans
    return root;

  // checking in left and right subtress

  TreeNode* left = LCA(root->left,c1,c2);  
  TreeNode* right = LCA(root->right,c1,c2);

  if(left && right)   // if both lie in left and right subtree then return the current root which was registered
    return root;


 return (left != NULL)? left: right;


}


/*// This function returns pointer to LCA of two given values n1 and n2.
// v1 is set as true by this function if n1 is found
// v2 is set as true by this function if n2 is found

struct Node *findLCAUtil(struct Node* root, int n1, int n2, bool &v1, bool &v2)
{
    // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report the presence
    // by setting v1 or v2 as true and return root (Note that if a key
    // is ancestor of other, then the ancestor key becomes LCA)
    if (root->key == n1)
    {
        v1 = true;
        return root;
    }
    if (root->key == n2)
    {
        v2 = true;
        return root;
    }
 
    // Look for keys in left and right subtrees
    Node *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2);
    Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}
 

// Returns true if key k is present in tree rooted with root

bool find(Node *root, int k)
{
    // Base Case
    if (root == NULL)
        return false;
 
    // If key is present at root, or in left subtree or right subtree,
    // return true;
    if (root->key == k || find(root->left, k) ||  find(root->right, k))
        return true;
 
    // Else return false
    return false;
}
 
// This function returns LCA of n1 and n2 only if both n1 and n2 are present
// in tree, otherwise returns NULL;
Node *findLCA(Node *root, int n1, int n2)
{
    // Initialize n1 and n2 as not visited
    bool v1 = false, v2 = false;
 
    // Find lca of n1 and n2 using the technique discussed above
    Node *lca = findLCAUtil(root, n1, n2, v1, v2);
 
    // Return LCA only if both n1 and n2 are present in tree
    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
        return lca;
 
    // Else return NULL
    return NULL;
}*/


int main(){

	TreeNode* root = create();

  int c1,c2;

  cin>>c1;
  
  cin>>c2;
  
	TreeNode* ans = LCA(root,c1,c2);
  cout<<ans->data;

}

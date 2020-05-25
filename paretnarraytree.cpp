#include<bits/stdc++.h>

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



void preOrderPrint(TreeNode* root){
    
    if (root == NULL) return;

    cout << root->data << " ";

    preOrderPrint(root->left);
    preOrderPrint(root->right);
   
}


 TreeNode* createParentArrayTree(int parent[], int n)
{
    // create an empty map
	unordered_map<int,  TreeNode*> map;

	// create n new tree  TreeNodes each having value from 0 to n-1
	// and store them in a map
	for (int i = 0; i < n; i++)
		map[i] = new TreeNode(i);          // creating a map of nodes pointing to their indices

    // represents root Node of binary tree
	 TreeNode *root = nullptr;

	// traverse the parent array and build the tree
	for (int i = 0; i < n; i++)
	{
	    // if parent is -1, set root to current  TreeNode having
	    // value i (stored in map[i])
		if (parent[i] == -1)
			root = map[i];
		else
		{
		    // get parent  TreeNode for current  TreeNode
			 TreeNode *currparent = map[parent[i]];

			// if its first child, i.e left child is empty
			if (!currparent->left)
				currparent->left = map[i];
				

			// if parent's left child is there, that is it is the second child , map the Node to it
            else
				currparent->right = map[i];
		}
	}

	// return root of the constructed tree
	return root;
}



int main(){


 int t;
 int n, parent[100];

 cin>>t;

 while(t>0){
 	cin>>n;

 	for(int i=0; i<n; i++)
 		cin>>parent[i];

 	auto root= createParentArrayTree(parent,n);

 	preOrderPrint(root);
 	cout<<endl;

 	--t;

 }

}
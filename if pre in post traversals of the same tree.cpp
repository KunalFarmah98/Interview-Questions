#include <bits/stdc++.h> 
using namespace std; 
bool checktree(int preorder[], int inorder[], int postorder[], int len) ;

class tree{
    public:
     tree* left;
     tree* right;
     int data;
     
     tree(int x){
         data=x;
         left=NULL;
         right=NULL;
     }
};


int search(int arr[], int strt, int end, int value)  
{  
    int i;  
    for (i = strt; i <= end; i++)  
    {  
        if (arr[i] == value)  
            return i;  
    }  
}  
 
tree* buildTree(int in[], int pre[], int inStrt, int inEnd)  
{  
    static int preIndex = 0;  
  
    if (inStrt > inEnd)  
        return NULL;  
  
    /* Pick current node from Preorder 
    traversal using preIndex  
    and increment preIndex */
    tree* tNode = new tree(pre[preIndex++]);  
  
    /* If this node has no children then return */
    if (inStrt == inEnd)  
        return tNode;  
  
    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);  
  
    /* Using index in Inorder traversal, construct left and  
    right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);  
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);  
  
    return tNode;  
}  
  



tree* buildtree(int inorder[], int preorder[], int b,int e){
    static int preind=0;
    if(b>e)return NULL;
    tree* root = new tree(preorder[preind++]);
    
    if(b==e)return root;
    
    int i=b;
    bool found=false;
    for(;i<=e; i++){
        if(inorder[i]==root->data){
            found=true;
            break;    
        }
    }
    if(!found)return NULL;

    root->left = buildtree(preorder,inorder,b,i-1);
    root->right = buildtree(preorder,inorder,i+1,e);
    
    return root;
}

vector<int> ans;
void postorder(tree* root){
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    //cout<<root->data<<" ";
    ans.push_back(root->data);

}
bool checktree(int preorder[], int inorder[], int postorder[], int len) 
{
    // if the array lengths are 0, 
    // then all of them are obviously equal 
    if (len == 0) 
        return 1; 
  
    // if array lengths are 1, 
    // then check if all of them are equal 
    if (len == 1) 
        return (preorder[0] == inorder[0]) 
               && (inorder[0] == postorder[0]); 
  
    // search for first element of preorder 
    // in inorder array 
    int idx = -1; 
    for (int i = 0; i < len; ++i) 
        if (inorder[i] == preorder[0]) { 
            idx = i; 
            break; 
        } 
  
    if (idx == -1) 
        return 0; 
  
    // check for the left subtree 
    int ret1 = checktree(preorder + 1, inorder, 
                         postorder, idx); 
  
    // check for the right subtree 
    int ret2 = checktree(preorder + idx + 1, inorder + idx + 1, 
                         postorder + idx, len - idx - 1); 
  
    // return 1 only if both of them are 
    // correct else 0 
    return (ret1 && ret2); 
}


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preorder[n];
        int inorder[n];
        int postorder[n];

        for (int i = 0; i < n; ++i)
            cin>>preorder[i];

        for (int i = 0; i < n; ++i)
            cin>>inorder[i];

        for (int i = 0; i < n; ++i)
            cin>>postorder[i];

        if(checktree(preorder, inorder, postorder, n) )
            cout << "Yes\n";
        else
            cout<<"No\n";
    } 
    return 0; 
} 

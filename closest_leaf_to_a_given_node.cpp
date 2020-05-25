// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

int findClosest(struct Node *root, int k);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k;
        scanf("%d ",&k);
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        cout<<findClosest(root,k)<<endl;
    }
    return 1;
}// } Driver Code Ends
//User function Template for C++

/*

Structure of Node:

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

*/
// A utility function to find minimum of x and y 
int getMin(int x, int y) 
{ 
    return (x < y)? x :y; 
} 
  
// A utility function to find distance of closest leaf of the tree 
// rooted under given root 
int closestDown(struct Node *root) 
{ 
    // Base cases 
    if (root == NULL) 
        return INT_MAX; 
    if (root->left == NULL && root->right == NULL) 
        return 0; 
  
    // Return minimum of left and right, plus one 
    return 1 + getMin(closestDown(root->left), closestDown(root->right)); 
} 
  
// Returns distance of the cloest leaf to a given key 'k'.  The array 
// ancestors is used to keep track of ancestors of current node and 
// 'index' is used to keep track of current index in 'ancestors[]' 
int findClosestUtil(struct Node *root, int k, struct Node *ancestors[], 
                                               int index) 
{ 
    // Base case 
    if (root == NULL) 
        return INT_MAX; 
  
    // If key found 
    if (root->data == k) 
    { 
        //  Find the cloest leaf under the subtree rooted with given key 
        int res = closestDown(root); 
  
        // Traverse all ancestors and update result if any parent node 
        // gives smaller distance 
        for (int i = index-1; i>=0; i--) 
            res = getMin(res, index - i + closestDown(ancestors[i])); 
        return res; 
    } 
  
    // If key node found, store current node and recur for left and 
    // right childrens 
    ancestors[index] = root; 
    return getMin(findClosestUtil(root->left, k, ancestors, index+1), 
                  findClosestUtil(root->right, k, ancestors, index+1)); 
  
} 
  
// The main function that returns distance of the closest key to 'k'. It 
// mainly uses recursive function findClosestUtil() to find the closes 
// distance. 
int findClosest(struct Node *root, int k) 
{ 
    // Create an array to store ancestors 
    // Assumptiom: Maximum height of tree is 100 
    struct Node *ancestors[1000]; 
  
    return findClosestUtil(root, k, ancestors, 0); 
} 


/*Node* bsearch(Node* root, int k){
    if(!root)return root;
    
    if(root->data==k)return root;
    bsearch(root->left,k);
    bsearch(root->right,k);
}

Node* parent(Node* root, int k){
    if(!root)return root;
    if((root->left && root->left->data==k) || (root->right && root->right->data==k))return root;
    bsearch(root->left,k);
    bsearch(root->right,k);
}

int dist(Node* root){
    if(!root)return 0;
    int leftc = dist(root->left);
    int rigthtc = dist(root->right);
    
    return min(leftc,rigthtc)+1;
}


int findClosest(struct Node *root, int k)
{
    Node* rootk = bsearch(root,k);
    Node* par = parent(root,k);
    // find closest leaf in the subtree rooted with k, its children
    int ans1 =  dist(rootk);
    
    if(!par)return ans1;
    
    // if k was left child of its parent, check for a leaf in right of its parent, sibling might have a closer leaf
    if(par->left->data==k){
        return min (ans1,dist(par->right)+1);
    }
    
    // if k was right child of its parent, check for a leaf in left of its parent, sibling might have a closer leaf
    else{
        return min (ans1,dist(par->left)+1);
    }
}*/
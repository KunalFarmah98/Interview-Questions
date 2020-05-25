
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
  
    void iterPreorder(TreeNode* root, vector<int> &a){
        stack<TreeNode*> s;
        s.push(root);
        // push root and its right and then left child
        // and print it while popping out
        while(!s.empty()){
            root = s.top();
            s.pop();
            a.push_back(root->val);
             if(root->right){
                s.push(root->right);
            }
            if(root->left){
                s.push(root->left);
            }
        }
    }

    void iterInorder(TreeNode* root, vector<int> &a){
        if(!root)return;
        stack<TreeNode*>s;
        // if root is not null, push root and go left
        // else pop root, print it and go right
        // keep doing this till stack is not empty
        while(true){
            if(root){
                s.push(root);
                root=root->left;
            }
            else{
                if(s.empty())
                    break;
                root = s.top();
                s.pop();
                a.push_back(root->val);
                root=root->right;
            }
        }
    }

 // using 2 stacks for postorder
/*  1. Push root to first stack.
    2. Loop while first stack is not empty
    2.1 Pop a node from first stack and push it to second stack
    2.2 Push left and right children of the popped node to first stack
    3. Print contents of second stack*/
    void postOrderIterative(TreeNode* root, vector<int> a){ 
        if (root == NULL) 
            return; 
      
        // Create two stacks 
        stack<TreeNode *> s1, s2; 
      
        // push root to first stack 
        s1.push(root); 
        TreeNode* node; 
      
        // Run while first stack is not empty 
        while (!s1.empty()) { 
            // Pop an item from s1 and push it to s2 
            node = s1.top(); 
            s1.pop(); 
            s2.push(node); 
      
            // Push left and right children 
            // of removed item to s1 
            if (node->left) 
                s1.push(node->left); 
            if (node->right) 
                s1.push(node->right); 
        } 
      
        // Print all elements of second stack 
        while (!s2.empty()) { 
            node = s2.top(); 
            s2.pop(); 
            a.push_back(node->val);
        } 
    } 

    // using 1 stack for postorder
    // push root twice and go to left until we reach NULL
    // current element is taken from top of stack
    // if current is at top of stack (we pushed root twice),
    // go to right else print root
    void postOrderIterative(TreeNode* root) { 
        stack<TreeNode*> s; 
        while(true) { 
            while(root != null) { 
                s.push(root); 
                s.push(root); 
                root = root.left; 
            } 
              
            // Check for empty stack 
            if(s.empty()) 
                return; 
            
            root = s.top();
            s.pop(); 
              
            if(!stack.empty() && stack.top() == root) 
                root = root.right; 
              
            else { 
                  
                cout<<root->val<<" ";
            } 
        } 
    } 
    vector<int> Traversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        iterPreorder(root,ans);
        return ans;
    }
};
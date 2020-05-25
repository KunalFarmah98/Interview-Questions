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

class node{
public:
	int data;
	node* next;

	node(int x){
		data=x;
		next=NULL;
		}
};


#define head first        //macros to define first and last as head and tail for better understanding
#define tail second




typedef pair<TreeNode*, TreeNode*> pht;

pht bstToLL(TreeNode* root){
    if (root == NULL){
        return pht(NULL, NULL);   // 0 == NULL   
    }

    pht leftAns = bstToLL(root->left); 
    pht rightAns = bstToLL(root->right);

    pht ans(NULL, NULL);

    if (leftAns.tail != NULL){
       
        leftAns.tail->right = root;        // note pht is not a pointer but a class
        ans.head = leftAns.head;             // left pointer stays null always
    }
    else {
        ans.head = root;
    }

    if (rightAns.head != NULL){
       
        root->right = rightAns.head;
        ans.tail = rightAns.tail;
    }
    else {
        ans.tail = root;
    }
    return ans;
}


TreeNode* insertIntoBst(TreeNode* root, int x){
    if (!root) return new TreeNode(x);

    if (x < root->data){
        root->left = insertIntoBst(root->left, x);
    }
    else {
        root->right = insertIntoBst(root->right, x);
    }
    return root;
}


TreeNode* createBST(){
    int x;
    TreeNode* root = NULL;
    while(cin >> x && x != -1){
        root = insertIntoBst(root, x);
    }
    return root;
}



void displaylist(node* head){

    while(head!=NULL){   //while(head) is equivalent meaning while head exists

        cout<<head->data<<endl;
        head=head->next;

    }
}

    

int main(){

    TreeNode* root = createBST();
    
    pht ans = bstToLL(root);

    TreeNode* curHead = ans.head;
    while(curHead){
        cout << curHead->data << " ";
        curHead = curHead->right;
    }
}
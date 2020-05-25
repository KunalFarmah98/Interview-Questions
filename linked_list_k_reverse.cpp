#include<iostream>
#include<stack>
using namespace std;


class node{

public:

    int data;
    node* next;

    node(int d){
        data= d;
        next= NULL;
    }

};



node* createlinkedlist(int n) {

    int i=0;
    node *head = NULL;
    node *tail = NULL;


    while(i<n) {
        int x;
        cin >> x;
        i++;

//        if (x == -1)
//            break;

        node *temp = new node(x);   //creating the new node

        if (head == NULL) {       // if it is the first node then head =tail = node ka address
            head = temp;
            tail = temp;
        }
        else {                     // otherwise increment tail
            tail->next = temp;
            tail = tail->next;
        }
    }

    return head;
}

node* createlinkedlist2(int x) {


    node *head = NULL;
    node *tail = NULL;



    node *temp = new node(x);   //creating the new node

    if (head == NULL) {       // if it is the first node then head =tail = node ka address
        head = temp;
        tail = temp;
    }
    else {                     // otherwise increment tail
        tail->next = temp;
        tail = tail->next;
    }

    return head;
}


void displaylist(node* head){

    while(head!=NULL){   //while(head) is equivalent meaning while head exists
        cout<<head->data<<" ";
        head=head->next;

    }
}

/*node* kreverse(node* head,int k){

    stack<node*>s;

    auto curr = head;
    node* head1 = NULL;

    int i=0;

    if(!head)
        return head1;

    while(curr && i<k){
        s.push(curr);
        ++i;
        curr=curr->next;
    }

    while( !s.empty()){

        head1 = createlinkedlist2(s.top()->data);
        s.pop();
        // head1 = head->next;
        if(!head1)
            break;
    }

    if(curr) head = kreverse(curr, k);


//return curr;

}*/


node* k_reverse(node* head, int k){
    node* cur = head;
    node* ahead= NULL;
    node* prevNode = NULL;
    int i=0;

    while(cur && i<k){
        ahead = cur->next;
        cur->next = prevNode;
        prevNode = cur;
        cur = ahead;
        ++i;
    }                          // after this ahead will point to the k+1 th node

    if(ahead)
      
      head->next = k_reverse(ahead,k);
   
    return prevNode;     // prevnode becomes the head here
}




int main(){

    int n;
    int k;
    cin>>n>>k;

    node*a = createlinkedlist(n);

    node*ans = k_reverse(a,k);

    displaylist(ans);

    return 0;

}
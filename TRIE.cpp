
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	char data;
	// a map holds the pointers to the nodes after it
	unordered_map<char,Node*> h;
	bool isTerminal;
	Node(char c){
		data=c;
		isTerminal=false;
	}
};


class Trie{
public:
	Node* root;
	Trie(){
		// root is empty for data
		root = new Node('\0');
	}

	void insert(string word){

        Node* temp = root;
		for(int i=0; word[i]!='\0'; i++){
			char ch = word[i];
			// if the letter dne
			if(temp->h.count(ch)==0){
				// create a new node
				Node* child  = new Node(ch);
				// make the child of root's (temp) as the new node
				temp->h[ch] = child;
				// temp = temp->next
				temp = child;
			}

			else{
				// if it already exists, directly go to that node
				temp = temp->h[ch]; 
			}
		}
        // when we reach the end of the word, mark the terminal node
		temp->isTerminal = true;
	}


	bool search(string word){

		Node* temp = root;
		for(int i=0; word[i]!='\0'; i++){
			char ch = word[i];
			// if a char is found, go to its node
			if(temp->h.count(ch))
				temp = temp->h[ch];
			// if any char is not found, return false
			else return false;
		}
	// if we found the word, if the last node is the terminal, then it exists else it dne.
	return (temp->isTerminal)?true:false;


	}
};

int main(){
	Trie T;
	T.insert("Code");
	T.insert("Coding Blocks");
	T.insert("Jhasa");
	T.insert("Fail");

	string s;
	getline(cin,s);

	cout<<T.search(s)<<endl;



	return 0;
}
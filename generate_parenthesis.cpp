
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

vector<char brackets[100]>;

void print(char a[]){
	for(int i=0; a[i]!='\0';i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void generate_parenthesis(int opencnt, int closecnt, int index, int n ){

     if(index==2*n){   // there are n pairs of 2, hence total of 2n places are to be filled
         brackets[index]='\0';
         print(brackets);
         return;
     }

// opening bracket can only be placed if number is < n
     if(opencnt<n){   // if we can place an openting bracket place it
     	brackets[index]='(';
     	generate_parenthesis(opencnt+1,closecnt,index+1,n);
     }

//closing can only be placed when number is less than opening otherwise it won't be balanced

    if(closecnt<opencnt){   // if we can place a closing bracket place it
     	brackets[index]=')';
     	generate_parenthesis(opencnt,closecnt+1,index+1,n);
     }

}

int main(){
	
   int n;
   cin>>n;

   generate_parenthesis(0,0,0,n);


	return 0;
}
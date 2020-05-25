#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// all elements occur twice exept 2 elements
int rightmostbit(int res){

    int ans=0;
    int pos = 0;

    while(res) {

       if (res & 1) {
       ans = pos;
       break;
   }
       else{
           res<<1;
           pos++;
       }
   }

    return  ans;

}


int main() {


    priority_queue<int,vector<int>,greater<int> > min;

	int n;
	cin>>n;

	int a[n];

	for(int i=0; i<n; i++)
	cin>>a[i];


	int res = 0;


	for(int i=0; i<n; i++)
	res=res^a[i];


	int pos = rightmostbit(res);

	// the set bits in res indicate that those bits of the 2 single numbers are different

    // so we obtain the rightmost bit and and divide the array in 2 sets
    // one with that bit set and 1 with unset
    // both sets will contain each of the 2 numbers
	int mask =  1<<pos;


	int first=0;
	int second=0;
   // on xoring set bit set, we will be left with the single set
	// similarly on xoring the unset set, we will get the second set
	for(int i=0; i<n; i++){
	    if(a[i]&mask==1)
	    first=first^a[i];
	    else
	    	second = second^a[i];
	}


	//int second = first^res;

    min.push(first);
    min.push(second);

    while(!min.empty()){
        cout<<min.top()<<" ";
        min.pop();
    }



}
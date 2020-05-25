
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int checkpratha(int i, int r[], int l){

	int c=0;
    
    for(int i=0; i<l; i++){
        float num =float(r[i])/float(i);
        if(num<1)
        	return c;
        // cheking if it is exactly divisible
        if(num - int(num) ==0)
        c+=num; 

    }
}


int curr_time = 0;
int pratha(int p, int l, int r[],int beg, int end){
        int num=0;
        int time=0;
        

        if (beg>end){
        	return curr_time;
        }

// if we tried all chefs and coudln't complete, call the function again with revised pratahas to be made
        if(beg==end && num<p){
        	return pratha(p-num,l,r,0,l-1);
        }

        int mid = (beg+end)/2;

        for(int i=beg; i<mid; i++){
        	num+=checkpratha(i,r,mid);
        	time+=i;
        }

        // if we made all prathas, check for fewer cases

        if(num==p){
        	curr_time=time;
        	time=0;
        	return pratha(p,l,r,beg,mid-1);
        }

        // if we coudln't make, check for higher cases
        else if(num<p){
        	time=0;
        	return pratha(p,l,r,mid+1,end);
        }

}

int main(){
	
    int p,l;

    cin>>p>>l;

    int ranks[l];
    for(int i=0; i<l; i++){
    	cin>>ranks[i];
    }

    cout<<pratha(p,l,ranks,0,l-1);


	return 0;
}
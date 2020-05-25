
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

bool detect_cycle(int a[], int n){

    // a[i] contains index of next element

    if(n==1)
        return false;

    int slow=0,fast=0;

    while(fast>=0 && fast<n){

        // at each stage we have to check if slow = fast as this is not a linked list

        // fast moves 2 times, slow moves 1 time

        slow = a[slow];

        fast = a[fast];
        
        if(fast<0 || fast>n)
            return false;
        
        fast = a[fast];
        
        if(fast<0 || fast>n)
            return false;
       
        if(fast==slow)
            return true;

    }

    return false;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)cin>>a[i];

        cout<<detect_cycle(a,n)<<endl;
    }


    return 0;
}
#include<bits/stdc++.h>

using namespace std;



int min_max(stack<int>a, int n, int k){

    int max= -32767;
    int min = 32767;


    stack<int> s;
    int i=0;



    while(!a.empty() && i<k){        // making subset
        s.push(a.top());
        a.pop();
        ++i;
    }


    while(!s.empty()){

        if(s.top()<min)
            min = s.top();

        if(s.top()>max)
            max = s.top();

        s.pop();


    }


    return min+max;
}


int ans = 0;

int min_maxsum(stack<int>&s, int n, int k){

    ans = ans + min_max(s ,n , k);

   if(s.empty() || k>=s.size())
   	return ans;

        s.pop();
        min_maxsum(s,n,k);
    

   
}



int main(){

    int t;
    int n, k, a[10000];

    cin>>t;

    while(t>0){

        cin>>n;
        cin>>k;

        for(int i=0; i<n; i++)
            cin>>a[i];

        stack<int> s;

        for(int i=0; i<n; i++)
            s.push(a[i]);


        cout<<min_maxsum(s,n,k)<<endl;
        ans=0;


        --t;


    }
}


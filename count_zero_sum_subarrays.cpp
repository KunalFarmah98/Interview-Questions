#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t,n,x;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    unordered_map<int,int> m;
	    int c=0,curr_sum=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        curr_sum+=x;
	        if(curr_sum==0)
	        c++;
	        // if sum is already there, just count its occurences
	        if(m.find(curr_sum)!=m.end())
	        c+=m[curr_sum];
	        m[curr_sum]++;
	    }
	    cout<<c<<endl;
	}
	return 0;
}
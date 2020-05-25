
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin>>n;

	unordered_map<ll,int> m;
	ll presum=0;
	int length=0;
	int s=-1,e=-1;
	int a[n];

	for(int i=0; i<n; i++){	
		cin>>a[i];
		// if first ele is zero
		if(a[i]==0 && i==0) length=1;

		presum+=a[i];	
		
		// if prefix sum becomes 0, it means zero summ suaray form 0 to i;
		if(presum==0){
			if(i+1>length){
            length = i+1;
            s=0;e=i;
            }
		}
		
		// if that sum is not repeated, make an entry for the first occurrence only as we want longest
		if(m.find(presum)==m.end()){
			m[presum]=i;
		}
		// if that sum repeated, it means prev index+1 till i has a 0 sum subarray
		else{
			if((i-m[presum])>length){
                length = (i-m[presum]);
                s=m[presum]+1;
                e = i;
            }
		}
	}

	
	vector<int> ans;
    
    if(s>-1 && e>-1)
    for(int i=s; i<=e; i++)ans.push_back(a[i]);


	cout<<length<<endl;
	for(char i:ans)cout<<i;
	cout<<endl;


	return 0;
}
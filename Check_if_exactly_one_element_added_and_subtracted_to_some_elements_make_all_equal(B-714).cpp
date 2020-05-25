
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	map<int,int>diff;
	diff[a[0]] = 0;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	sort(a,a+n);
	set<int> distinct;
	for(int i=0; i<=n-2; i++){
		// if(i==n-1 && a[i]!=a[i-1])
		// 	distinct.insert(a[i]);
		if(a[i]!=a[i+1]){
			distinct.insert(a[i]);
			distinct.insert(a[i+1]);
		}
	}
	
	//cout<<distinct.size()<<endl;
	// if all equal or 2 distinct, its always possible
	if(distinct.size()==0 || distinct.size()==2){
		cout<<"YES"<<endl;
		return 0;
	}
	// atleast 4 distinct, then no
	else if(distinct.size()>=4){
		cout<<"NO"<<endl;
		return 0;
	}
	else{
		int a  = *(distinct.begin());
		distinct.erase(distinct.begin());
		int b = *(distinct.begin());
		distinct.erase(distinct.begin());
		int c=  *(distinct.begin());
		//cout<<a<<" "<<b<<" "<<c<<endl;
		if(2*b == a+c){
			cout<<"YES"<<endl;
			return 0;
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}




	return 0;
}
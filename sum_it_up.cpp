
// ques link: https://hack.codingblocks.com/contests/c/547/912
#include<bits/stdc++.h>
using namespace std;

std::vector<int> ans;
vector<vector<int> > alist;

void remove(std::vector<vector<int> > &v)
{
	auto end = v.end();
	for (auto it = v.begin(); it != end; ++it) {
		end = std::remove(it + 1, end, *it);
	}

	v.erase(end, v.end());
}


void printlist(vector<int> a){
	for(int i=0; i<a.size(); i++)
		cout<<a[i]<<" ";

	cout<<endl;

}
void sum_it_up(int a[],int n, int sum, int index){

	if(sum==0){

//		for(int i=0; i<ans.size(); i++)
//			cout<<ans[i]<<" ";
//		cout<<endl;
		alist.push_back(ans);

		return;
	}

	if(sum<0)
		return;


	for(int j=index; j<n; j++){
		sum-=a[j];
		ans.push_back(a[j]);
		sum_it_up(a,n,sum,j+1);
		sum+=a[j];//backtracking
		ans.pop_back();
	}
}


int main(){
	int n;
	cin>>n;

	int a[n];

	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	sort(a,a+n);


	int sum;
	cin>>sum;


	sum_it_up(a,n,sum,0);
	
	remove(alist);

	for(int i=0; i<alist.size(); i++){

			printlist(alist[i]);
		
		}

}
#include<iostream>
using namespace std;

int pivot(int a[], int n){

	int s=0;
	int e = n;
	int ans=-1;

	while(s<=e){
		int mid = (s+e)/2;

		if(a[mid]<a[mid-1]){
			ans=mid-1;
			return ans;
		}

		else if(a[mid]>a[mid+1]){
			ans=mid;
			return ans;
		}

		else{
			if(a[s]<a[mid]){
				s= mid+1;
			}
			else
				e=mid-1;
		}
	}

	return ans;
}


int main(){
	int a[]={6,7,8,2,3,4,5,6};
	int n = 8;

	cout<<pivot(a,n)<<endl;
}
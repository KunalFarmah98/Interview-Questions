
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<iostream>
using namespace std;

int lower_bound(int a[], int n, int key){

	int ans = -1;
	int mid;

	int s=0,e=n;

	while(s<=e){
		mid=(s+e)/2;

		if(a[mid]==key){
			ans=mid; // storing last occurrence
			e=mid-1; // searching in the left array
		}

		else if(a[mid]<n){
			s=mid+1;
		}
		else if(a[mid]>n){
			e=mid-1;
		}
	}
	
	return ans;
}

int upper_bound(int a[], int n, int key){
   
    int ans = -1;
	int mid;

	int s=0,e=n;

	while(s<=e){
		mid=(s+e)/2;

		if(a[mid]==key){
			ans=mid;  // storing last occurrence
			s=mid+1;  // searching in the right array
		}

		else if(a[mid]<n){
			s=mid+1;
		}
		else if(a[mid]>n){
			e=mid-1;
		}
	}
	
	return ans;
}

int main(){
    
    int a[]={1,2,2,2,2,4,4,7};
    int n=8;

	cout<<lower_bound(a,n,2)<<endl;
	cout<<upper_bound(a,n,2)<<endl;
	cout<<lower_bound(a,n,4)<<endl;
	cout<<upper_bound(a,n,4)<<endl;
	cout<<upper_bound(a,n,3)<<endl;
}
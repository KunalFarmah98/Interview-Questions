#include<iostream>
using namespace std;

float sq_root(int n, int p){

	float ans;
	int mid;

	int s=0,e=n;

	while(s<=e){
		mid=(s+e)/2;

		if(mid*mid==n){
			ans=mid;
			return ans;
		}

		else if(mid*mid<n){
			s=mid+1;
			ans=mid;
		}
		else if(mid*mid>n){
			e=mid-1;
		}
	}

	// fractional part;
	float inc=0.1;

  // for each decimal place starting 0.1 till the precision p
	for(int i=0; i<p; i++){
		
		while(ans*ans<n){
			ans=ans+inc;
		}
		// now ans*ans>n
		ans=ans-inc; // taking the previous value as the current one overshoots sqrt(n)
		inc/=10; // after each iteration increment will become smaller by a factor of 10, i.e 0.1, 0.01, 0.001, .....
	}

	return ans;
}


int main(){

	cout<<sq_root(10,3)<<endl;
	cout<<sq_root(49,1)<<endl;
}
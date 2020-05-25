
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int fpair(int n){

	int dp[n+1]={0};
   

	dp[0]=0;
	dp[1]=1;




for(int i=2;i<=n;i++){
	int ans1 = 1*dp[i-1];  // nth guy goes alone
	int ans2 = (n-1)*dp[i-2]; // nth guys goes ina pair from any 1 of the remaining n-2
    dp[i] += ans1+ans2;
}

return dp[n];

}

int main(){

   int n;
   cin>>n;

   cout<<fpair(n);


	return 0;
}

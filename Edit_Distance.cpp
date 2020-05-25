
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int editDistance(char s1[100], char s2[100]){

    int dp[101][101]={};   // first row and column are reserved for the words respectively
	
    int n = strlen(s1);
	int m = strlen(s2);

	//cout<<n<<m<<" ";

	

	dp[0][0] = 0;

	// setting first row
	for(int r=1; r<=n; r++){
		dp[0][r] = dp[0][r-1]+1;
	}
 
   // setting first column
	for(int c=1; c<=m; c++){
		dp[c][0] = dp[c-1][0]+1;
	}


	for(int r=1;r<=n;r++){
		for(int c=1;c<=m; c++){

			int replace = dp[r-1][c-1];
			int del = dp[r-1][c];
			int insert = dp[r][c-1];

      // if letters are same, then nothing is done else 1 operation is done so we add 1
      // != gives 1 if not equal else gives 0
			dp[r][c] = min(replace,min(insert,del)) + ((s1[r-1]!=s2[c-1]) ? 1 : 0);  
		}
	}


	return dp[n][m];
}

int main(){
  
   char s1[100],s2[100];
   cin>>s1>>s2;

   cout<<editDistance(s1,s2);	



	return 0;
}
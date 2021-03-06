#include <bits/stdc++.h> 
using namespace std; 
const int MAX_CHAR = 256; 

// for distince elements, count = nC0+nC1+nC2+....1 = 2^n

// if repetion takes place, we just remove the count of the previous subsequences generated ending 
// with that character
  
// Returns count of distinct sunsequences of str. 
int countSub(string str) 
{ 
    // Create an array to store index 
    // of last 
    vector<int> last(MAX_CHAR, -1); 
  
    // Length of input string 
    int n = str.length(); 
  
    // dp[i] is going to store count of distinct 
    // subsequences of length i. 
    int dp[n+1]={-1}; 
  
    // Empty substring has only one subsequence 
    dp[0] = 1; 
  
    // Traverse through all lengths from 1 to n. 
    for (int i=1; i<=n; i++) 
    { 
        // Number of subsequences with substring 
        // str[0..i-1] 

        // the no of subsequences doubles every iteration
        dp[i] = 2*dp[i-1]; 
  
        // If current character has appeared 
        // before, then remove all subsequences 
        // ending with previous occurrence of that letter.

        if (last[str[i-1]] != -1) 
            dp[i] = dp[i] - dp[last[str[i-1]]]; 
  
        // Mark occurrence of current character 
        // now we have marked its subsequences
        last[str[i-1]] = (i-1); 
    } 
  
    return dp[n]; 
} 


int main(){
    int t;
    cin>>t;

    while(t--){
        string a;
        cin>>a;

        cout<<countSub(a)<<endl;
    }
}
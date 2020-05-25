
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/**
Logic
Let there be a subarray (i, j) whose sum is divisible by k
  sum(i, j) = sum(0, j) - sum(0, i-1)
Sum for any subarray can be written as q*k + rem where q 
is a quotient and rem is remainder
Thus,     
    sum(i, j) = (q1 * k + rem1) - (q2 * k + rem2)
    sum(i, j) = (q1 - q2)k + rem1-rem2
     
We see, for sum(i, j) i.e. for sum of any subarray to be
divisible by k, the RHS should also be divisible by k.
(q1 - q2)k is obviously divisible by k, for (rem1-rem2) to 
follow the same, rem1 = rem2 where
    rem1 = Sum of subarray (0, j) % k
    rem2 = Sum of subarray (0, i-1) % k 

*/
// optimised O(n)
ll subCount(int arr[], int n, int k) 
{ 
    // create auxiliary hash array to count frequency 
    // of remainders 
    ll mod[k]; 
    memset(mod, 0, sizeof(mod)); 
  
    // Traverse original array and compute cumulative 
    // sum take remainder of this current cumulative 
    // sum and increase count by 1 for this remainder 
    // in mod[] array 
    ll cumSum = 0; 
    for (int i = 0; i < n; i++) { 
        cumSum += arr[i]; 
  
        // as the sum can be negative, taking modulo twice 
        mod[((cumSum % k) + k) % k]++; 
    } 
  
    ll result = 0; // Initialize result 
  
    // Traverse mod[] 
    for (int i = 0; i < k; i++) 
  
        // If there are more than one prefix subarrays 
        // with a particular mod value, we can chose 2 of them in n*(n-1)/2 ways. 
        if (mod[i] > 1) 
            result += (mod[i] * (mod[i] - 1)) / 2; 
  
    // add the elements which are divisible by k itself 
    // i.e., the elements whose modulus with k = 0 
    result += mod[0]; 
  
    return result; 
} 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
    	int n,k;
    	cin>>n>>k;
    	int a[n];
    	for(int i=0; i<n; i++){
    		cin>>a[i];
    	}
    	cout<<subCount(a,n,k)<<endl;
    }
    return 0;
}
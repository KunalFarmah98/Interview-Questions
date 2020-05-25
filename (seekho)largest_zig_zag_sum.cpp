// Memoization based C++ program to find the largest 
// sum zigzag sequence 
#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 100; 
int dp[MAX][MAX]; 

// Returns largest sum of a Zigzag sequence starting 
// from (i, j) and ending at a bottom cell and 2 consecutive elements not in same column. 
int largestZigZagSumRec(int mat[][MAX], int i, 
								int j, int n) 
{ 
if (dp[i][j] != -1) 
	return dp[i][j]; 

// If we have reached bottom, add the element
// returning that element will actually add it to the sum
if (i == n-1) 
	return (dp[i][j] = mat[i][j]); 

// Find the largest sum by considering all 
// possible next elements in sequence. 
//  we check the max possible in the next column
int zzs = 0; 
for (int k=0; k<n; k++) 
	if (k != j)   // we add it as long as it is not in the same column
	zzs = max(zzs, largestZigZagSumRec(mat, i+1, k, n)); 

// add the current element to the largest zigzag sum after it
return (dp[i][j] = (zzs + mat[i][j])); 
} 

// Returns largest possible sum of a Zizag sequence 
// starting from top and ending at bottom. 
int largestZigZag(int mat[][MAX], int n) 
{ 
memset(dp, -1, sizeof(dp)); 

// Consider all cells of top row as starting point 
int res = 0; 
for (int j=0; j<n; j++) 
	res = max(res, largestZigZagSumRec(mat, 0, j, n)); 

return res; 
} 

// Driver program to test above 
int main() 
{ 
	int n = 3; 
	int mat[][MAX] = { {4, 2, 1}, 
						{3, 9, 6}, 
						{11, 3, 15}}; 
	cout << "Largest zigzag sum: " << largestZigZag(mat, n); 
	return 0; 
} 

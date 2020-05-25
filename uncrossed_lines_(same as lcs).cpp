class Solution {
public:
    int dp[501][501];
    int solve(vector<int> a, vector<int> b, int n, int m, int ai, int bi){
        if(ai==n || bi == m)return 0;
        if(dp[ai][bi]!=-1)return dp[ai][bi];
        // once numbers match, we can't go back, we have to move forward
        if(a[ai]==b[bi])
            return dp[ai][bi] = 1+solve(a,b,n,m,ai+1,bi+1);
        // if not equal, check which index gives max on going forward aindex or bindex
        return dp[ai][bi] = max(solve(a,b,n,m,ai+1,bi), solve(a,b,n,m,ai,bi+1));
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        if(n==0 || m==0)return 0;
        memset(dp,-1,sizeof(dp));
        return solve(A,B,n,m,0,0);
    }
};
#include<bits/stdc++.h>
using namespace std;

 class SolutionDP {
 public:
     int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        int dp[rows+1][cols+1];
        memset(dp,0,sizeof(dp));
        int maxsqlen = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                // checking last cell of each square
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(min(dp[i][j - 1], min( dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                    maxsqlen = max(maxsqlen, dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        int n  = matrix.size();
        int m = matrix[0].size();
        int c=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1')++c;
            }
        }
        if(c==0)return 0;
        int maxlen=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int len=0;
               for(int k=1;k<=min(n,m);k++){
                   bool ok=true;
                   for(int x=i; x<i+k; x++){
                       if(x>=n){
                           ok = false;
                           break;
                       }
                       if(!ok)break;
                       for(int y=j; y<j+k; y++){
                           if(y>=m || matrix[x][y]=='0'){
                               ok=false;
                               break;
                           }
                        }
                    }
                   if(ok){
                       len=k;
                       maxlen=max(maxlen,len);
                   }
                }
            }
        }
        
        return maxlen*maxlen;
    }
    
};

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char> > mat;
    for(int i=0; i<n; i++) {
        vector<char> c;
        for (int j = 0; j < m; j++){
            char ch;
            cin>>ch;
            c.push_back(ch);
        }
        mat.push_back(c);
    }

    Solution s;
    cout<<s.maximalSquare(mat);
}
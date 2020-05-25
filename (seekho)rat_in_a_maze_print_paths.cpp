#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
	int m[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}
	
	vector<string> res = printPath(m,n);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */
void ratInaMaze(int m[MAX][MAX], int n, int r, int c, vector<string> &v, string s){

	// checking bounds and blocked cells
    if(r>=n||r<0||c>=n||c<0||m[r][c]==0||m[r][c]==-1) 
    return;
    
    if(r==n-1 && c==n-1){
        v.push_back(s);
        return;
    }
    // as string is passed by value, no need to backtrack it
    // only backtrack visited
    // marking as visited
    m[r][c]=-1;
    ratInaMaze(m,n,r+1,c,v,s+'D');
    ratInaMaze(m,n,r,c+1,v,s+'R');
    ratInaMaze(m,n,r-1,c,v,s+'U');
    ratInaMaze(m,n,r,c-1,v,s+'L');
    //marking as unvisited
    m[r][c]=1;
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    int r=0,c=0;
    vector<string> v;
    string s="";
    ratInaMaze(m,n,r,c,v,s);
    sort(v.begin(), v.end());
    return v;
}
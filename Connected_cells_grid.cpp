
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

void regions(int mat[10][10], int n, int m, int x, int y, bool visited[10][10], int len, set<int> &lengths){
    if(x==n && y==m) {
        if(mat[x-1][y-1]==1)
            lengths.insert(len);
        
        return;
    }
    if(visited[x][y] || mat[x+1][y]==0 && mat[x][y+1]==0 && mat[x+1][y+1]==0 && mat[x-1][y-1]==0 && mat[x+1][y-1]==0
        && mat[x-1][y+1]==0 && mat[x-1][y]==0 && mat[x][y-1]==0){
        lengths.insert(len);
        return;
    }

    visited[x][y]=true;
    regions(mat,n,m,x+1,y,visited,len+1,lengths);
    regions(mat,n,m,x,y+1,visited,len+1,lengths); 
    regions(mat,n,m,x-1,y,visited,len+1,lengths); 
    regions(mat,n,m,x,y-1,visited,len+1,lengths); 
    regions(mat,n,m,x+1,y+1,visited,len+1,lengths); 
    regions(mat,n,m,x+1,y-1,visited,len+1,lengths); 
    regions(mat,n,m,x-1,y+1,visited,len+1,lengths); 
    regions(mat,n,m,x-1,y-1,visited,len+1,lengths); 

}

void dfs(map<pair<int,int>,vector<pair<int,int> > >g, pair<int,int> src, bool visited[10][10], int &len){
    visited[src.first][src.second]=true;
    for(auto nbr: g[src]){
        if(!visited[nbr.first][nbr.second]){
            visited[nbr.first][nbr.second]=true;
            ++len;
            dfs(g,nbr,visited,len);
        }
    }
}

int maxregion(int mat[10][10], int n, int m, map<pair<int,int>,vector<pair<int,int> > >g, vector<pair<int,int> > ind){
    int maxval = INT_MIN;
    bool visited[10][10];
    

    for(auto i : ind){
        memset(visited,false,sizeof(visited));
        int len=1;
        dfs(g,i,visited,len);
        //regions(mat,n,m,i.first,i.second,visited,len,lengths);
        maxval=max(maxval,len);
    }

    return maxval;
}

int main(){
    int n,m;
    cin>>n>>m;

    int mat[10][10];
    vector<pair<int,int> > ind;
    map<pair<int,int>,vector<pair<int,int> > >g;
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            int x;
            cin>>x;
            mat[i][j]=x;
            if(x==1){
                ind.push_back({i,j});
                if(i-1>=0 && mat[i-1][j]==1){
                    g[{i-1,j}].push_back({i,j});
                    g[{i,j}].push_back({i-1,j});
                }
                if(j-1>=0 && mat[i][j-1]==1){
                    g[{i,j-1}].push_back({i,j});
                    g[{i,j}].push_back({i,j-1});
                }
                if(i-1>=0 && j-1>=0 && mat[i-1][j-1]==1){
                    g[{i-1,j-1}].push_back({i,j});
                    g[{i,j}].push_back({i-1,j-1});
                }
                if(i-1>=0 && j+1<n && mat[i-1][j+1]==1){
                    g[{i-1,j+1}].push_back({i,j});
                    g[{i,j}].push_back({i-1,j+1});
                }
            }
        }
    }


    cout<<maxregion(mat,n,m,g,ind)<<endl;



    return 0;
}
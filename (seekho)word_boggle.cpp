#include <bits/stdc++.h>
using namespace std;

set<string>ans;
int maxlen = INT_MIN;


bool check(string word, vector<string>dict, int &index){
    int n = dict.size();
    for(int i=0; i<n; i++){
        if(dict[i].compare(word)==0){
            index=i;
            return true;
        }
    }

    return false;
}


void matcher(vector<string> dict, char boggle[7][7] , int n, int m, int i, int j , string &word, int visited[7][7]){

// bounds check and visited check 
    if(i>=n || i<0 || j>=m || j<0 || visited[i][j]==1)
        return;


    int index = -1;

// if word reaches maxlength and stil not valid, stop recursing
    if(word.length()==maxlen && !check(word,dict,index))
        return;
    
    visited[i][j]=1;
    word.push_back(boggle[i][j]);

    if(check(word,dict,index)){
        ans.insert(word);
        // removing all occurrences to avoid duplicate matching
        dict.erase(std::remove(dict.begin(), dict.end(), dict[index]), dict.end());
        //cout<<word<<" ";
        return;
    }


    matcher(dict,boggle,n,m,i+1,j,word,visited);

    matcher(dict,boggle,n,m,i-1,j,word,visited);

    matcher(dict,boggle,n,m,i,j+1,word,visited);

    matcher(dict,boggle,n,m,i,j-1,word,visited);

    matcher(dict,boggle,n,m,i+1,j-1,word,visited);

    matcher(dict,boggle,n,m,i+1,j+1,word,visited);

    matcher(dict,boggle,n,m,i-1,j+1,word,visited);

    matcher(dict,boggle,n,m,i-1,j-1,word,visited);


    word.pop_back();
    visited[i][j]=0;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int s,n, m = 0;
        cin>>s;

        vector<string>dict;

        for(int i=0; i<s; i++){
            string a;
            cin>>a;
            int l = a.length();
            maxlen = max(maxlen,l);
            dict.push_back(a);
        }

        cin>>n>>m;


        char boggle[7][7];

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>boggle[i][j];


        string word="";
        int visited[7][7];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                visited[i][j]=false;

            // we need to call for each and every element in boggle

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                matcher(dict,boggle,n,m,i,j,word,visited);

         if(ans.size()==0){
         cout<<-1<<endl;
         continue;
         }
        for(auto i : ans)
            cout<<i<<" ";

        ans.clear();
        cout<<endl;
    }
    return 0;
}
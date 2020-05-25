#include<bits/stdc++.h>
using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define mx 200001
int s[mx + 1];
int rank[mx + 1];
int a[mx + 1];
void build_rank(int n){
    for (int i=0;i<n;i++) {
        if (i==0) {
            ::rank[i] = 1;
        }
        else {
            if (s[i] == s[i-1]) {
                ::rank[i] = ::rank[i - 1];
            }
            else {
                ::rank[i] = ::rank[i - 1] + 1 ;
            }
        }
    }
}

int main(){

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    build_rank(n);
    

    int m;
    int point = n;
    cin >> m;
    for (int j = 0; j < m; j++) {
        cin >> a[j];
    }
    
    for(int j = 0; j < m; j++) {
        
        int current_rank;
        // finding index of possible insertion
        while (point >= 0 and a[j] > s[point]) {
            point--;
        }
        // if it goes beyond the largest score,then rank is 1
        if (point == -1) {
            current_rank = 1;
        }
        // if score is already present, rank is same
        else if (a[j] == s[point]) {
            current_rank = ::rank[point];
        }
        // if current ind score is greater, our rank is greater by 1
        else if (a[j] < s[point]) {
            current_rank = ::rank[point] + 1;
        }
        
        cout << current_rank << endl;
    }
    
    return 0;
}
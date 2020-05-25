
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;

    while(t--){
    ll n,m;
    cin>>n>>m;

    ll a[n];
    ll prefix=0;
    ll max_=0;



    for(ll i=0; i<n; i++){
        cin>>a[i];
    }

    // set to hold all prefix sums in inc order so that we can find the one greater and 
    //closest to current one 
    set<ll> s;
    // first prefix is 0
    s.insert(0);
    for(ll i=0; i<n; i++){
        ll prefix = (prefix+a[i])%m;
        max_=max(max_,prefix);
    
        // finding a prefix sum greater and closest to the current prefix sum

        // correct syntax for lowerbound for set and fastest one
        auto it = s.lower_bound(prefix+1);
        if(it!=s.end())
            // modulo sum is the max sum ending at i 
            // (which is sum till i- greater sum closest to the current sum till i)
            max_ = max(max_,prefix-*(it)+m);
    
        s.insert(prefix);
    }

    cout<<max_<<endl;
    }

    return 0;
}

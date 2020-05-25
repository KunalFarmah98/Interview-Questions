
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool check(ll nPainters, vector<ll>& L, ll guess){
    ll curPainter = 1;
    ll curLen = 0;
    
    for(auto board: L){
    	// for every value, check if the crrent painter can paint the board
        if (board + curLen <= guess){
            curLen += board;
        }
        // if not, use the next painter and stop if we have used all present
        else {
            ++curPainter;
            if (curPainter > nPainters || board > guess){
                return false;
            }
            // current length to be painted is the current number now as the new painter starts afresh
            curLen = board;
        }
    }
    return true;
}

ll partition(ll N, ll k, vector<ll> &L) {
    
    ll low = 0; // min boards to be painted are 0, hence min time is 0

    ll high = accumulate(L.begin(), L.end(), 0); // max time can be sum of all board lengths,
    // hence max possible time is that
    
    ll ans = high;
    
    while(low <= high){
        ll guess = (low + high) / 2;
        if (check(k, L, guess)){
            ans = guess;
            // if we succeed, we check for a lower time
            high = guess - 1;
        }
        else {
        	// if we fail, we need to go higher
            low = guess + 1;
        }
    }
   return ans;
}


int main(){
	
	ll n,k;
	cin>>k>>n;

	vector<ll> a;

	for(ll i=0; i<n; i++){
		ll x;
		cin>>x;
		a.push_back(x);
	}

		cout<<partition(n,k,a)<<endl;



	return 0;
}
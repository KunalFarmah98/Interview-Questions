    // Kunal Farmah
	// kunalfarmah98@gmail.com
	
	#include <bits/stdc++.h>
	using namespace std;

	#define RTIME ((double)clock()/(double)CLOCKS_PER_SEC)
	#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	#define Mod 1000000007
	
	typedef long long int ll;
	typedef unsigned long long int ull;
	typedef long double ld;
	typedef pair < int, int > pii;
	typedef pair < ll, ll > pll;
	typedef vector<int> vi;
	typedef vector<vi> vvi;
	typedef vector<bool> vb;
	typedef queue<int> qi;
	typedef complex<double> base;
	
	const ld pi = 3.141592653589793238462643383; 
	const double PI = 3.141592653589793;
	
	template<class T>
	using max_pq = priority_queue<T>;
	template<class T>
	using min_pq = priority_queue<T,vector<T>,greater<T>>; 
	
	
	vector<bool> primeSieve(int n){
	    std::vector<bool> p(n+1,false);
		p[0]=p[1]=0;
		p[2]=1;
	    for(int i=3;i<=n;i+=2){
	        p[i] = 1;
	    }
	    for(int i=3;i<=sqrt(n);i+=2){
	        if(p[i]){
	            for(int j=i*i;j<=n;j+=2*i){
	                p[j] = 0;
	            }
	        }
	    }
	    return p;
	}
	
	ll power(ll x, ll y, ll m){
		if(y==0)
			return 1;
		ll smallpower = power(x,y/2,m);
		smallpower = smallpower%m;
		smallpower = (smallpower*smallpower)%m;
		if(y&1)
	         return (x*smallpower)%m;
		else
			return (smallpower%m);
	}
	
	
	
	int main(){
		IOS;
		#ifndef ONLINE_JUDGE
   			freopen("in.txt", "r", stdin);
    		freopen("out.txt", "w", stdout);
		#endif
		

		int t;
		cin>>t;
		while(t--){
			int n,q;
			cin>>n>>q;
			int cf=0;
			int c=0;
			while(q--){
			
				int f,d;
				cin>>f>>d;
				c+=abs(cf-f);
				c+=abs(f-d);
				cf=d;
			}
			cout<<c<<endl;
		}
	
		return 0;
	}
#include<bits/stdc++.h>
using namespace std;


 int maxval = -1E9;




// O(n)  USING SET

 /*int andxoror(set<long int>&s1 ){

	if(s1.size()==1)
		return maxval;

	set< int> :: iterator it = s1.begin();
	set< int> :: iterator it2 = ++it;
	--it;


	 int ans = (((*it & *(it2)) ^ (*it | *(it2))) & *it ^ *(it2));



	if(ans>maxval)
		maxval=ans;

	s1.erase(it);



	andxoror(s1);

}*/


// USING STACK
/*
int and_xor_or(vector<int>a) {

	stack<int>s;
	s.push(a[0]);

	for (int i = 1; i < a.size(); i++) {

		while (!s.empty()) {

			if (s.top() >= a[i]) {          // if stack has a greater element it can't form smaller pair with any other than that element of the array

				int ans = (((s.top() & a[i]) ^ (s.top() | a[i])) & s.top() ^ a[i]);
				s.pop();

				if (ans > maxval)
					maxval = ans;
			}

			else
				break;

		}
		s.push(a[i]);
	}

	return maxval;
}
*/

 void solve(vector<int>a,int n) {

    stack<int> s;

    int result = INT_MIN, cur;

    for (int i = 0; i < n; ++ i) {
       while (!s.empty() && s.top() >= a[i]) {

          int tmp = s.top(); s.pop();
          result = max(result, tmp ^ a[i]);
       }

       if (!s.empty()) result = max(result, a[i] ^ s.top());
       s.push(a[i]);
    }

    cout<< result;
}


//int maxval = -1E9;

/*int andxoror(vector<int> v){

	if(v.size()==1)
		return maxval;

set<int>s;

	for(int i=0; i<v.size(); ++i)
    s.insert(v[i]);


    set< int> :: iterator it = s.begin();
	set< int> :: iterator it2 = ++it;

	--it;


	 int ans = (((*it & *(it2)) ^ (*it | *(it2))) & *it ^ *(it2));


	if(ans>maxval)
		maxval = ans;

	s.clear();

	v.pop_back();

	andxoror(v);

	return maxval;


}*/





 int main() {

	 int n;
	vector< int>v;
	cin >> n;
	v.resize(n);



	for ( int i = 0; i < n; i++)
		cin >> v[i];

	solve(v,n);


	// cout << and_xor_or(v);


	// cin>>n;

	// set<int>s1;


	// for(long  int i=0; i<n; i++){
	// 	 int x;
	// 	cin>>x;
	// 	s1.insert(x);


	// }

	// cout<<andxoror(s1);



}
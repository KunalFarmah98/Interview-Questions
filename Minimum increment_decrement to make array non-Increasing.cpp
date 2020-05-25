// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long


 // } Driver Code Ends
ll Compute(ll *a, ll n) 
{ 
    ll sum = 0, dif = 0; 
  	// keep a min heap and compare every element with the smallest
  	// so far as it has to be smaller/equal than that to keep 
  	// it non increasing
    
    priority_queue<ll, vector<ll>, greater<ll> > pq; 
  
    for (ll i = 0; i < n; i++) { 
    	// if we find a larger element at any time, we need to reduce it
        if (!pq.empty() && pq.top() < a[i]) { 
            dif = a[i] - pq.top(); 
            sum += dif; 
            pq.pop(); 
            pq.push(a[i]); 
        } 
        pq.push(a[i]); 
    } 
  
    return sum; 
} 
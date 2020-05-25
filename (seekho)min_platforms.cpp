#include <bits/stdc++.h>
using namespace std;

// just increasea  platform if the next event in order is an arrival and dedice if its a departure
int findPlatform(int arr[], int dep[], int n) 
{ 
    // Insert all the times (arr. and dep.) 
    // in the multimap. 
    multimap<int, char> order; 
    for (int i = 0; i < n; i++) { 
  
        // If its arrival then second value 
        // of pair is 'a' else 'd' 
        order.insert(make_pair(arr[i], 'a')); 
        order.insert(make_pair(dep[i], 'd')); 
    } 
  
    int result = 0; 
    int plat_needed = 0; 
  
    multimap<int, char>::iterator it = order.begin(); 
  
    // Start iterating the multimap. 
    for (; it != order.end(); it++) { 
  
        // If its 'a' then add 1 to plat_needed 
        // else minus 1 from plat_needed. 
        if ((*it).second == 'a') 
            plat_needed++; 
        else
            plat_needed--; 
  
        if (plat_needed>result) 
            result = plat_needed; 
    } 
    return result; 
} 

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    int dept[n];
	    map<int,int> trains;
	    
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    
	    for(int i=0; i<n; i++){
	        cin>>dept[i];
	        //trains.insert(make_pair(arr[i],dept[i]));
	    }
	    
	    cout<<findPlatform(arr,dept,n)<<endl;
	}
	return 0;
}
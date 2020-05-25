#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> count_zero_sum_subarrays(int a[],int n){
    
    // ans vector stores start and end of the zero sum subarray
    vector<pair<int,int> >ans;
    
    // map will store starting indices of a given sum
    unordered_map<int,vector<int> >m;
    
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];

     // if we get sum as zero it means there is an array from 0 to i summing to 0
        if(sum==0){
            ans.push_back({0,i});
        }
        
        // if we get a sum that has already been found once,
        // it means the subarray between those 2 indices  has zero sum
        // map[sum] has a vector of the index at which that sum was found
        // the index of the subarray would start from 1 + the index of its last occurence 
        // and end at i
        
        if(m.find(sum)!=m.end()){
            // getting all occurences of sum
            vector<int> temp = m[sum];
            //subarray starts from prev val of m[sum]+1 and ends at i
            int l = temp.size();
            // for(auto val : temp){
            //       ans.push_back({sum,val+1});
            // }
            for(int j=0; j<l; j++){
                ans.push_back({temp[j]+1,i});
            }
        }
        
        // we push all occurrences of given sum in map[sum]
        
        m[sum].push_back(i);
    }
    
    return ans;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    int a[n];
	    for(int i=0; i<n; i++){
	        cin>>a[i];
	    }
	    
	    vector<pair<int,int> > ans = count_zero_sum_subarrays(a,n);
        // do whatever u want
	}
	return 0;
}
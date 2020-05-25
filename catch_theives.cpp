// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
int catchThieves(char arr[], int n, int k) ;

// } Driver Code Ends
//User function Template for C++

int catchThieves(char arr[], int n, int k)
{
    int res = 0; 
    vector<int> thi; 
    vector<int> pol; 
  
    // store indices in the vector 
    for (int i = 0; i < n; i++) { 
        if (arr[i] == 'P') 
            pol.push_back(i); 
        else if (arr[i] == 'T') 
            thi.push_back(i); 
    }    
  
    // track lowest current indices of 
    // thief: thi[l], police: pol[r] 
    int l = 0, r = 0; 
    while (l < thi.size() && r < pol.size()) { 
  
        // can be caught 
        if (abs(thi[l] - pol[r]) <= k) { 
            res++; 
            l++; 
            r++; 
        } 
  
        // increment the minimum index 
        else if (thi[l] < pol[r]) 
            l++; 
        else
            r++; 
    } 
  
    return res;  
   /* int t=0;
    int ans=0;
    for(int i=0; i<n; i++){
        if(arr[i]=='T')++t;
        if(arr[i]=='P'){
            if(t>0){
                // if there are thiefs behind, catch the farthest one
                for(int j=max(0,i-k); j<i; j++){
                    if(arr[j]=='T'){
                        --t;
                        arr[j]='0';
                        ans++;
                        break;
                    }
                }
            }
            // if no thief is left behind, catch the farthest in front
            else{
                for(int j=min(n-1,i+k); j>i; j--){
                    if(arr[j]=='T'){
                        ++ans;
                        arr[j]='0';
                        break;
                    }
                }
            }
        }
    }

    return ans;*/
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n >> k;
        char arr[n];
        for (int i = 0; i < n; ++i)
            cin>>arr[i];
        cout<<catchThieves(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;

/*
  O((n+m)log(n+m))
*/

/*
The idea: we start comparing elements that are far from each other rather than adjacent.
For every pass, we calculate the gap and compare the elements towards the right of the gap.
 Every pass, the gap reduces to the ceiling value of dividing by 2.
 */

int nextGap(int gap) 
{ 
    if (gap <= 1) 
        return 0; 
    // ceil value of gap/2
    return (gap / 2) + (gap % 2); 
}

void merge(int *arr1, int *arr2, int n, int m) 
{ 
    int i, j, gap = n + m; 
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    { 
        // comparing elements in the first array at the given gap and swapping. 
        for (i = 0; i + gap < n; i++) 
            if (arr1[i] > arr1[i + gap]) 
                swap(arr1[i], arr1[i + gap]); 
  
        //comparing elements in both arrays. 
            // crossing compare

            // if gap>n, then we need to start from gap-n (as the other element at the gap
             // may be in the second array but not at its begining) else we can start form 0

        for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++) 
            // finding the other crossing element at the given gap
            if (arr1[i] > arr2[j]) 
                swap(arr1[i], arr2[j]); 
  
       // if any element is left then compare the elements in second array in same way as the first array
        if (j < m) 
        { 
            //comparing elements in the second array. 
            for (j = 0; j + gap < m; j++) 
                if (arr2[j] > arr2[j + gap]) 
                    swap(arr2[j], arr2[j + gap]); 
        } 
    } 
} 

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    
	    int a[n],b[m];
	    
	    for(int i=0; i<n; i++) cin>>a[i];
	    for(int i=0; i<m; i++) cin>>b[i];
	    
	    merge(a,b,n,m);
	    
	    for(int i=0; i<n; i++) cout<<a[i]<<" ";
	    for(int i=0; i<m; i++)  cout<<b[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
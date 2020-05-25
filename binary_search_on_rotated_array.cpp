#include<iostream>
using namespace std;

int actual_beg(int a[], int beg, int end){
    while(a[beg]>=a[end]){
        beg++;
    }
    
    return beg;
}

int bin_search(int a[], int beg, int end, int val){
    
    int mid = beg+end/2;

    // we know the actual begining index, so if mid goes beyond end, 
    // restart counting from 0,
    // in 4 5 1 2 3
    // any value >4 = value-end
    
    
    if(mid>end)
    mid = mid-end;
    
    
    
    if(a[mid]==val)
    return mid;
    
    if(beg>end)
    return -1;
    
    if(a[mid]<val)
    return bin_search(a,beg,mid-1,val);
    else
    return bin_search(a,mid+1,end,val);
    
}
// complexity of this program is O(klog(n)) where k is the index at which the array is rotated



// Search an element in sorted and rotated 
// array using single pass of Binary Search 

// Returns index of key in arr[l..h] if  
// key is present, otherwise returns -1 
int search(int arr[], int l, int h, int key) 
{ 
    if (l > h) return -1; 
  
    int mid = (l+h)/2; 
    if (arr[mid] == key) return mid; 
  
    /* If arr[l...mid] is sorted */
    // it will be sorted if arr[l]<=arr[mid] as elements to left and right of pivot are sorted
    if (arr[l] <= arr[mid]) 
        // this means array to the left of mid is sorted for sure
    { 
        /* As this subarray is sorted, we can quickly 
        check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid]) 
        return search(arr, l, mid-1, key); // if key actually lies in the left most array which is sorted
        else
        return search(arr, mid+1, h, key);   // otherwise search in the right part
    } 
  
    /* If arr[l..mid] is not sorted, then arr[mid... r] 
    must be sorted as this array was initially sorted*/

    if (key >= arr[mid] && key <= arr[h]) //if key lies the rightmost sorted part of the right subarray
        return search(arr, mid+1, h, key); 
  
    return search(arr, l, mid-1, key); //  otherwise search in the left part
} 

// complexity is O(logn)
  

int main() {
    
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0; i<n; i++){
    cin>>a[i];
    }
    
   // int beg = actual_beg(a,0,n-1);
    
    int val;
    cin>>val;
    
    //cout<<bin_search(a,beg,n-1,val);
    cout<<bin_search(a,0,n-1,val);

	return 0;
}
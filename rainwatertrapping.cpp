#include<bits/stdc++.h>

using namespace std;


void inputVec(vector<long int>& v){
    for(long int i = 0; i < v.size(); ++i){
        cin >> v[i];
    }
}


//buggy code


/*long int nonzer0(vector<long int> a, long int n){
    long int i;

    //finding first non zero element
    for( i=0; i<n; i++){
        if(a[i]!=0);
        break;
    }

    return i;

}

// function to check if a greater wall exists further in the input
bool check(vector<long int> a, long int n, long int index){


        for(long int j = index+1; j<n; ){
            if(a[j]>=a[index])
                return true;
            else
                ++j;
        }

    return false;
}


long int ans =0;

long int rainwatertrapping(vector<long int> a, long int n, long int i){


    static long int j=0;

    if(j==n || i==n)
        return ans;

    if(check(a,n,i)){    // checking if greater is present or else check for the next index as current one is useless


        // calculating water stored till just greater height tower comes
        for( j=i+1; j<n; j++){

            if(a[j]<=a[i]){
                ans = ans + (a[i]-a[j]);
            }

            if(a[j]>=a[i])
                break;
        }

        i=j;


        rainwatertrapping(a,n,j);
    }


    else{
        ++i;     // incrementing index
        rainwatertrapping(a,n,i);

    }


    return ans;
}
*/


int findWater(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];
 
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];
 
    // Initialize result
    int water = 0;
 
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
       left[i] = max(left[i-1], arr[i]);  // apne se peeche wale ki max height dekhi for each element
 
    // Fill right array
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
       right[i] = max(right[i+1], arr[i]);   // apne se age ki max height dekhi for each element
 
    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
       water += min(left[i],right[i]) - arr[i];   // the smaller of hte 2 heights give us the answer
 
    return water;
}



/*// we find the height bar on the left and right of hte current position and calculate the answer accordingly
// space optimised

long int findWateroptimised(vector<long int> arr, long int n)
{
    // initialize output
    long int result = 0;
     
    // maximum element on left and right
    long int left_max = 0, right_max = 0;
     
    // indices to traverse the array
    long int lo = 0, hi = n-1;
     
    while(lo <= hi) 
    {
        if(arr[lo] < arr[hi])    // if there are big towers after the current computation will take place from left
        {
            if(arr[lo] > left_max)
            // update max in left
            left_max = arr[lo];    // setting left max for the current element
            else
            // water on curr element = max - curr
            result += left_max - arr[lo];
            lo++;
        }
        else
        {
            if(arr[hi] > right_max)   // if htere are smaller towers after the current, the computaion takes place from right
            // update right maximum
            right_max = arr[hi];   // setting right max for the current element
            else
            result += right_max - arr[hi];
            hi--;
        }
    }
     
    return result;
}*/


 int main(){

    long int t;
    long int n;
    vector<long int> a;

    cin>>t;

    while(t>0){

        
        cin >> n;
        a.resize(n);
        inputVec(a);

        // long int index =nonzer0(a,n);  // we start from the first non zero element


        // cout<<rainwatertrapping(a,n,index);
        cout<<findWater(a,n);
        cout<<endl;
        // ans=0;

        --t;


    }
}
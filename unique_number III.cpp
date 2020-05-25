#include<bits/stdc++.h>
using namespace std;

int unique_numIII(int a[], int n){


	int cnt[64] = {0};

   for(int i=0; i<n; i++){

   	int index =0;
     int no = a[i];

   	while(no>0){
      cnt[index]+=(no&1);    // 1 at nth position will contribute 1 and 0 will contribute 0
      index++;
      no = no>>1;   // right shifting to see other bits;
   	}
   }


   // binary to decimal conversion

   	int ans=0;
   	int p=1;

   for(int i=0; i<64; i++){
	cnt[i]%=3;                      // mod 3 will remove all the bits conrtibuted by repeated numbers 
    ans += cnt[i]*p;                    // 0    1    0
                                       // 2^0 2^1 2^0
    // jo end me bchega whi unique number hoga
    p=p<<1;   // (p=p*2);

    }

   return ans;


}


// With O(1)space

/*int getSingle(int arr[], int n) 
{ 
    // Initialize result 
    int result = 0; 
  
    int x, sum; 
  
    // Iterate through every bit 
    for (int i = 0; i < INT_SIZE; i++) 
    { 
      // Find sum of set bits at ith position in all 
      // array elements 
      sum = 0; 
      x = (1 << i);    

      /// taking sum of xth bits in all the numbers and then cahnging x to its left (x = 1<<i till 32 or 64 bits are read)

      for (int j=0; j< n; j++ ) 
      { 
      	//this will sum the xth bits in all the numbers
          if (arr[j] & x) 
            sum++; 
            
      } 
  

   /// this statement will make the result as the xth bit in the question

      // The bits with sum not multiple of 3, are the 
      // bits of element with single occurrence. 
     
      if (sum % 3) 
        result |= x; 

    } 
  
    return result; 
} */



int main(){

	int n;
	cin>>n;


	int a[n];

	for(int i=0; i<n; i++)
		cin>>a[i];


	cout<<unique_numIII(a,n)<<endl;
	//cout<<getSingle(a,n)<<endl;
}
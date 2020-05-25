
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll largest(ll a[], ll n){
 
stack<ll> s;
ll max_area = INT_MIN;
ll top;
ll area = 0;

ll i=0;
	while(i<n){
		// is stack is empty or the current element is greater than the prev pushed element
          if(s.empty() || a[s.top()] <= a[i]){
          	s.push(i++);
      }

          else{
        		// remove all heights greater than current
          		top = s.top();
          		s.pop();
          		// if stack is empty, it means the val is the smallest val in the array
          		// hence max area is length of array so far * val
          		
          		// we consider the freshly removed element as the smallest height
          		if(s.empty()){
                  area  = a[top]*i;
          		}
          		// at this point we would have reached one index after the largest value is
          		// encountered ( so we do i-1 in length of the rectange)
          		// it is adjusteed by the index just pushed before the largest as it will
          		// combine with the same height in the largest to form the max area

          		// stack top would be having a value less than the current and the maxarea for
          		// that would have height =  the lesser value   (top of stack)  left smaller
          		// i would denote the right smaller
          		// that would have length = i-the val at top(i.e index of the in between element that
          		// adjusts the length) -1

          		// length =  rightmost smallest - leftmost smallest  - 1
          		//					(i)              s.top()
          		
          		else{
          			area = a[top]*(i-s.top()-1);
          		}

          		 // update max area, if needed 
            if (max_area < area) 
                max_area = area; 
          }
          
	}


          //empty the remaining stack and find the area

          while(s.empty()==false){

          		top = s.top();
          		s.pop();
          		
          		if(s.empty()){
                  area  = a[top]*i;
          		}
          		else{
          			area = a[top]*(i-1-s.top());
          		}

          	 // update max area, if needed 
            if (max_area < area) 
                max_area = area; 
          }

	return max_area;
}

int main(){
	
    ll t;
    cin>>t;

    while(t--){
    	ll n;
    	cin>>n;

    	ll a[n];
    	for(ll i=0; i<n; i++){
    		cin>>a[i];
    	}

    	cout<<largest(a,n)<<endl;
    }


	return 0;
}
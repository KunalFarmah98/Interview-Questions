#include <iostream>
using namespace std;
typedef long long ll; 

//bhaiya wala code
/*bool isValidConfig(ll books[], ll n, ll m, ll ans){

  int students=1;

  ll current_pages=0;

  for(int i=0; i<n; i++){

  	// if we overshoot the upper bound, we increment the no of students and restore the 
  	//current pages read toteh previous value

if(current_pages + books[i] > ans ){
	current_pages=books[i];
	students++;
	// if no of students exceeds the limit, then it is not a valid config
if(students>m)
	return false;
}

else{
	// we keep on reading the pages
  	current_pages += books[i];
  }
}

return true;

}


ll binary_search(ll books[], ll n, ll m){

  ll total_pages=0;
  ll s=0,e=0;
  for(int i=0; i<n; i++){
  	total_pages+=books[i];
  	s=max(s,books[i]);
  }

  // start from he last element as no ans can be less than the max no of pages in question

  e=total_pages;
  ll finalans=0;

  while(s<=e){
  	
  	ll mid = (s+e)/2;

  	if(isValidConfig(books,n,m,mid)){
  		// if a configuration is valid, update the ans and try to search for one in the left side 
       finalans = mid;
       e= mid-1;
  	}

  	else{
  		// if config is not valid, search in the right part
        s = mid+1;
  	}
  }

return finalans;


}*/

// my code 
ll sum (ll a[], ll n){
	ll s=0;
	for(int i=0; i<n; i++){
		s+=a[i];
	}
	return s;
}

ll book_allocation(ll a[], ll n, ll m){

	ll min = a[n-1];
	// ans can't be less than the lasrgest value in the array
	ll s=min;
	ll max = sum(a,n);
	ll e = max;
	ll ans=0;
	ll possible_ans=0;


	while(s<=e){
		int f=0;
		int students=1;
		ll mid = (s+e)/2;
		//int possible_ans = upper_bound_pages[mid];
	 possible_ans = mid;

		ll pages_read=0;
		// read  pages until we overshoot upperbound
		for(int i=0; i<n; i++){
	    pages_read += a[i];
	    //if we overshoot, increment no of students and repeat from second last case
	    if(pages_read>possible_ans){
	        // now the new student will read the previously read pages that overshot the nas
	    	pages_read=a[i];
	        students++;
	        // if no of students exceed m, search in the right and break this for loop
	        if(students>m){
	        	s= mid+1;
	        	f=1;
	        	break;
	        }
	    }

	 }

  // if the pages_read didn't overshoot our ans, then try to search in left side
	if(f==0) {
		e = mid - 1;
	    ans=possible_ans;
	}
	
     
}



return ans;
}




int main(){
	ll n,m;
	cin>>n>>m;
	 ll a[n];
	 for(int i=0; i<n; i++) {
	 	cin>>a[i];
	 }

	 	cout<<book_allocation(a,n,m)<<endl;
	 // cout<<binary_search(a,n,m)<<endl;
}
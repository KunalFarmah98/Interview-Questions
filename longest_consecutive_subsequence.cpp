
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

// O(maxelement-minelement) > O(n) apporach

/*int lcsuseq(vector<int> nums, int n){
	 if(n==0)return 0;
        
        int min_ = *min_element(nums.begin(),nums.end());
        int max_ = *max_element(nums.begin(),nums.end());
        
        //cout<<min_<<" "<<max_<<endl;
        
        unordered_map<int,int> m;
        
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        
        int len=0,maxlen=1;
        for(int i=min_; i<=max_; i++){
            if(m[i]>0)
                ++len;
            else{
                
                len=0;
            }
            maxlen=max(maxlen,len);
        }

        return maxlen;
       
}*/


// O(n) approach
int lcsuseq(vector<int> a, int n){
	if(n==0)return 0;

	unordered_set<int> s;
	for(int i:a){
		s.insert(i);
	}

	int maxlen=1,len=0;
	int LB=0,RB=0,lb,rb;
	for(int i=0; i<n; i++){
		// if a[i]-1 is not present, then a[i] is one LB for some streak
		if(s.find(a[i]-1)==s.end()){
			len=0;
			// find the right boundary for the streak bounded by LB
			int j = a[i];
			lb=j;
			while(s.find(j)!=s.end()){
				++len;
				++j;
			}
			rb = j;
		}

		if(len>maxlen){
			maxlen=len;
			LB=lb;
			RB=rb;
		}
	}

	for(int i=LB; i<=RB; i++)cout<<i<<" ";
	cout<<endl;
	return maxlen;
}

int main(){


	 int n;
	 cin>>n;

	 vector<int> a(n);
	 for(int i=0; i<n; i++){
	 	cin>>a[i];
	 } 

	 cout<<lcsuseq(a,n)<<endl;


      
	return 0;
}
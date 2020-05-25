class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
    unordered_map<int,int> m;
	int presum=0;
	int length=0;
	int s=-1,e=-1;
    int n = a.size();
    int count=0;
	for(int i=0; i<n; i++){	
		
		// if first ele is k
		if(a[i]==k){
			
		if(length==0)
			length=1;
			
		++count;
		} 

		presum+=a[i];	
		
		// if prefix sum becomes k, it means k sum suaray form 0 to i;
		if(presum==k){
            ++count;
			if(i+1>length){
            length = i+1;
            s=0;e=i;
            }
		}
		// if presum wasn't present, make an entry
		if(m.find(presum)==m.end()){
			m[presum]=i;
		}
		// if sum-k is repeated, it means prev index+1 till i has a k sum subarray
		if(m.find(presum-k)!=m.end()){
			++count;
			if((i-m[presum-k])>length){
                length = (i-m[presum-k]);
                s=m[presum-k]+1;
                e = i;
            }
		}
		
	}
        
        cout<<length<<" "<<s<<" "<<e<<endl;

        
    }
};
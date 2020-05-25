class Solution {
public:
    int kadane(vector<int> a, int beg, int end, int n, int sign){
        long long maxsum = INT_MIN;
        long long curr= INT_MIN;
        for(int i=beg; i<=end; i++){
            curr = (sign*a[i])+max(curr,0ll);
            maxsum = max(maxsum,curr);
        }
        return maxsum;
    }
    
    // circular can have A[0,i] + A[j,N-1] as corner elemnts can be
    // cross referenced in subarrays
    // hence we check regular kadane with crossed subarrays
    // that is sum of all + max kadane sum of -ves
    int maxSubarraySumCircular(vector<int>& A) {
       int n = A.size();
        long long s=0;
        for(int i:A)s+=i;
        long long ans1 = kadane(A,0,n-1,n,1);
        // sum of all with kadane of -ves with first removed
        long long ans2 = s+kadane(A,1,n-1,n,-1);
        // sum of all kadane of -ves with last removed
        long long ans3 = s+kadane(A,0,n-2,n,-1);
        return max(ans1,max(ans2,ans3));
    }
};
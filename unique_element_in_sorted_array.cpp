#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int> arr, int low, int high)
    {
        // Base cases
        if (low > high)
            return -1;

        if (low==high)
        {

            return arr[low];
        }

        int ans=0;
        // Find the middle point
        int mid = (low + high) / 2;

        // If mid is even and element next to mid is
        // same as mid, then output element lies on
        // right side, else on left side
        if (mid%2 == 0)
        {
            if (arr[mid] == arr[mid+1])
                ans = search(arr, mid+2, high);
            else
                ans = search(arr, low, mid);
        }
        else  // If mid is odd
        {
            if (arr[mid] == arr[mid-1])
                ans = search(arr, mid+1, high);
            else
                ans= search(arr, low, mid-1);
        }
        return ans;

    }
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        return search(nums,0,n);
    }
};

int main()
{
  vector<int> a = {1,1,2,3,3,4,4,8,8};
  Solution s;
  cout<<s.singleNonDuplicate(a);

  return 0;
}
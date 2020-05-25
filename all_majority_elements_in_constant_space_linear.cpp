class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int x = nums.size();
        int c1 = 0,c2 = 0;
        int f = INT_MAX,s = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            if(f == nums[i]) c1++;
            
            else if(s == nums[i]) c2++;
            
            else if(c1 == 0){
                f = nums[i];
                c1=1;
            }
            
            else if(c2 == 0){
                s = nums[i];
                c2=1;
            }
            
            else{c1--;c2--;}
        }
        c1 = 0;c2 = 0;
        
        for (int i = 0; i < nums.size(); i++) { 
        if (nums[i] == f) 
            c1++; 
  
        else if (nums[i] == s) 
            c2++; 
        }
        nums.clear();
        if(c1 > x/3) nums.push_back(f);
        if(c2 > x/3) nums.push_back(s);
        return nums;
    }
};
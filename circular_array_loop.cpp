class Solution {
public:
    
    bool checkCycle( vector<int> &a, int start){
        
        int n = a.size();
        // move slow 1 ahead
    int slow=((start+a[start])%n+n)%n;
        // move fast 2 ahead
        int fast=((slow+a[slow])%n+n)%n;
       
        
        while(slow!=fast){

         
               
             slow= ((slow+ a[slow])%n+n)%n;
            
             fast= ((fast + a[fast])%n+n)%n;
            
            fast= ((fast + a[fast])%n+n)%n;
          

            
        }
          // check if it is a 1 element loop
            if(((slow+a[slow])%n+n)%n ==slow){
               return false;
            }
        
        // this sets either the loop is rigthward or leftward
            int dir = a[slow]>0?1:0;
        
        // now check if same direction is there or not
        
        int temp = ((slow+a[slow])%n+n)%n;
        while(temp!=slow){
            // if direction changes at any point, then cycle is false
            if(dir==1 && a[temp]<0  || dir==0 && a[temp]>0)
                return false;
             temp  = ((temp+a[temp])%n+n)%n;
        }
        
            
            return true;

           

        }
    bool circularArrayLoop(vector<int>& a) {
        
        if(a.size()<=1)
            return false;
        
         for(int i:a){
            if(i==0) return false;
        }
        
       int n = a.size();
        
        // we check for every possible starting index
        for(int i=0; i<n; i++){
            if(checkCycle(a,i))
                return true;
        }
        
        return false;
    }
};
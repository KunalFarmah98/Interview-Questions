typedef long long ll;
class Solution {
public:
    int msbPos(ll n) { 
        int msb_p = -1; 
        while(n){ 
            n = n>>1; 
            msb_p++; 
        }
        return msb_p; 
    } 
    int rangeBitwiseAnd(int x, int y) {
    
        
         ll res = 0;
  
            while (x && y){ 
 
                int msb_p1 = msbPos(x); 
                int msb_p2 = msbPos(y); 

                if (msb_p1 != msb_p2) 
                    break; 

                ll msb_val =  (1 << msb_p1); 
                res = res + msb_val; 

                // subtract 2^msb_p1 from x and y. 
                x = x - msb_val; 
                y = y - msb_val; 
            } 

            return res; 
    
    }
};
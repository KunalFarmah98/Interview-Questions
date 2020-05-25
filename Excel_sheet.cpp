class Solution {
public:

	int titleToNumber(string s) 
	{ 
    // This process is similar to binary-to- 
    // decimal conversion 
    int result = 0; 
    for (const auto& c : s) 
    { 
        result *= 26; 
        result += c  - 'A' + 1; 
    } 
  
    return result; 
	} 

    string convertToTitle(int n) {
        vector<int> rem;
        char a[28] = "ZABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if(n<=26){
            string ans="";
            ans+=a[n];
            return ans;
        }
        
        // decimal to binary equivalent
        // if completely divisble, then quotient is decremeneted
        // pattern he ye
        while(n>=1){
            rem.push_back(n%26);
            if(n%26==0){n/=26;--n;continue;}
            n/=26;
            
        }
        
        int k = rem.size();
        string col="";
        
       
        for(int i=k-1; i>=0; i--){
            col+=a[rem[i]];
        }
        
        return col;
    }
};
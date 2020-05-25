class Solution {
public:
    //map<pair<int,int>,string>dp;
    void buildLowestNumberRec(string str, int n, string &res) 
    { 
    // If there are 0 characters to remove from str, 
    // append everything to result 
    if (n == 0) 
    { 
        res.append(str); 
        return; 
    } 
  
    int len = str.length(); 
  
    // If there are more characters to remove than string 
    // length, then append nothing to result 
    if (len <= n) 
        return; 
  
    // Find the smallest character among first (n+1) characters 
    // of str. 
    int minIndex = 0; 
    for (int i = 1; i<=n ; i++) 
        if (str[i] < str[minIndex]) 
            minIndex = i; 
  
    // Append the smallest character to result 
    res.push_back(str[minIndex]); 
  
    // substring starting from minIndex+1 to str.length() - 1. 
    string new_str = str.substr(minIndex+1, len-minIndex); 
  
    // Recur for the above substring and n equals to n-minIndex 
    buildLowestNumberRec(new_str, n-minIndex, res); 
} 
//     string num(string a, string &s, int k, int i, int c){
//         if(i==a.length() && c!=a.length()-k)return "999999999999999999";
//         if(c==a.length()-k){
//             if(s.empty())
//                 return "0";
// //            int j=0;
// //            while(s[j]=='0')
// //                ++j;
//             return s;
//         }
        
//         if(dp[make_pair(i,c)]!=0)return dp[make_pair(i,c)];

//         s.push_back(a[i]);
//         string taken = num(a,s,k,i+1,c+1);
//         s.pop_back();
//         string ignored = num(a,s,k,i+1,c);
//         return dp[make_pair(i,c)] =min(taken,ignored);
//     }
    string removeKdigits(string a, int k) {
        string s="";
        buildLowestNumberRec(a,k,s);
        cout<<s<<endl;
        if(s=="")
            return "0";
        if(s.length()>1){
            int k=0;
            while(s[k]=='0' && k<s.length()-1)++k;
            return s.substr(k);
        }
        else return s;
        // string ans= num(a,s,k,0,0);
        // cout<<ans<<endl;
        // if(ans.empty())
        //     return "0";
        // int j=0;
        // while(ans[j]=='0')
        //     ++j;
        // if(j==ans.size())return "0";
        // return ans.substr(j);
        //return num(a,s,k,0,0);
    }
};
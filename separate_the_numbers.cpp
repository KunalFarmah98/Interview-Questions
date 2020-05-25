
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll stoi_(string s){
    int len = s.length();
    ll mul=1;
    ll num=0;
    for(int i=1; i<len; i++){
        mul*=10;
    }
    for(int i=0; i<len; i++){
        num+=(s[i]-'0')*mul;
        mul/=10;
    }

    return num;
}

int main(){
    int n;
    cin>>n;

    string s;
    while(n--){
        cin>>s;
        int len = s.length();
        if(s[0]=='0'){cout<<"NO"<<endl;continue;}
        bool found=false;
        string str;
        for(int l = 1; l<=len/2; l++){
            // if first element has 0 after it, we need to include it
            if(s[l]=='0')
                continue;
            found=false;
            str= s.substr(0,l);

            ll num = stoi_(str);

            string next = to_string(num+1);
            //cout<<next<<" ";
            // always find from the current index and not from beginning
            int i = s.find(next,l-1);
            if(i==string::npos){
                found=false;
                continue;
            }
            int curr=l;
            while(i!=string::npos){
                //cout<<next<<"->";
                if(i!=curr){found=false;break;}
                // the next int was found but was followed by 0, its invalid
                if(s[i+next.length()]=='0'){
                    found=false;
                    break;
                }
                // keep checking for next ints till we reach eos
                curr=i+next.length();
                if(curr==s.length()){
                    found=true;
                    break;
                }

                ll temp = stoi_(next);
                //cout<<temp+1<<" ";
                next = to_string(temp+1);
           	 	// always find from the current index and not from beginning
                i = s.find(next,curr);

            }
            if(!found)continue;
            else break;
        }

        if(found){
            cout<<"YES"<<" "<<str<<endl;
        }
        else cout<<"NO"<<endl;

    }



    return 0;
}
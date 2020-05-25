using namespace std;

void longest_palindrome(string a, int n){
    map<int,int> m;

    int start = 0;
    int end = n;

// s and end track start and end
    int s=start;
    int e=end-1;

    // we go from end towards start finding a palindrome
    // if we find one, we search from start+1

    while(start<n){

        bool pl = true;


        if(s<e && a[s]==a[e]){
            s++;
            e--;
        }
        else if(s<e && a[s]!=a[e]){
            // plaindrome not found
            pl=false;
            end--;
            s=start;
            e=end;
            continue;
        }

        if(s>=e && pl){
            // it means we found a palindrome
            m.insert(make_pair(start,end));
            // research for another from start+1
            start++;
            end=n;

            s=start;
            e=end;
        }
    }

    int maxlength = INT_MIN;

    for(auto palindromes : m){

        int curl  = palindromes.second - palindromes.first;
        if(curl>maxlength){
            maxlength = curl;
            start = palindromes.first;
            end =  palindromes.second;
        }
    }

    for(int i=start; i<=end; i++){
        cout<<a[i];
    }

    cout<<endl;


}

int main() {
    int t;
    cin>>t;

    while(t--){
        string a;
        cin>>a;
        int n = a.length();
        longest_palindrome(a,n);
    }
    return 0;
}
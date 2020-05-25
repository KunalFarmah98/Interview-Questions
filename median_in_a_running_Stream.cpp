
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;


void balance(priority_queue<int, vector<int>, less<int> >&left,priority_queue<int, vector<int>, greater<int> > &right){
   
int diff1 = left.size() - right.size();
int diff2 = right.size() - left.size();

    if(diff1>=2){
        right.push(left.top());
        left.pop();
    }
    else if(diff2>=2){
        left.push(right.top());
        right.pop();
    }
}

double find_median(	priority_queue<int, vector<int>, less<int> >&left,priority_queue<int, vector<int>, greater<int> > &right){



    if(left.size()==right.size()){
        return (double)(left.top()+right.top()) / (double)2;
    }
    else{
        return (left.size()>right.size())?(double)left.top():(double)right.top();
    }

}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


// min heap for right ele
    priority_queue<int, vector<int>, greater<int> > right;
    // maxheap for left ele
    priority_queue<int, vector<int>, std::less<int> >left;

    for(int i=0; i<n; i++){
        if(left.empty() || arr[i]<left.top())
            left.push(arr[i]);
        else
            right.push(arr[i]);

        balance(left,right);

        cout<<find_median(left,right)<<endl;
    }






    return 0;
}
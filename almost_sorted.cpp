
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

bool issorted(vector<int> a, int n){
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1])return false;
    }
    return true;
}

/*bool checkswaps(vector<int> a, int n){
    int c=0;
    int i1=-1,i2=-1;
    for(int i=0; i<n; i++){
        if(a[i]>a[i+1]){
            //first grater element needs to go after
            if(i1==-1)
            i1=i;
            else{
                // next greater element will stay,its next smaller will go before if it is not
                // the last element
                if(i<n-1)
                i2=i+1;
                else i2=i;
                break;
            }
        }
    }

    if(i2==-1){
        i2=i1+1;
    }
    swap(a[i1],a[i2]);
    if(issorted(a,n)){
        cout<<"yes"<<endl;
        cout<<"swap "<<i1+1<<" "<<i2+1<<endl;
        return true;
    }
    return false;
}*/

void almostsorted(std::vector<int> a, int  n){
	if(issorted(a,n)){cout<<"yes";return;}
	vector<int> sorted = a;
	sort(sorted.begin(), sorted.end());
	// finding the first and last elemnts where input doesn't match the sorted version
	int i1,i2;
	for(int i=0; i<n; i++){
		if(a[i]!=sorted[i]){
			i1=i;
			break;
		}
	}

	for(int i=n-1; i>=0; i--){
		if(a[i]!=sorted[i]){
			i2=i;
			break;
		}
	}
	// check if we can swap them
	swap(a[i1],a[i2]);
	if(issorted(a,n)){
		cout<<"yes"<<endl<<"swap "<<i1+1<<" "<<i2+1<<endl;
	}
	// if not then check if we can reverse them
	else{
		swap(a[i1],a[i2]);
		reverse(a.begin()+i1,a.begin()+i2+1);
		if(issorted(a,n)){
			cout<<"yes"<<endl<<"reverse "<<i1+1<<" "<<i2+1<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
}
int main(){
    int n;
    cin>>n;

    vector<int> a(n,0);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    almostsorted(a,n);

    /*if(issorted(a,n)){
        cout<<"yes"<<endl;
        return 0;
    }


    int s=-1,e=n-1;
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1] && s==-1){
        
                s=i;
        }
        else if(a[i]<a[i+1] && s!=-1){
            e=i;
            break;
        }
    }
    if(!checkswaps(a,n))
        {
        reverse(a.begin()+s, a.begin()+e+1);
        if(issorted(a,n)){
            cout<<"yes"<<endl;
            cout<<"reverse "<<s+1<<" "<<e+1<<endl;
        }
        else{
            cout<<"no"<<endl;
            return 0;
        }
    }*/


    return 0;
}

//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

string min_length_substring_containing_all_ele_of_pat(string str, string pat){

	int len1 = str.length();
	int len2 = pat.length();
	// if pattern is bigger than string
	if(len2>len1)return "";

	// sliding window
	int s=0,e=0,start=-1,ele=0,minlength=INT_MAX;
	int hpat[256]={0};
	int hstr[256]={0};
	// finding all occurences of ele in pat
	for(int i=0;i<len2;i++) hpat[pat[i]]++;

	// iterate entire string and keep growing and shrinking the window wherever possible
	for(int i=0; i<len1; i++){
		hstr[str[i]]++;
		// if the element is in pattern and we still haven't got all the occurences, grow the window
		if(hpat[str[i]]!=0 && hstr[str[i]]<=hpat[str[i]]){
			++ele;
		}
		// if we found all occurences, now try to shrink the window
		if(ele==len2){
			while(hpat[str[s]]==0 || hstr[str[s]]>hpat[str[s]]){
				// if we have extra occurences, shrink the window
				if(hstr[str[s]]>hpat[str[s]]){
					// removing the element from the window
					hstr[str[s]]--;
				}
				++s;
			}
			// finding min length
			int len = i-s+1;
			if(len<minlength){
				minlength==len;
				start=s;
			}

		}
		
	}


	if(start==-1)return "";
	else return str.substr(start,minlength);

}
int main(){
	string str,pat;
	cin>>str>>pat;

	cout<<min_length_substring_containing_all_ele_of_pat(str,pat)<<endl;



	return 0;
}
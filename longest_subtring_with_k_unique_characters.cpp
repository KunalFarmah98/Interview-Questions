#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int unique_char_no(int*h)
{
	int q = 0;
	for (int i = 0; i < 256; i++)
	{
		if (h[i] > 0)
			q++;
	}
	return q;
}

int longest_k_unique_substring(string s, int k)
{
	int h[256] = { 0 };
	int len=-1;

	for (int end = 0, start = 0; s[end]; end++)
	{
		h[s[end]]++;

		// if we get a window witk k unique chars and it is greater than prev window found
		if (unique_char_no(h) == k && end - start + 1 > len)
			len = end - start + 1;
     
     // if we get more unique chars, remove from the start
		else if (unique_char_no(h) > k)
		{
			h[s[start]]--;
			start++;
		}
	}
	
	return len;
}

int main()
{
	int t = 0; cin >> t;
while(t--)	{
		string s;
		cin >> s;
		int l = s.length();
		int k, c; cin >> k; c = 0;
		cout<<longest_k_unique_substring(s, k)<<endl;
	}
}
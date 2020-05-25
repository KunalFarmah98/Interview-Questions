#include <iostream>
#include <cstring>
using namespace std;

string keypad[]={" ",
                 "abc", "def",
                 "ghi", "jkl", "mno",
                 "pqrs", "tuv", "wxyz"};


void getButton(char dig, char arr[]){
    char table[][5] = {
            " ",
            "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
    };

    int digit = dig - '0';  // index
    strcpy(arr, table[digit]);
}


void generateCodes(char inp[], int be, char ansSoFar[], int i){
    if (inp[be] == '\0'){
        ansSoFar[i] = '\0';
        cout << ansSoFar <<" ";
        return ;
    }

    char dig = inp[be];
    char code[10] = {};
    getButton(dig, code);

    for(int j = 0; code[j] != '\0'; ++j){
        ansSoFar[i] = code[j];
        generateCodes(inp, be + 1, ansSoFar, i + 1);
    }
}

int count(char inp[],int ans,int i){

    if(inp[i]=='\0')
        return ans;

    ans=ans*(keypad[(inp[i]-'0')].size());

    count(inp,ans,i+1);
}


int main() {

    char inp[100], out[100];
    cin >> inp;

    int ans=1;


   cout<<count(inp,ans,0)<<endl;

   generateCodes(inp, 0, out, 0);

}
#include <iostream>
using namespace std;

char digToChar(int num){
    // 1-->a
    // 2-->b
    // 'a' + num - 1;
    return 'a' + num - 1;  //logic
}

int j;
int c=0;
int count=0;
void printCodes(char inp[], int be, char ansSoFar[], int i) {
    if (inp[be] == '\0'){
        ansSoFar[i] = '\0';

        if(count<c) {
            cout << ", ";
            ++count;
        }
        for(j=0; j<i; j++)
            cout << ansSoFar[j] ;
            c++;
        return;
    }

    //123
    // for individual numbers
    int num = inp[be] - '0';                    // 1
    char curChar = digToChar(num);              // a
    ansSoFar[i] = curChar;
    printCodes(inp, be + 1, ansSoFar, i + 1);// abc, aw

    if (inp[be + 1] == '\0') return;            // no more next char

    // 12 3   // for 2 in one number
    int nextDig = inp[be + 1] - '0';            // 2
    num = num * 10 + nextDig;                   // 1 * 10 + 2
    if (num <= 26) {
        ansSoFar[i] = digToChar(num);
        printCodes(inp, be + 2, ansSoFar, i + 1);  //as we already printed for beg+1, so increment it
    }
}


int main() {
    char arr[100], ans[100];
    cin >> arr;
    cout<<"[";
    printCodes(arr, 0, ans, 0);
    cout<<"]";

//    cout<<c;
}

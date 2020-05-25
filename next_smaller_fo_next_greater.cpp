#include<bits/stdc++.h>
using namespace std;


int searchval(vector<int>a, int n, int x) {
  for (int i = 0; i < n; i++) {
    if (a[i] == x)
      return i;
  }
}


void push_back(stack<int> &s, int x) {


  if (s.empty())
    s.push(x);       // if its empty, simply push the element to the last

  else {

    int temp = s.top(); // upar wala element jo last me ana chahiye utha liya
    s.pop();

    push_back(s, x); // recursion se baki kiya

    s.push(temp);

  }              // last me elemnt daal diya jo nikala tha

}


void revstack(stack<int> &s) {


  if (s.empty())
    return;

  int x = s.top(); // removing the top element
  s.pop();

  revstack(s);  // baki reverse kra

  push_back(s, x); // peeeche daal diya


}


//O(n^2)

/*vector<int> next_smaller(vector<int> a, int n) {


  stack<int> s;
  stack<int> greater;
  vector<int> ans(a.size(), 0);

  s.push(a[0]);

  for (int i = 1 ; i < n; i++) {


    if (a[i] > s.top()) {

      while (!s.empty()) {
        if (a[i] > s.top()) {
          s.pop();
          greater.push(a[i]);
        } else
          break;

      }

    }

    s.push(a[i]);
  }



  while (!s.empty()) {

    int index  = searchval(a, n , s.top());                  // for the numbers remaining in s, there is no next greater, hence -1
    s.pop();
    ans[index] = -1;

  }

  int k = 0;

  revstack(greater);                        // for all the elements in greater, we find next smaller

  while (!greater.empty()) {

    int index = searchval(a, n, greater.top());
    greater.pop();

    for (int i = index + 1; i < n; i++) {
      if (a[i] < a[index]) {
        if (ans[k] == -1) {
          ++k;
          ans[k] = a[i];
          ++k;
          break;
        }


        else {
          ans[k] = a[i];
          ++k;
          break;
        }

      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (ans[i] == 0)
      ans[i] = -1;
  }

  return ans;
}
*/


void nextGreater(int arr[], int n, int next[])
{
  // create empty stack
  stack<int> S;       // stack contains hte index of all greater elements

  // Traverse all array elements in reverse order
  // we compute next greater elements of
  //              every element

  for (int i = n - 1; i >= 0; i--)
  {
    // Keep removing top element from S while the top
    // element is smaller then or equal to arr[i]

    while (!S.empty() &&
           arr[S.top()] <= arr[i]
          )
      S.pop();

    // store the next greater element of current element
    if (!S.empty())
      next[i] = S.top();

    // If all elements in S were smaller than arr[i]
    else
      next[i] = -1;

    // Push this element
    S.push(i);
  }
}


void nextSmaller(int arr[], int n, int next[])
{
  // create empty stack
  stack<int> S;

  // Traverse all array elements in reverse order

  //' we compute right smaller element of
  //              every element
  for (int i = n - 1; i >= 0; i--)
  {
    // Keep removing top element from S while the top
    // element is greater then or equal to arr[i]
    while (!S.empty() &&
           arr[S.top()] >= arr[i])

      S.pop();

    // store the next greater element of current element
    if (!S.empty())
      next[i] = S.top();

    // If all elements in S were smaller than arr[i]
    else
      next[i] = -1;

    // Push this element
    S.push(i);
  }
}

// Function to find Right smaller element of next greater
// element
void nextSmallerOfNextGreater(int arr[], int n)
{
  int NG[n]; // stores indexes of next greater elements
  int RS[n]; // stores indexes of right smaller elements

  // Find next greater element
  // Here G indicate next greater element
  nextGreater(arr, n, NG);

  // Find right smaller element
  // using same function nextGreater()
  // Here S indicate right smaller elements
  nextSmaller(arr, n, RS);

  // If NG[i] == -1 then there is no smaller element
  // on right side. We can find Right smaller of next
  // greater by arr[RS[NG[i]]]
  for (int i = 0; i < n; i++)
  {
    if (NG[i] != -1 && RS[NG[i]] != -1)
      cout << arr[RS[NG[i]]] << " ";
    else
      cout << "-1" << " ";
  }
}


int main() {

  int t;
  int n;
  // vector<int>a;
  int a[100000];

  cin >> t;
  while (t > 0) {



    cin >> n;
    // a.resize(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];

    // vector<int>ans = next_smaller(a, n);

    //   for (int i = 0; i < n; i++)
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    nextSmallerOfNextGreater(a, n);
    cout << endl;

    --t;
  }
}

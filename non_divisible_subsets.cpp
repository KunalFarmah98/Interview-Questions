#include<bits/stdc++.h>
using namespace std;

const int MAXM = 100;

int n, m, st[MAXM], sp, sz, a[MAXM], ret, tn, ai;
bool used[MAXM];
int forbidden[MAXM];
set<int> S;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> ai;
        // counting number of elemnets giving a particular remainder
        ++a[ai % m];
        S.insert(ai);
    }
    // for remainder k/2 when k is even, we can't incldue another k/2 remainder or sum
    // will become div by k
    if (m % 2 == 0)
        a[m / 2] = min(a[m / 2], 1);
    ret = 0;
    for(int i = 1; i <= m / 2; i++)
        // we need maximal subset, so we include the remainder occuring max times
        ret += max(a[i], a[m - i]);
    // for remainder 0, we can't include another remainder 0 or sum will get div by k
    ret += min(a[0], 1);
    cout << ret << endl;
    return 0;
}
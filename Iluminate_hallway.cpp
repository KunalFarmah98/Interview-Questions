// { Driver Code Starts
// driver code
#include <bits/stdc++.h>

using namespace std;

int min_lights(int hallway[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int hallway[n];
        for (int i = 0; i < n; i++)
            cin >> hallway[i];

        cout << min_lights(hallway, n) << endl;
    }
    return 1;
}
// } Driver Code Ends
//User function Template for C++


int min_lights(int hallway[], int n) {
    vector<pair<int, int>> lights;
    for (int i = 0; i < n; i++)
        if (hallway[i] > -1)
            lights.push_back(pair<int, int>(i - hallway[i], i + hallway[i]));

    // only check on the left side
    sort(lights.begin(), lights.end());

    int target = 0, lights_on = 0, i = 0;
    while (target < n) {
        if (i == lights.size() || lights[i].first > target)
            return -1;

        int max_range = lights[i].second;
        // finding last bulb to light upto 0
        while (i + 1 < lights.size() && lights[i + 1].first <= target) {
            i++;
            max_range = max(max_range, lights[i].second);
        }
        if (max_range < target)
            return -1;

        lights_on++;
        // now maxleft to be lighted is maxrange+1
        target = max_range + 1;
        i++;
    }

    return lights_on;
}

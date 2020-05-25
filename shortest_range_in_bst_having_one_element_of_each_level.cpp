// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
pair<int, int> shortestRange(Node *root);

// Position this line where user code will be pasted.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        auto range = shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }

    return 0;
}// } Driver Code Ends
// User function Template for C++

vector<vector<int> > lvl(Node *root){
    queue<Node*> q;
    Node* del = NULL;
    q.push(root);
    q.push(del);
    vector<vector<int> > ans;
    vector<int> temp;
    while(!q.empty()){
        Node* ele = q.front();
        q.pop();
        if(ele==del){
            if(!q.empty()){
                q.push(del);
                sort(temp.begin(),temp.end());
                ans.push_back(temp);
                temp.clear();
                continue;
            }
            else {
                sort(temp.begin(),temp.end());
                ans.push_back(temp);
                temp.clear();
                break;
            }
        }

        if(ele->left){
            q.push(ele->left);
        }
        if(ele->right){
            q.push(ele->right);
        }

        temp.push_back(ele->data);

    }

    return ans;
}
pair<int, int> shortestRange(Node *root) {

    vector<vector<int> >level = lvl(root);
    int n = level.size();
    int r = level[0][0];
    vector<int> ans;
    int prev = r;
    ans.push_back(r);
    for(int i=1; i<n; i++){
        int ele,diff=INT_MAX;
        for(int j=0; j<level[i].size(); j++){
            int d = abs(r-level[i][j]) + abs(prev-level[i][j]);
            if(d<diff){
                diff = d;
                ele = level[i][j];
            }
        }
        prev = ele;
        ans.push_back(ele);
    }

    int f = *min_element(ans.begin(),ans.end());
    int s = *max_element(ans.begin(),ans.end());

    return {f,s};
}
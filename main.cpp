#include <bits/stdc++.h>
using namespace std;

/*
Input: 8 integers separated by newlines.
- First 7 integers: values of nodes in a BST given by level-order of the BST (i.e., the BFS order of the actual BST structure if inserted appropriately).
- Last integer: cnt, ask for the cnt-th largest value.

We will construct the BST according to the standard rule by inserting the first 7 keys one-by-one.
Then perform a reverse in-order traversal to find the cnt-th largest.

Assumptions: distinct keys as stated.
*/

struct Node {
    int val;
    Node *l, *r;
    Node(int v): val(v), l(nullptr), r(nullptr) {}
};

void insert(Node* &root, int x) {
    if (!root) { root = new Node(x); return; }
    if (x < root->val) insert(root->l, x);
    else insert(root->r, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    a.reserve(8);
    long long x;
    for (int i = 0; i < 8; ++i) {
        if (!(cin >> x)) return 0; // if insufficient input, exit
        a.push_back(x);
    }
    // first 7 are keys, last is cnt
    Node* root = nullptr;
    for (int i = 0; i < 7; ++i) insert(root, (int)a[i]);
    int cnt = (int)a[7];

    // reverse inorder traversal to get cnt-th largest
    int ans = -1;
    int k = 0;
    vector<Node*> st;
    Node* cur = root;
    while (cur || !st.empty()) {
        while (cur) { st.push_back(cur); cur = cur->r; }
        cur = st.back(); st.pop_back();
        if (++k == cnt) { ans = cur->val; break; }
        cur = cur->l;
    }
    if (ans != -1) cout << ans << "\n";
    return 0;
}


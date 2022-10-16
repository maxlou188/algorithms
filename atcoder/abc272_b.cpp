#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int> > g(n + 1);
    while (m--) {
        int k;
        cin >> k;
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                g[v[i]].insert(v[j]);
                g[v[j]].insert(v[i]);
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        if (g[i].size() != n - 1) {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
    return 0;
}
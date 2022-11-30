#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <deque>
#include <string>
#include <iomanip>
 
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<bool> D(10, 1);
    while (K--) {
        int i;
        cin >> i;
        D[i] = 0;
    }
    vector<int> U;
    for (int i = 0; i < 10; ++i) {
        if (D[i]) U.push_back(i);
    }
    vector<pair<int, int> > res;
    while (N) {
        int d = N % 10;
        if (D[d] && (res.empty() || res.back().second != 1)) res.push_back(make_pair(d, -1));
        else if (d > U.back()) res.push_back(make_pair(U.front(), 1));
        else {
            auto it = upper_bound(U.begin(), U.end(), d);
            if (!res.empty() && res.back().second == 1 && it == U.end()) res.push_back(make_pair(U.front(), 1));
            else res.push_back(make_pair(*it, 0));
        }
        N /= 10;
    }
    if (res.back().second == 1) {
        if (U.front() != 0) cout << U.front();
        else cout << U[1];
        for (int i = 0; i < res.size(); ++i) {
            cout << U.front();
        }
    } else {
        bool flag = false;
        for (int i = res.size() - 1; i >= 0; --i) {
            if (flag) {
                cout << U.front();
            } else {
                cout << res[i].first;
                if (res[i].second == 0 || res[i].second == 1) flag = true;
            }
        }
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    solve();
    
    return 0;
}
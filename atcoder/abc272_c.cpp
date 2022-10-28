#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = -1;
    sort(a.begin(), a.end());
    vector<int> e, o;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (!(a[i] & 1)) {
            e.push_back(a[i]);
            if (e.size() == 2) {
                break;
            }
        }
    }
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] & 1) {
            o.push_back(a[i]);
            if (o.size() == 2) {
                break;
            }
        }
    }
    if (o.size() == 2) {
        ans = max(ans, accumulate(o.begin(), o.end(), 0));
    }
    if (e.size() == 2) {
        ans = max(ans, accumulate(e.begin(), e.end(), 0));
    }
    cout << ans << '\n';
    return 0;
}
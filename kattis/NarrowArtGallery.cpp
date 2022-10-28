#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <climits>
using namespace std;

#define OPEN    2
#define LEFT    0
#define RIGHT   1

long solve(int i, int u, int ck, vector<vector<int> > &v, int &n, int &k, vector<vector<vector<long> > > &dp) {
    // takes the row we are on and which side is unavailable
    if (ck == k) return 0;
    if (i == n) return INT_MAX;
    if (dp[i][u][ck] != -1) return dp[i][u][ck];
    long ans = solve(i + 1, OPEN, ck, v, n, k, dp);
    if (u == OPEN) {
        ans = min(ans, solve(i + 1, RIGHT, ck + 1, v, n, k, dp) + v[i][LEFT]);
        ans = min(ans, solve(i + 1, LEFT, ck + 1, v, n, k, dp) + v[i][RIGHT]);
    } else if (u == LEFT) {
        ans = min(ans, solve(i + 1, LEFT, ck + 1, v, n, k, dp) + v[i][RIGHT]);
    } else {
        ans = min(ans, solve(i + 1, RIGHT, ck + 1, v, n, k, dp) + v[i][LEFT]);
    }
    dp[i][u][ck] = ans;
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    int sum = 0;
    vector<vector<int> > v(n + 1, vector<int>(2));
    vector<vector<vector<long> > > dp(n + 1, vector<vector<long> > (3, vector<long> (k + 1, -1)));
    for (int i = 0; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
        sum += v[i][0] + v[i][1];
    }
    cout << sum - solve(0, OPEN, 0, v, n, k, dp) << '\n';
    return 0;
}
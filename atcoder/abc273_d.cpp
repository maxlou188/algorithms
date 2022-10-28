#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

int h, w, rs, cs;
unordered_map<int, vector<int> > rm, cm;

int main() {
    cin >> h >> w >> rs >> cs;
    int n;
    cin >> n;
    while (n--) {
        int r, c;
        cin >> r >> c;
        rm[r].push_back(c);
        cm[c].push_back(r);
    }
    for (auto it=rm.begin(); it != rm.end(); it++) sort(it->second.begin(), it->second.begin());
    for (auto it=cm.begin(); it != cm.end(); it++) sort(it->second.begin(), it->second.begin());
    
    int q;
    cin >> q;
    char d; int l;
    while (q--) {
        cin >> d >> l;
        if (d == 'U') {
            int c = *(lower_bound(cm[cs].begin(), cm[cs].end(), rs));
            if (rs - l > c) {
                rs -= l;
            } else {
                rs = 1;
            } 
        }
    }
    return 0;
}
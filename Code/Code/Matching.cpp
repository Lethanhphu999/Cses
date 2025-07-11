
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#ifndef ONLINE_JUDGE

#endif

map<int, vector<int>> a;

void solve() {
    int n, x, y; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    vector<bool> gone(n, false);
    int result = 0;
    for (auto it = a.begin(); it != a.end(); it++) {
        if (gone[it->first] == false) {
            gone[it->first] = true;
            for (auto& child : it->second) {
                gone[child] = true;
            }
            ++result;
        }
    }

    cout << result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

#ifndef ONLINE_JUDGE
    //FILE* fin = nullptr;
    //FILE* fout = nullptr;
    //freopen_s(&fin, "input.txt", "r", stdin);
    //freopen_s(&fout, "output.txt", "r", stdout);
#endif

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

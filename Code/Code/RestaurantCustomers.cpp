#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n;
    map<int, int> delta;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        delta[x]++;   
        delta[y]--;   
    }

    int result = 0, mx = 0;
    for (auto& [t, change] : delta) {
        result += change;
        mx = max(mx, result);
    }

    cout << mx;
}
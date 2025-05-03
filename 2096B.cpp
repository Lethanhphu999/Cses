#include <bits/stdc++.h>
using namespace std;
const long long Max = 2e5 +10;
struct gloves{
    int l;
    int r;
    /* data */
};

vector<gloves> g(Max, gloves());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >>  g[i].l;
    }
    for (int i = 0; i < n; i++) {
        cin >> g[i].r;
    }

    std::sort(g.begin(), g.begin() + n, [&](const gloves& a, const gloves& b) {
        return (a.l + a.r) < (b.l + b.r);
    });
    int result = 1;
    for (int i = 0; i < k - 1; i++) {
        result += g[i].l + g[i].r;
    }
    for (int i = k - 1; i < n; i++) {
        result += max(g[i].l, g[i].r);
    }

    cout << result << "\n";


    return 0;
}

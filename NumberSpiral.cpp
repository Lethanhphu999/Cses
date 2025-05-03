#include <bits/stdc++.h>
using namespace std;


void test() {
    long long y, x;
    cin >> y >> x;
    long long mx = max(y, x);
    long long result;
    result = mx * (mx - 1) + 1;
    if ((y >= x && y % 2 == 0)
        || (x > y && x & 1 )) {
        result += abs(y - x);
    } else {
        result -= abs(y - x);
    }

    cout << result << std::endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--) {
        test();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N;
int x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long sum;
    cin >> N;
    sum = 1LL * N * (N + 1) / 2;

    for (int i = 0; i < N - 1; i++) {
        cin >> x;
        sum -= x;
    }
    std::cout << sum;
    return 0;
}
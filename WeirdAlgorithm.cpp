#include <bits/stdc++.h>

#define print(result) std::cout << result << " ";

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long N;
    cin >> N;
    while (N != 1) {
        print(N);
        if (N & 1) {
            N = N * 3 + 1;
        } else {
            N = N / 2;
        }
    }
    print(N);
    return 0;
}
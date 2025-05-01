#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, e, prev = 0;
    long long move = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> e;
        if (i) {
            if (e < prev) {
                move += (prev - e);
                e = prev;
            }

        }
        prev = e;

    }

    cout << move;

    return 0;
}
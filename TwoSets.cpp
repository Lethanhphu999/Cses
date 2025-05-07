#include <bits/stdc++.h>

#define Print(result) std::cout << result << "\n";

using namespace std;

int N;
const int Max = 10e6 + 10;

set<int> s1;
bool b[Max] = {false};

void process(int N) {
    int n = N;
    long long sum = 1LL * (N + 1) * N / 4;
    while (sum && N) {
        if (sum - N >= 0) {
            b[N] = true;
            s1.insert(N);
            sum -= N * 1LL;
        } 
        --N;
    }
    Print(s1.size());
    for_each(s1.begin(), s1.end(), [](const int a) {cout << a << " ";});
    cout << std::endl;
    Print(n - s1.size());
    for (int i = 1; i < n; ++i) { 
        if (!b[i]) {
            cout << i << " ";
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    if (N & 1) {
        if (((N + 1) / 2) % 2 != 0) {
            Print("NO");
            return 0;
        }
    } else {
        if ((N / 2) % 2 != 0) {
            Print("NO");
            return 0;
        }
    }
    Print("YES");
    process(N);
    return 0;
}
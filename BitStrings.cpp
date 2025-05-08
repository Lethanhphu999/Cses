#include <bits/stdc++.h>

#define print(result) std::cout << result << " ";

using namespace std;

const long long Mod = 1e9 + 7;

map<int, long long> mm;

long long recur(int number) {
    if (mm[number]) {
        return mm[number];
    }
    if (number == 1) {
        return 2;
    } else if (number == 0) {
        return 1;
    }

    if (number & 1) {
        return mm[number] = (recur(number / 2) * recur(number / 2) * 2) % Mod;
    } else {
        return mm[number] = (recur(number / 2) * recur(number / 2)) % Mod;
    }

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << recur(n);
    return 0;
}
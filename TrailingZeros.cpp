#include <bits/stdc++.h>

#define print(result) std::cout << result << " ";

using namespace std;

void sovle() {
    int n; cin >> n;
    int result = 0;
    for (int i = 5; i <= n; i+=5) {
        int tmp  = i;
        while(tmp % 5 == 0) {
            ++result;
            tmp /= 5;
        }
        
    }
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sovle();
    return 0;
}
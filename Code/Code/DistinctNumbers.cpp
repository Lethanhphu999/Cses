#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

void radix_sort(vector<uint32_t>& a) {
    const int BITS = 8;         // 1 byte = 8 bit
    const int BASE = 1 << BITS; // 256
    const int MASK = BASE - 1;  // 0xFF
    const int PASSES = 4;       // 32 bit / 8 = 4 bytes

    int n = a.size();
    vector<uint32_t> temp(n);
    vector<int> count(BASE);

    for (int pass = 0; pass < PASSES; ++pass) {
        int shift = pass * BITS;
        fill(count.begin(), count.end(), 0);

        // ??m s? l??ng t?ng byte
        for (int i = 0; i < n; ++i) {
            int byte = (a[i] >> shift) & MASK;
            ++count[byte];
        }

        // Tính prefix sum
        for (int i = 1; i < BASE; ++i)
            count[i] += count[i - 1];

        // S?p x?p ng??c ?? stable
        for (int i = n - 1; i >= 0; --i) {
            int byte = (a[i] >> shift) & MASK;
            temp[--count[byte]] = a[i];
        }

        // Gán l?i k?t qu?
        a.swap(temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n; vector<uint32_t> a(n);
    for (auto& e : a) cin >> e;
    radix_sort(a);
    auto it = unique(a.begin(), a.end());
    cout << distance(a.begin(), it);
    return 0;
}
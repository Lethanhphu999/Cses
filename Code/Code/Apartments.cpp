#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> k;
	int idx = 0, result = 0;
	vector<int> a(n), b(m);
	for (auto& e : a) cin >> e;
	for (auto& e : b) cin >> e;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < m; i++) {
		for (; idx < n; idx++) {
			if (abs(b[i] - a[idx]) <= k) {
				++idx;
				++result;
				break;
			} else if (a[idx] - k > b[i]) {
				break;
			}
		}
	}

	cout << result;
}
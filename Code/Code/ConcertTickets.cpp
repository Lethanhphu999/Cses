#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int INF = 1e9;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	int e;
	multiset<int> a;
	for (int i = 0; i < n;i++) {
		cin >> e;
		a.insert(e);
	}
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (a.empty()) { cout << -1 << "\n"; continue; };
		auto itl = a.upper_bound(x);
		if (itl == a.begin()) {
			cout << -1 << "\n";
		} else {
			--itl;
			if (*itl <= x) {
				cout << *itl << "\n";
				a.erase(itl);
			} else {
				cout << -1 << "\n";
			}
		}
	}
}
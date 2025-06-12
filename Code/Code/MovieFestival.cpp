#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

map<int,int> m;
int n;
int result;

int main() {
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (!m[x] || y < m[x]) {
			m[x] = y;
		}
	}
	int curend = 0;
	for (auto& [mp,st] : m) {
		if (curend <= mp) {
			++result;
			curend = st;
		} else if (st < curend) {
			curend = st;
		}
	}
	cout << result;
}

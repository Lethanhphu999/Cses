#include <iostream> 
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

const int MAX = 2e5 + 10;
using namespace std;

int m[MAX] = { 0 };

int n, x;

int main() {
	//FILE* fin = nullptr;
//FILE* fout = nullptr;
//	freopen_s(&fin, "input.txt", "r", stdin);
//freopen_s(&fout, "output.txt", "r", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int result = 0;
	cin >> n >> x;
	vector<int> a(n);
	for (auto& e : a) {
		cin >> e;
	}
	sort(a.begin(), a.end());
	int i = 0, j = n - 1;
	while (i < j) {
		if (a[i] + a[j] <= x) {
			++result;
			++i; --j;
		} else {
			++result;
			--j; 
		}
	}
	if (i == j) ++result;

	cout << result;
}
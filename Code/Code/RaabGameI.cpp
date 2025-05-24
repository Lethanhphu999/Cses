#include <iostream>

using namespace std;

#define For(i,n) for (int j = i; j <= n; j++)

int ts;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	if (!a && !b) {
		cout << "YES\n";
		For(1, n) {
			cout << j << " ";
		}
		cout << "\n";
		For(1, n) {
			cout << j << " ";
		}
		cout << "\n";
		return;
	}
	if (a == 0 || b == 0 || a + b > n) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	For(1, n) {
		cout << j << " ";
	}
	cout << "\n";
	int equal = n - a - b; 
	For(1, equal) {
		cout << j << " ";
	}
	For(equal + a  + 1, n) {
		cout << j << " ";
	}
	For(equal + 1, equal + a) {
		cout << j << " ";
	}
	cout << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//FILE* fin = nullptr;
	//FILE* fout = nullptr;
	////freopen_s(&fin, "input.txt", "r", stdin);
	//freopen_s(&fout, "output.txt", "r", stdout);
	cin >> ts;
	while (ts--) {
		solve();
	}
}
#include <iostream>
#include <map>

using namespace std;

const int Max = 2e5 + 11;
int n;
map<int, int> m;
int dp[Max] = { 0 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		dp[i] = m[x]; m[x] = i;
	}

	long long  result = 0;
	for (int i = 1; i <= n; i++) {
		result += 1ll * (i - dp[i]) * (n - i + 1);
	}

	cout << result;

	

}
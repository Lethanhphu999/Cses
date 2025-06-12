#include <algorithm>
#include <iostream>
#include <vector>
#include<climits>

using namespace std;

int n;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	arr.resize(n);
	for (auto& e : arr) {
		cin >> e;
	}

	long long result = INT_MAX;

	for (int i = 0; i < (1 << n); i++) {
		long long tmp = 0;
		for (int j = 0; j < n; j++) {
			if ((1 << j) & i) {
				tmp += arr[j];
			} else {
				tmp -= arr[j];
			}
		}
		result = min(abs(result), abs(tmp));
	}

	cout << result;

}
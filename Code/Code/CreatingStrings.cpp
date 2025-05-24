#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<string> result;
vector<bool> check;
string s;

void conductResult(string str,int n) {
	if (n == s.size()) {
		result.insert(str);
		return;
	}
	for (int i = 0; i < s.size(); i++) {
		if (check[i] == false) {
			check[i] = true;
			conductResult(str + s[i], n + 1);
			check[i] = false;
		}
	}

}

void buildResult() {
	conductResult("", 0);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	check.assign(s.size(), false);
	buildResult();
	cout << result.size() << "\n";
	for (const auto& e : result) {
		cout << e << "\n";
	}

}
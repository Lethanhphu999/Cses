#include <iostream>
#include <string>
#include <set>

using namespace std;
#define LOCAL

const int Max = 1e6 + 10;

int character[28] = { 0 };
char strs[Max];
int idx = 0;
//string strs;
string s;

bool valdidate(string s) {
	bool valid = true;
	for (size_t i = 0; i < s.size(); i++) {
		++character[(int)(s[i] - 'A')];
	}

	for (int i = 0; i < 28; i++) {
		if (character[i] > (s.size() + 1) / 2) {
			valid = false;
			break;
		}
	}

	return valid;
	
}

void generateC(int sz ,int pos) {
	if (sz == s.size()) {
		return;
	}

	for (int i = 0; i < 28; i++) {
		if (i != pos && character[i]) {
			--character[i];
			strs[++idx] = (char)('A' + i);
			generateC(sz + 1, i);
			--idx;
			++character[i];
		}
	}
}

void generateString() {
	for (int i = 0; i < 28; i++) {
		if (character[i]) {
			--character[i];
			strs[++idx] = (char)('A' + i);
			generateC(1 ,i);
			break;
		}
	}
}

int step(string source, string target) {
	int step = 0;
	for (size_t i = 0; i < source.size(); i++) {
		if (source[i] != target[i]) {
			++step;
			for (size_t j = i + 1; j < source.size(); j++) {
				if (source[j] == target[i] && source[j] != source[j]) {
					std::swap(source[i], source[j]);
					break;
				}
			}
		}
	}

	return step;
}

//string strMinStep() {
//	int minStep = 1e9;
//	string result;
//
//	for (auto& e : strs) {
//        int stp = step(s, e);
//        if (stp < minStep) {
//			minStep = stp;
//			result = e;
//		}
//	}
//
//	return result;
//}

int main() {
#ifdef LOCAL
FILE* fin = nullptr;
FILE* fout = nullptr;
freopen_s(&fin, "input.txt", "r", stdin);
//freopen_s(&fout, "output.txt", "w", stdout);
#endif
	cin >> s;
	if (valdidate(s)) {
		generateString();
		for (size_t i = 0; i < s.size(); i++) {
			cout << strs[i];
		}
		//cout << "ok";
	} else {
		cout << -1;
	}

}

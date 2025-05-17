#include <iostream>
#include <string>
#include <sstream>

using namespace std;

long long step = 0;
string result;
stringstream ss(result);
void TowerOfHaNoi(int source, int target, int number) {
	if (number == 1) {
		++step;
		ss << source << " " << target << "\n";
		return;
	}
	int mediate = 0;
	for (int i = 1; i <= 3; i++) {
		if (i != source && i != target) {
			mediate = i;
			break;
		}
	}

	TowerOfHaNoi(source, mediate, number - 1);
	TowerOfHaNoi(source, target, 1);
	TowerOfHaNoi(mediate, target, number - 1);
}

int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	TowerOfHaNoi(1, 3, n);
	cout << step << endl;
	cout << ss.str();
}
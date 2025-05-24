#include <iostream>

using namespace std;

char source[505][505];
char guest[505][505];
int row, col;
int dir[2][2] = {{-1, 0}, {0, -1}};

bool checkgenerate(int y, int x, char c) {
	for (int i = 0; i < 2; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if ((0 <= nx && nx < col && 0 <= ny && ny < row && c == guest[ny][nx])
			|| c == source[y][x]) {
				return false;
		}
	}
	return true;
}

void solve() {
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			for (char c = guest[y][x]; c <= 'D'; c++) {
				if (!checkgenerate(y, x, c)) {
					if (c == 'D') {
						if (x) {
							guest[y][x] = 'A';
							--x;
						} else {
							if (y) {
								guest[y][x] = 'A';
								--y;
							} else {
								cout << "IMPOSSIBLE";
								return;
							}
						}
					}
				} else {
					guest[y][x] = c;
					break;
				}
			}
			
		}
	}

	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			cout << guest[y][x];
		}
		cout << "\n";
	}
}

int main() {
	cin >> row >> col;
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			guest[y][x] = 'A';
			cin >> source[y][x];
		}
	}
	solve();

}
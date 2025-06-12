#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001] = { 0 };
int dir[8][2] = { {1 ,2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int n;

void solve() {
	int y, x, ny, nx;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			ny = y + dir[i][0];
			nx = x + dir[i][1];
			if (0 <= ny && ny < n && 0 <= nx && nx < n && !map[ny][nx]) {
				if (nx || ny) {
					map[ny][nx] = map[y][x] + 1;
					q.push({ ny, nx });
				}
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	solve();
}
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Kích th??c c?a l??i
const int GRID_SIZE = 3;

// Tr?ng thái ?ích
const string GOAL_STATE = "123456789";

struct Node {
    string state;
    int g_state;
    int f_state;

    bool operator>(const Node& other) {
        return f_state > other.f_state;
    }
};

int calulate_manhattan_distance(string state) {
    int distance = 0;
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        int c = i % GRID_SIZE;
        int r = i / GRID_SIZE;
        int point = state[i] - '0';
        int c_point = point % GRID_SIZE;
        int r_point = point / GRID_SIZE;
        distance += (abs(c - c_point) + abs(r - r_point)) / 2;
    }
    return distance;
}

int solve(string initState) {
    priority_queue<Node, vector<Node>, greater<Node>> open_set;
    unordered_map<string, int> g_scores;

    int g_start = 0;
    int h_start = calulate_manhattan_distance(initState);

    open_set.emplace(initState, g_start, g_start + h_start);

    while (!open_set.empty()) {
        auto cur = open_set.top();
        open_set.pop();

        if (cur.g_state > g_scores[cur.state]) {
            continue;
        }

        if (cur.state == GOAL_STATE) {
            return cur.g_state;
        }

        for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
            if (i / GRID_SIZE < GRID_SIZE - 1) {
                string next_state = cur.state;
                swap(next_state[i], next_state[i + 1]);
                int next_g = cur.g_state + 1;
                if (g_scores.find(next_state) == g_scores.end() || g_scores[next_state] > next_g) {
                    g_scores[next_state] = next_g;
                    int next_h = calulate_manhattan_distance(next_state);
                    open_set.push({ next_state, next_g, next_g + next_h});
                }
            }

        }



    }


};

int main() {
    // T?ng t?c ?? nh?p xu?t
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ??c input
    string initial_state = "";
    char digit;
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i) {
        cin >> digit;
        initial_state += digit;
    }

    // G?i hàm gi?i và in k?t qu?
    cout << solve(initial_state) << endl;

    return 0;
}
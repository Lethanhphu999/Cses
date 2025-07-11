
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#ifndef ONLINE_JUDGE

#endif

class Node {
public:
    Node(int number, int child = 0) : _value(number), _count(child) {

    };

    void add(Node* node) {
        _child.emplace_back(node);
    }

public:
    int _value;
    int _count;
    std::vector<Node*> _child;
};

std::queue<Node*> que;

void dfs(Node* node) {
    for (auto child : node->_child) {
        dfs(child);
        node->_count += child->_count;
    }

}

void solve() {
    int n; cin >> n;
    std::vector<Node*> nodes(n);
    nodes[0] = new Node(1, 1);
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        nodes[i] = new Node(i);
        nodes[x - 1]->add(nodes[i]);
    }

    que.push(nodes[0]);

    for (auto& node : nodes) {
        cout << node->_count << " ";
    }
    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

#ifndef ONLINE_JUDGE
    //FILE* fin = nullptr;
    //FILE* fout = nullptr;
    //freopen_s(&fin, "input.txt", "r", stdin);
    //freopen_s(&fout, "output.txt", "r", stdout);
#endif

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

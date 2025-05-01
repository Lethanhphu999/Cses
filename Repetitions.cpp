#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int lengthmx = 1;
    int lengthcur = 1;
    char cur = ' ';
    for (int i = 0; i < s.size(); i++) {
        if(cur != s[i]) {
            cur = s[i];
            lengthcur = 1;
        } else {
            ++lengthcur;
            lengthmx = max(lengthmx, lengthcur);
        }
    }
    cout << lengthmx;
    return 0;
}
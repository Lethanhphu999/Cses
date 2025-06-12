#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;
    int n = s.length();

    // B?n ?? ?? chuy?n ??i ký t? sang ch? s? 0-3
    std::map<char, int> char_to_int;
    char_to_int['A'] = 0;
    char_to_int['C'] = 1;
    char_to_int['G'] = 2;
    char_to_int['T'] = 3;
    std::vector<char> int_to_char = { 'A', 'C', 'G', 'T' };

    // B??c 1: Ti?n x? lý - T?o b?ng next_char
    std::vector<std::vector<int>> next_char(n + 1, std::vector<int>(4, n));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            next_char[i][j] = next_char[i + 1][j];
        }
        next_char[i][char_to_int[s[i]]] = i;
    }

    // B??c 2: Quy ho?ch ??ng
    std::vector<int> dp(n + 2, 0);
    std::vector<char> choice(n + 1);

    for (int i = n; i >= 0; --i) {
        int min_len = n + 2; // Giá tr? vô cùng l?n
        char best_char = ' ';

        for (int j = 0; j < 4; ++j) {
            int current_len = 1 + dp[next_char[i][j] + 1];
            if (current_len < min_len) {
                min_len = current_len;
                best_char = int_to_char[j];
            }
        }
        dp[i] = min_len;
        choice[i] = best_char;
    }

    // B??c 3: Tái t?o k?t qu?
    std::string result = "";
    int current_pos = 0;
    while (current_pos <= n) {
        char c = choice[current_pos];
        result += c;
        int next_pos = next_char[current_pos][char_to_int[c]];
        if (next_pos == n) {
            break;
        }
        current_pos = next_pos + 1;
    }

    std::cout << result << std::endl;

    return 0;
}
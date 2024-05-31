#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int levenshteinDistance(const string& s1, const string& s2) {

    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({ dp[i - 1][j] + 1,
                                 dp[i][j - 1] + 1,
                                 dp[i - 1][j - 1] + 1 });
            }
        }
    }

    return dp[m][n];
}

int main() {
    setlocale(LC_ALL, "Rus");
    string s1, s2;

    cout << "Введите первое слово: ";
    cin >> s1;

    cout << "Введите второе слово: ";
    cin >> s2;

    int distance = levenshteinDistance(s1, s2);

    cout << "Расстояние Левенштейна между \"" << s1 << "\" è \"" << s2 << "\" равно " << distance << endl;

    return 0;
}

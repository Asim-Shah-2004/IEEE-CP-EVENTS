#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = n - 1;
    for (int i = 1; i + 1 < n; ++i) {
        if (s[i - 1] == s[i + 1]) {
            res--;
        }
    }
    cout << res << '\n';
}

int main(int argc, char* argv[]) {
    solve();   
}
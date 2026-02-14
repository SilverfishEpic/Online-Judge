#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int tc = 0;
    while (cin >> n) {
        vector<int> b(n);
        bool ok = true;

        for (int i = 0; i < n; ++i) cin >> b[i];

        // 1) 正整數 + 嚴格遞增
        if (b[0] <= 0) ok = false;
        for (int i = 1; i < n; ++i) {
            if (b[i] <= 0 || b[i] <= b[i-1]) ok = false;
        }

        // 2) 兩兩和唯一：用 O(1) 的 seen 陣列
        // 最大可能和 = b[n-1] + b[n-1]
        int maxSum = b.back() + b.back();
        vector<char> seen(maxSum + 1, 0);

        if (ok) {
            for (int i = 0; i < n && ok; ++i) {
                for (int j = i; j < n; ++j) {     // j 從 i 開始 => i<=j
                    int s = b[i] + b[j];
                    if (seen[s]) { ok = false; break; }
                    seen[s] = 1;
                }
            }
        }

        cout << "Case #" << ++tc << ": It is " << (ok ? "a" : "not a")
             << " B2-Sequence.\n\n";
    }
}

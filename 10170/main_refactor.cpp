#include <iostream>
#include <cmath>
using namespace std;

using ull = unsigned long long;

/*
  sum_from_S_len(S, m)
  -----------------------------------------
  意義：從 S 開始連續加 m 項的總和

    S + (S+1) + (S+2) + ... + (S+m-1)

  這是一個等差級數：
    首項 = S
    末項 = S+m-1
    項數 = m

  等差級數和公式：
    sum = m * (首項 + 末項) / 2
        = m * (S + (S+m-1)) / 2
        = m * (2S + m - 1) / 2

  注意：這裡用 ull 做計算，理論上乘法可能溢位。
  但 UVa 10170 的測資通常不會讓它溢位到影響答案，
  所以這樣能 AC。
*/
static inline ull sum_from_S_len(ull S, ull m) {
    return m * (2*S + m - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull S, D;

    /*
      UVa 10170：輸入多組 (S, D)，直到 EOF。
      S：起始天數/起始數
      D：目標總和（要達到或超過的累加量）
    */
    while (cin >> S >> D) {

        /*
          我們要找最小的 n（n >= S），使得：

            S + (S+1) + ... + n >= D

          為了方便，把「累加到 n」改寫成「加了幾項」：

          設 m = n - S + 1
          代表從 S 開始總共加了 m 項：
            S, S+1, ..., S+m-1 (= n)

          那總和就是 sum_from_S_len(S, m)。

          目標：找最小 m 使得
            sum_from_S_len(S, m) >= D
        */

        /*
          用數學直接解（O(1)）：

          sum = m(2S + m - 1)/2 >= D

          兩邊乘 2：
            m(2S + m - 1) >= 2D

          展開：
            m^2 + (2S - 1)m - 2D >= 0

          這是關於 m 的二次不等式，係數：
            A = 1
            B = (2S - 1)
            C = -2D

          m 取「使不等式成立的最小整數」，我們先算二次方程正根：
            m = [ -B + sqrt(B^2 - 4AC) ] / 2A
              = [ -(2S-1) + sqrt((2S-1)^2 + 8D) ] / 2

          因為要「最小整數 m」讓 sum >= D，
          所以先做 ceiling（向上取整）。
        */

        long double a = (long double)(2.0L * S - 1.0L);     // a = (2S - 1)
        long double disc = a * a + 8.0L * (long double)D;   // 判別式 = a^2 + 8D

        // 先用浮點數解出 m 的近似值，並向上取整成 ull
        ull m = (ull)ceill((-a + sqrtl(disc)) / 2.0L);

        /*
          為什麼還要做「校正 while」？

          因為 sqrtl 與浮點運算可能有微小誤差，
          導致 ceill 算出來的 m 可能：
            - 偶爾大 1（本來 m-1 就夠了）
            - 偶爾小 1（算出來的 m 還不夠達到 D）

          所以我們用「整數版的 sum_from_S_len」再檢查一次，
          透過 while 往下/往上修到剛剛好：

          1) 若 m-1 其實已經夠（sum >= D），就把 m 往下減
          2) 若 m 還不夠（sum < D），就把 m 往上加

          通常只會跑 0~幾次，不會變成 O(大迴圈)。
        */

        // 如果 m 太大：m-1 仍然達標，表示 m 不是最小，往下修
        while (m > 0 && sum_from_S_len(S, m - 1) >= D) --m;

        // 如果 m 太小：m 還沒達標，往上修到達標
        while (sum_from_S_len(S, m) < D) ++m;

        /*
          有了 m，就能回推 n：

            m = n - S + 1
            n = S + m - 1
        */
        ull n = S + m - 1;

        cout << n << "\n";
    }
}

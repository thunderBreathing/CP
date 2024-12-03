#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int, int> mii;

#define el "\n"
#define pb push_back
#define print_yes cout << "YES\n"
#define print_no cout << "NO\n"
#define print_ans cout << ans << el

const int INF = 1e9;
const ll LINF = 4e18;
const double EPS = 1e-9;

bool debug = false;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> carpet(n);

  for (int i = 0; i < n; i++) {
    cin >> carpet[i];
  }

  vector<vi> lists(n / 2);

  int row, col;
  for (int i = 0; i < n / 2; i++) {
    row = col = i;

    while ((int)lists[i].size() < (2 * (n + m - 4 * i - 2)) + 3) {
      lists[i].pb(carpet[row][col] - '0');
      if (row == i) {
        if (col != m - 1 - i) {
          col++;
        } else {
          row++;
        }
      } else if (row == n - i - 1) {
        if (col != i) {
          col--;
        } else {
          row--;
        }
      } else if (col == i) {
        if (row != i) {
          row--;
        } else {
          col++;
        }
      } else if (col == m - i - 1) {
        if (row != n - i - 1) {
          row++;
        } else {
          col--;
        }
      }
    }
  }

  int ans = 0;
  for (auto var : lists) {
    if (var.size() < 4) {
      continue;
    }

    // for (int i = 0; i < var.size(); i++) {
    //   cout << var[i];
    // }
    // cout << el;

    for (int i = 0; i < (int)var.size() - 3; i++) {
      if (var[i] * 1000 + var[i + 1] * 100 + var[i + 2] * 10 + var[i + 3] ==
          1543) {
        ans++;
      }
    }
  }
  print_ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

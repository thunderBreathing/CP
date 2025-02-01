#include <bits/stdc++.h>
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

void solve() {}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  char s[n + 2][n + 2], t[m + 2][m + 2];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t[i][j];
    }
  }

  int a, b;

  for (int i = 0; i < n - m + 1; i++) {
    for (int j = 0; j < n - m + 1; j++) {
      if (s[i][j] == t[0][0]) {
        a = i, b = j;
        bool not_found = false;

        for (int row = 0; row < m; row++) {
          for (int col = 0; col < m; col++) {
            if (t[row][col] != s[i + row][j + col]) {
              not_found = true;
              break;
            }
          }

          if (not_found) {
            break;
          }
        }

        if (!not_found) {
          cout << a + 1 << " " << b + 1 << el;
          return 0;
        }
      }
    }
  }

  return 0;
}

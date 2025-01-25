#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
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

vector<vi> soln;
vi one_case;
bool rows[8], p_diag[16], s_diag[16];

void generate_soln(int col) {
  if (col == 8) {
    soln.pb(one_case);
    return;
  }

  for (int i = 0; i < 8; i++) {
    if (rows[i] || p_diag[i + col] || s_diag[8 - i + col - 1])
      continue;
    one_case.pb(i);
    rows[i] = p_diag[i + col] = s_diag[8 - i + col - 1] = true;

    generate_soln(col + 1);

    one_case.pop_back();
    rows[i] = p_diag[i + col] = s_diag[8 - i + col - 1] = false;
  }
}

void solve() {
  int r, c;
  cin >> r >> c;
  int cnt = 0;

  for (auto var : soln) {
    if (var[c - 1] == r - 1) {
      cout << setw(2) << ++cnt << "      ";
      for (int i = 0; i < 8; i++) {
        cout << var[i] + 1;
        if (i != 7) {
          cout << " ";
        }
      }
      cout << el;
    }
  }
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  generate_soln(0);
  sort(soln.begin(), soln.end());

  int t;
  cin >> t;

  while (t--) {
    cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
    solve();
    if (t)
      cout << el;
  }

  return 0;
}

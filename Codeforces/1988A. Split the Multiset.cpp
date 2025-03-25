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

void solve() {
  int n, k;
  cin >> n >> k;
  int m = n;
  int ones = 0;

  int ans = 0;

  if (n == 1) {
    print_ans;
  } else if (k >= n) {
    ans++;
    print_ans;
  } else {
    for (int i = 0; i < m; i++) {
      ones += (k == n) ? k : k - 1;
      n -= k - 1;
      ans++;
      if (ones >= m) {
        break;
      }
    }
    print_ans;
  }
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

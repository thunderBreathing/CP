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

  int ans = 0;

  if (k == 0) {
    cout << "0\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    ans++;
    if (k <= n - i) {
      break;
    }

    k -= n - i;
    if (i != 0) {
      ans++;
      if (k <= n - i) {
        break;
      }
      k -= n - i;
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

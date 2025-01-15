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
  int n;
  cin >> n;

  vi a(n), b(n + 1);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n + 1; i++) {
    cin >> b[i];
  }

  ll ans = 0;
  int cpy = 2e9;
  for (int i = 0; i < n; i++) {
    ans += abs(a[i] - b[i]);

    if (b[n] <= max(a[i], b[i]) && b[n] >= min(a[i], b[i])) {
      cpy = 1;
    } else if (cpy != 1) {
      if (b[n] > max(a[i], b[i])) {
        cpy = min(cpy, (b[n] - max(a[i], b[i])) + 1);
      } else if (b[n] < min(a[i], b[i])) {
        cpy = min(cpy, (min(a[i], b[i]) - b[n]) + 1);
      }
    }
  }

  ans += cpy;

  print_ans;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

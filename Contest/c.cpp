#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<int, int> mii;

#define el "\n"
#define pb push_back
#define mp make_pair

const int INF = 1e9;
const ll LINF = 4e18;
const double EPS = 1e-9;

bool debug = false;

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);

  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);

  ll ans = 0;
  for (int i = n - 1; i >= 0; i -= 2) {
    if (i != 0) {
      ans += a[i] - a[i - 1];
      if (a[i] - a[i - 1] <= k) {
        k -= a[i] - a[i - 1];
        ans -= a[i] - a[i - 1];
      } else {
        ans -= k;
        k = 0;
      }
    } else {
      ans += a[i];
    }
  }

  printf("%lld\n", ans);
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int t;
  scanf("%d", &t);

  while (t--) {
    solve();
  }

  return 0;
}

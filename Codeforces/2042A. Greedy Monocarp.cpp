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

  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());

  int sum = a[0], ans;
  int idx;

  for (int i = 1; i < n; i++) {
    if (sum + a[i] <= k) {
      sum += a[i];
    } else {
      break;
    }
  }

  // if (sum < k) ans = k - sum;
  // else ans = (sum - k) < (k - sum + a[idx]) ? sum - k : k - sum + a[idx];

  ans = k - sum;

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

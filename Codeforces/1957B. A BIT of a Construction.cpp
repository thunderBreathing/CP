#include <bits/stdc++.h>
#include <cmath>
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

  if (n == 1) {
    cout << k << el;
    return;
  }

  int d;

  ll ara[32];
  for (int i = 0; i < 32; i++) {
    ara[i] = powl(2, i);
    if (k < ara[i]) {
      d = ara[i - 1] - 1;
      break;
    }
  }

  int a = d, b = k - d;
  cout << a << " " << b;

  for (int i = 2; i < n; i++) {
    cout << " 0";
  }
  cout << el;
}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

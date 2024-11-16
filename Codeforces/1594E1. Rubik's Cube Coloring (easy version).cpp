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

const int MOD = 1e9 + 7;

bool debug = false;

ll bigmod(ll t) {
  if (t == 0) {
    return 1;
  }
  if (t % 2 == 0) {
    return ((bigmod(t / 2) % MOD) * (bigmod(t / 2) % MOD)) % MOD;
  } else {
    return ((bigmod(t / 2) % MOD) * (bigmod(t / 2) % MOD) * 2) % MOD;
  }
}

void solve() {
  ll k;
  cin >> k;

  ll power_of_2 = 2 * (powl(2, k) - 2);

  ll ans = bigmod(power_of_2) % MOD;
  ans = (6 * ans) % MOD;
  print_ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}

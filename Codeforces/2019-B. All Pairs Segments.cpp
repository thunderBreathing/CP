#include <bits/stdc++.h>
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
  int n, q;
  cin >> n >> q;

  vi x;
  map<ll, ll> cnt;
  for (int i = 0; i < n; i++) {
    int xi;
    cin >> xi;
    x.pb(xi);
  }

  for (int i = 0; i < n; i++) {
    // process here
    // count appearance of numbers for each index and then the numbers in
    // between
    cnt[(ll)(n - i - 1) + (ll)(n - i) * i]++;
    if (i != n - 1)
      cnt[(ll)(n - i - 1) * (i + 1)] += x[i + 1] - x[i] - 1;
  }

  ll k;
  for (int i = 0; i < q; i++) {
    cin >> k;
    cout << cnt[k];
    if (i != q - 1)
      cout << " ";
  }
  cout << el;
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

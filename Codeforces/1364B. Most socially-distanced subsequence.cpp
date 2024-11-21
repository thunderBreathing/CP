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

  vi p(n);

  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  bool increasing, decreasing;

  increasing = p[0] < p[1];
  decreasing = p[0] > p[1];

  vi ans;
  ans.pb(p[0]);

  for (int i = 2; i < n; i++) {
    if (increasing && p[i - 1] > p[i]) {
      increasing = false;
      ans.pb(p[i - 1]);
    } else if (!increasing && p[i - 1] < p[i]) {
      increasing = true;
      ans.pb(p[i - 1]);
    }
  }

  ans.pb(p[n - 1]);

  cout << ans.size() << el;
  int cnt = 0;

  for (int var : ans) {
    cout << var;
    cnt++;

    if (cnt != (int)ans.size()) {
      cout << " ";
    }
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

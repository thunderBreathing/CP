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

  vi p(n + 1);
  for (int i = 1; i < n + 1; i++) {
    cin >> p[i];
  }

  vector<bool> visited(n + 1, false);
  vector<vi> ans;
  for (int i = 1; i < n + 1; i++) {
    if (visited[i]) {
      continue;
    }

    ans.pb(vi());
    int current = i;
    ans.back().pb(current);
    visited[current] = true;

    while (i != p[current]) {
      current = p[current];
      ans.back().pb(current);
      visited[current] = true;
    }
  }

  vi a(n + 1);

  for (auto var : ans) {
    for (auto u : var) {
      a[u] = var.size();
    }
  }

  for (int i = 1; i < n + 1; i++) {
    cout << a[i];
    if (i != n - 1) {
      cout << " ";
    } else {
      cout << el;
    }
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

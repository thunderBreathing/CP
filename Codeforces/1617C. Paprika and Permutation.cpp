#include <algorithm>
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

  vector<bool> a(n + 1, false);
  vi p;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x <= n && a[x] == false) {
      a[x] = true;
    } else {
      p.pb(x);
    }
  }

  if (p.empty()) {
    cout << "0\n";
    return;
  }

  sort(p.begin(), p.end());
  int ans = 0;

  for (int i = n; i > 0; i--) {
    if (a[i] == false) {
      if (ceil(p[p.size() - 1] / 2.0) <= i) {
        cout << "-1\n";
        return;
      } else {
        p.pop_back();
        ans++;
      }
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

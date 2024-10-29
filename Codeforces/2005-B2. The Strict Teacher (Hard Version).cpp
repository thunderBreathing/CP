#include <algorithm>
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
  int n, m, q;
  cin >> n >> m >> q;

  vi b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  int a, ans;
  for (int i = 0; i < q; i++) {
    cin >> a;

    if (a < b[0]) {
      ans = b[0] - 1;
    } else if (a > b[m - 1]) {
      ans = n - b[m - 1];
    } else {
      int start = 0;
      int end = m - 1;
      int mid;

      while (start < end) {
        mid = (start + end) / 2;

        if (b[mid] < a && a < b[mid + 1]) {
          break;
        } else if (b[mid] < a && b[mid + 1] < a) {
          start = mid;
        } else {
          end = mid;
        }
      }

      int wait = min(a - b[mid] - 1, b[mid + 1] - a - 1);
      // cout << wait << el;
      int dist = max(a - b[mid] - wait, b[mid + 1] - a - wait);
      // cout << dist << el;
      ans = ceil(dist / 2.0) + wait;
    }

    cout << ((ans == 0) ? 1 : ans) << el;
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

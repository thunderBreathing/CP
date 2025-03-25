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
  string r;
  cin >> r;

  char min = r[0], max = r[0];

  if (k == 0) {
    string rev = r;
    reverse(rev.begin(), rev.end());

    if (r < rev) {
      print_yes;
      return;
    } else {
      print_no;
      return;
    }
  }

  for (int i = 0; i < r.length(); i++) {
    if (min < r[i]) {
      min = r[i];
    }
    if (max > r[i]) {
      max = r[i];
    }
  }

  if (min == max) {
    print_no;
    return;
  }

  print_yes;
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

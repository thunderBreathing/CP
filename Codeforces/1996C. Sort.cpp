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

  string a, b;
  cin >> a >> b;

  vector<vi> prefix_sum_a(n, vi(26, 0)), prefix_sum_b(n, vi(26, 0));

  prefix_sum_a[0][a[0] - 'a'] = 1;
  prefix_sum_b[0][b[0] - 'a'] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      prefix_sum_a[i][j] = prefix_sum_a[i - 1][j];
      prefix_sum_b[i][j] = prefix_sum_b[i - 1][j];
    }
    prefix_sum_a[i][a[i] - 'a'] = prefix_sum_a[i - 1][a[i] - 'a'] + 1;
    prefix_sum_b[i][b[i] - 'a'] = prefix_sum_b[i - 1][b[i] - 'a'] + 1;
  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < 26; j++) {
  //     cout << prefix_sum_a[i][j] << " ";
  //   }
  //   cout << el;
  // }
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < 26; j++) {
  //     cout << prefix_sum_b[i][j] << " ";
  //   }
  //   cout << el;
  // }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;

    vi count_a(26, 0), count_b(26, 0);

    for (int j = 0; j < 26; j++) {
      count_a[j] =
          prefix_sum_a[r - 1][j] - ((l > 1) ? prefix_sum_a[l - 2][j] : 0);
      count_b[j] =
          prefix_sum_b[r - 1][j] - ((l > 1) ? prefix_sum_b[l - 2][j] : 0);
    }

    // for (int j = 0; j < 26; j++) {
    //   cout << count_a[j] << " ";
    // }
    // cout << el;
    // for (int j = 0; j < 26; j++) {
    //   cout << count_b[j] << " ";
    // }
    // cout << el;

    int ans = 0;
    for (int j = 0; j < 26; j++) {
      ans += (count_a[j] > count_b[j]) ? count_a[j] - count_b[j] : 0;
    }

    cout << ans << el;
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

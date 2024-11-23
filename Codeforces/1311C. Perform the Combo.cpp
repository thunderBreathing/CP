#include <bits/stdc++.h>
#include <string>
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
  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  vi p(m + 1);
  map<char, int> mci;

  for (int i = 0; i < n; i++) {
    mci[s[i]]++;
  }

  for (int i = 1; i < m + 1; i++) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());

  for (int i = 1, j = 0; i < m + 1; i++) {
    while (j < n && j < p[i]) {
      mci[s[j]] += m - i + 1;
      j++;
    }
  }

  // for (int i = m; i < n; i++) {
  //   mci[s[i]]++;
  // }

  for (int i = 'a'; i < 'z' + 1; i++) {
    cout << mci[i];
    if (i != 'z') {
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

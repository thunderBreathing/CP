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
  vi a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (a[0] == a[n - 1]) {
    print_no;
    return;
  }

  print_yes;

  vector<char> str(n + 1);
  str[0] = 'R';
  str[n - 1] = 'B';

  if (a[0] == a[1] && a[1] != a[n - 1]) {
    str[1] = str[n - 1];
    for (int i = 2; i < n - 1; i++) {
      str[i] = str[n - 1];
    }
  } else if (a[0] != a[1]) {
    if (a[1] == a[n - 1]) {
      str[1] = str[0];
    } else {
      str[1] = str[n - 1];
    }
    for (int i = 2; i < n - 1; i++) {
      str[i] = str[n - 1];
    }
  }

  for (int i = 2; i < n - 1; i++) {
  }

  for (int i = 0; i < n; i++) {
    cout << str[i];
  }
  cout << el;
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

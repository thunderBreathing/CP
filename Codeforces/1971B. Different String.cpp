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
  string s;
  cin >> s;

  for (int i = 0; i < (int)s.length() - 1; i++) {
    if (s[i] != s[i + 1]) {
      char temp = s[i];
      s[i] = s[i + 1];
      s[i + 1] = temp;
      print_yes;
      cout << s << el;
      return;
    }
  }

  print_no;
}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

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
  int n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  ii alice = {0, 0};

  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < n; j++) {
      if (s[j] == 'N') {
        alice.second++;
      } else if (s[j] == 'E') {
        alice.first++;
      } else if (s[j] == 'S') {
        alice.second--;
      } else if (s[j] == 'W') {
        alice.first--;
      }

      if (alice.first == a && alice.second == b) {
        print_yes;
        return;
      }
    }
  }

  print_no;
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

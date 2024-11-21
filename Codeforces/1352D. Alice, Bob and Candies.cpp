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

  int alice = a[0], bob = 0, move = 1;
  int alice_total = a[0], bob_total = 0;
  bool alice_move = false;
  int l = 1, r = n - 1;

  while (l <= r) {
    if (alice_move) {
      alice_total += a[l];
      alice += a[l];
      l++;

      if (alice > bob || l > r) {
        bob = 0;
        alice_move = false;
        move++;
      }
    } else {
      bob_total += a[r];
      bob += a[r];
      r--;

      if (bob > alice || l > r) {
        alice = 0;
        alice_move = true;
        move++;
      }
    }
  }

  cout << move << " " << alice_total << " " << bob_total << el;
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

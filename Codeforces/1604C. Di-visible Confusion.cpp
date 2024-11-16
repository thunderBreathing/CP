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
  int removable = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    if (a[i] % (i + 2) != 0) {
      removable++;
    } else {
      int divisor = i + 1;
      int removable_from_i = removable;

      while (removable_from_i) {
        if (a[i] % divisor == 0) {
          removable_from_i--;
          divisor--;
        } else {
          break;
        }
      }

      if (!removable_from_i) {
        print_no;
        return;
      }
    }
  }

  print_yes;
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

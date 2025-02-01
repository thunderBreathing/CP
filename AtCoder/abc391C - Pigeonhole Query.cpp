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

void solve() {}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  vi pigeon(n + 1), nests(n + 1, 1);

  for (int i = 1; i < n + 1; i++) {
    pigeon[i] = i;
  }

  int ans = 0;

  for (int i = 0; i < q; i++) {
    int a;
    cin >> a;

    if (a == 1) {
      int p, h;
      cin >> p >> h;

      nests[pigeon[p]]--;
      if (nests[pigeon[p]] == 1 && ans > 0)
        ans--;
      pigeon[p] = h;
      nests[h]++;
      if (nests[h] == 2)
        ans++;

    } else if (a == 2) {
      cout << ans << el;
    }
  }

  return 0;
}

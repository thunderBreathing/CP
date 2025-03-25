#include <bits/stdc++.h>
#include <cmath>
#include <vector>
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

vector<vi> pegs;

void generate_soln(int n) {
  if (pegs.size() == 50)
    return;
  for (auto var : pegs) {
    if (ceil(sqrt(var[var.size() - 1] + n)) ==
        floor(sqrt(var[var.size() - 1] + n))) {
      var.pb(n);
      generate_soln(++n);
    }
  }
}

void solve() {
  int n;
  cin >> n;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  generate_soln(1);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

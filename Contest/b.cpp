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

void solve() {}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int n;
  cin >> n;
  vector<vi> list(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int x;
      cin >> x;
      list[i].pb(x);
    }
  }

  int element = list[0][0];

  for (int i = 2; i <= n; i++) {
    if (element >= i) {
      element = list[element - 1][i - 1];
    } else {
      element = list[i - 1][element - 1];
    }
  }

  cout << element << el;

  return 0;
}

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

  int l, r;
  cin >> l >> r;

  if ((l == 0 && r == 0) || (l == 1 && r == 1)) {
    cout << "Invalid\n";
  } else if (l == 1) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}

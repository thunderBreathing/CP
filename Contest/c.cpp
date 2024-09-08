#include <algorithm>
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
#define mp make_pair

const int INF = 1e9;
const ll LINF = 4e18;
const double EPS = 1e-9;

bool debug = false;

void solve() {}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  string s, t;
  cin >> s;
  cin >> t;

  vector<string> x;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] != t[i]) {
      s[i] = t[i];
      x.pb(s);
    }
  }

  sort(x.begin(), x.end());

  cout << x.size() << el;

  for (int i = 0; i < x.size(); i++) {
    cout << x[i] << el;
  }

  return 0;
}

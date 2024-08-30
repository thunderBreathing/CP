#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <unordered_set>
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

void solve() {
  int n;
  scanf("%d", &n);
  unordered_map<string, int> um;
  int best = 0;

  for (int i = 0; i < n; i++) {
    vi temp;
    for (int i = 0; i < 5; i++) {
      int x;
      scanf("%d", &x);
      temp.pb(x);
    }
    sort(temp.begin(), temp.end());

    string key = "";

    for (int i = 0; i < 5; i++) {
      key += to_string(temp[i]);
    }
    um[key]++;
    best = max(best, um[key]);
  }

  unordered_map<string, int>::iterator it = um.begin();
  int cnt = 0;

  while (it != um.end()) {
    if (it->second == best) {
      cnt += best;
    }
    it++;
  }

  printf("%d\n", cnt);
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  solve();

  return 0;
}

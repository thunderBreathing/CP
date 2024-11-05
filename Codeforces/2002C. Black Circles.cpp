#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
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
  cin >> n;

  vii xy(n);
  for (int i = 0; i < n; i++) {
    cin >> xy[i].first >> xy[i].second;
  }

  int xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;

  long double dist = sqrtl((long double)(xs - xt) * (long double)(xs - xt) +
                           (long double)(ys - yt) * (long double)(ys - yt));

  long double dist_from_target[n];

  for (int i = 0; i < n; i++) {
    dist_from_target[i] = sqrt(
        (long double)(xy[i].first - xt) * (long double)(xy[i].first - xt) +
        (long double)(xy[i].second - yt) * (long double)(xy[i].second - yt));

    // printf("%0.30lf %0.30lf\n", dist_from_target[i], dist);
    if (dist_from_target[i] <= dist) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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

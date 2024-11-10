#include <bits/stdc++.h>
#include <cstdio>
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
#define print_yes cout << "YES\n"
#define print_no cout << "NO\n"

const int INF = 1e9;
const ll LINF = 4e18;
const double EPS = 1e-9;

bool debug = false;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  string s;
  cin >> s;

  int start = -1, swam = 0;
  bool currently_swimming = false;

  while (start < n + 1) {
    if (currently_swimming) {
      start++;
      if (start >= n) {
        print_yes;
        return;
      } else if (s[start] == 'W') {
        swam++;
        if (swam > k) {
          print_no;
          return;
        }
      } else if (s[start] == 'L') {
        currently_swimming = false;
      } else {
        print_no;
        return;
      }
    } else {
      bool log_found = false;
      int furthest_water_at = -1;

      for (int i = 1; i < m + 1; i++) {
        if (start + i >= n) {
          print_yes;
          return;
        } else if (s[start + i] == 'L') {
          start = start + i;
          log_found = true;
          break;
        } else if (s[start + i] == 'W') {
          furthest_water_at = start + i;
        }
      }

      if (!log_found) {
        if (furthest_water_at == -1) {
          print_no;
          return;
        } else {
          start = furthest_water_at;
          currently_swimming = true;
          swam++;
          if (swam > k) {
            print_no;
            return;
          }
        }
      }
    }
  }
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

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
  ll sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if (sum % n != 0) {
    print_no;
    return;
  }

  int avg = sum / n;

  for (int i = 1; i < n - 1; i++) {
    if (a[i - 1] >= avg) {
      a[i - 1] -= a[i - 1] - avg;
      a[i + 1] += a[i - 1] + avg;
    } else {
      if (avg - a[i - 1] > a[i + 1]) {
        print_no;
        return;
      } else {
        a[i - 1] += avg - a[i - 1];
        a[i + 1] -= avg - a[i - 1];
      }
    }

    if (i == n - 2 && a[i] != a[i - 1]) {
      print_no;
      return;
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

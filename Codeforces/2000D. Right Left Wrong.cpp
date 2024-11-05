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

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n, 0);
  cin >> a[0];
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    a[i] = a[i - 1] + x;
  }

  string s;
  cin >> s;

  ll sum = 0;
  int start = s.length(), end = 0;
  for (int i = 0; i < (int)s.length(); i++) {
    if (s[i] == 'L') {
      start = i;
      break;
    }
  }
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == 'R') {
      end = i;
      break;
    }
  }

  if (start < (int)s.length() && end > 0) {
    sum = a[end] - ((start > 0) ? a[start - 1] : 0);
  }

  start++, end--;
  while (start < end) {
    if (s[start] != 'L') {
      start++;
    }
    if (s[end] != 'R') {
      end--;
    }
    if (s[start] == 'L' && s[end] == 'R') {
      sum += a[end] - a[start - 1];
      end--;
      start++;
    }
  }

  cout << sum << el;
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

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

  vi a(n), count_a(n + 1);
  int smallest = 1e6;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    count_a[a[i]]++;
    smallest = min(smallest, a[i]);
  }

  if (smallest != 0) {
    cout << n << el;
    for (int i = 1; i < n + 1; i++) {
      cout << i << " " << i << el;
    }
    return;
  }

  int mex;
  for (int i = 0; i <= n; i++) {
    if (count_a[i] == 0) {
      mex = i;
      // cout << mex << el;
      break;
    }
  }

  vii indices;
  unordered_set<int> num;
  int k = 0, starting_index = 1;

  for (int i = 0; i < n; i++) {
    if (a[i] < mex) {
      if ((int)num.size() == mex) {
        k++;
        indices.pb({starting_index, i});
        starting_index = i + 1;
        num.clear();
        num.insert(a[i]);
      } else {
        num.insert(a[i]);
      }
      if (i == n - 1) {
        if ((int)num.size() == mex) {
          k++;
          indices.pb({starting_index, i + 1});
        } else if (k > 1) {
          indices[indices.size() - 1].second = n;
        }
      }
    } else if (i == n - 1) {
      if ((int)num.size() == mex) {
        k++;
        indices.pb({starting_index, i + 1});
      } else if (k > 1) {
        indices[indices.size() - 1].second = n;
      }
    }
  }

  if (k < 2) {
    cout << "-1\n";
  } else {
    cout << k << el;
    for (auto var : indices) {
      cout << var.first << " " << var.second << el;
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

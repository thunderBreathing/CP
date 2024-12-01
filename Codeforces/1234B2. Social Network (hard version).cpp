#include <bits/stdc++.h>
#include <queue>
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
  int n, k;
  cin >> n >> k;

  vi id(n);
  for (int i = 0; i < n; i++) {
    cin >> id[i];
  }

  queue<int> q;
  vector<bool> present(1e9 + 1, false);

  for (int i = 0; i < n; i++) {
    if (!present[id[i]]) {
      if (q.size() == k) {
        int x = q.front();
        present[x] = false;
        q.pop();
      }
      q.push(id[i]);
      present[id[i]] = true;
    }
  }

  vi ans;
  cout << q.size() << el;
  while (!q.empty()) {
    int x = q.front();
    ans.pb(x);
    q.pop();
  }

  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i];
    if (i != 0) {
      cout << " ";
    } else {
      cout << el;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}

#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
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
  int n, k;
  scanf("%d %d", &n, &k);

  priority_queue<tuple<int, int, int, int, string>> min_heap;

  for (int i = 0; i < n; i++) {
    string name;
    int interval;
    cin >> name >> interval;
    // cout << name << " " << interval << el;

    min_heap.push({interval * -1, i * -1, 1, interval * -1, name});
  }

  for (int i = 0; i < k; i++) {
    auto [interval, priority, multiple, mean, name] = min_heap.top();
    min_heap.pop();

    cout << interval * -1 << " " << name << el;

    min_heap.push({mean * (multiple + 1), priority, multiple + 1, mean, name});
  }
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int t;
  scanf("%d", &t);

  while (t--) {
    solve();
  }

  return 0;
}

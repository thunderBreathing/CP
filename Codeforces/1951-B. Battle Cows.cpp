#include <algorithm>
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
  int n, k;
  cin >> n >> k;
  k--;

  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int index_of_first_ai_greater_than_ak = -1;
  int index_of_second_ai_greater_than_ak = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] > a[k]) {
      if (index_of_first_ai_greater_than_ak == -1) {
        index_of_first_ai_greater_than_ak = i;
      } else {
        index_of_second_ai_greater_than_ak = i;
        break;
      }
    }
  }

  int ans;
  // cout << index_of_first_ai_greater_than_ak << " "
  //      << index_of_second_ai_greater_than_ak << el;

  if (index_of_first_ai_greater_than_ak == -1) {
    ans = n - 1;
  } else if (index_of_second_ai_greater_than_ak == -1) {
    if (index_of_first_ai_greater_than_ak > k) {
      ans = index_of_first_ai_greater_than_ak - 1;
    } else {
      ans = max(index_of_first_ai_greater_than_ak - 1,
                k - ((index_of_first_ai_greater_than_ak == 0)
                         ? 1
                         : index_of_first_ai_greater_than_ak));
    }
  } else {
    ans = max(((index_of_first_ai_greater_than_ak == 0)
                   ? 1
                   : index_of_first_ai_greater_than_ak) -
                  1,
              min(index_of_second_ai_greater_than_ak -
                      ((index_of_first_ai_greater_than_ak == 0)
                           ? 1
                           : index_of_first_ai_greater_than_ak),
                  k - ((index_of_first_ai_greater_than_ak == 0)
                           ? 1
                           : index_of_first_ai_greater_than_ak)));
  }

  cout << ans << el;
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

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

void solve() {}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  string dir;
  cin >> dir;

  char a = dir[0];
  if (a == 'S')
    cout << "N";
  else if (a == 'N')
    cout << "S";
  else if (a == 'W')
    cout << "E";
  else
    cout << "W";

  if (dir.length() == 1) {
    cout << el;
  } else {
    a = dir[1];
    if (a == 'S')
      cout << "N";
    else if (a == 'N')
      cout << "S";
    else if (a == 'W')
      cout << "E";
    else
      cout << "W";
    cout << el;
  }

  return 0;
}

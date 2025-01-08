#include <bits/stdc++.h>
#include <string>
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
  string number;
  cin >> number;

  int len = number.length();

  int sum, two, three;
  sum = two = three = 0;

  for (int i = 0; i < len; i++) {
    sum += number[i] - '0';

    if (number[i] == '2') two++;
    else if (number[i] == '3') three++;
  }

  for (int i = 0; i <= two; i++) {
    for (int j = 0; j <= three; j++) {
      if ((sum + 2 * i + 6 * j) % 9 == 0) {
        print_yes;
        return;
      }
    }
  }

  print_no;
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

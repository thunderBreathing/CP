#include <algorithm>
#include <cstdio>
#include <functional>
#include <map>
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

void find_sum(int ara1[], int ara2[], int result[], int k) {
  priority_queue<ii, vector<ii>, greater<ii>> min_heap;

  for (int i = 0; i < k; i++) {
    min_heap.push({ara1[i] + ara2[0], 0});
  }

  int count = 0;

  while (!min_heap.empty()) {
    ii current = min_heap.top();
    min_heap.pop();

    result[count++] = current.first;

    if (current.second + 1 < k) {
      min_heap.push(
          {current.first - ara2[current.second] + ara2[current.second + 1],
           current.second + 1});
    }

    if (count == k) {
      break;
    }
  }
}

void solve(int k) {
  int ara1[k], ara2[k];

  for (int i = 0; i < k; i++) {
    scanf("%d", &ara1[i]);
  }
  sort(ara1, ara1 + k);

  for (int i = 1; i < k; i++) {
    for (int j = 0; j < k; j++) {
      scanf("%d", &ara2[j]);
    }
    sort(ara2, ara2 + k);
    find_sum(ara1, ara2, ara1, k);
  }

  printf("%d", ara1[0]);

  for (int i = 1; i < k; i++) {
    printf(" %d", ara1[i]);
  }

  printf("\n");
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int n;
  while (~scanf("%d", &n)) {
    solve(n);
  }

  return 0;
}

/*
ID: mehranh1
TASK: sprime
LANG: C++
*/

#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
#include <iostream>

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

int n;

ll _sieve_size;
bitset<10000010> bs;
vi p;

void sieve(int upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i < _sieve_size; i++)
    if (bs[i]) {
      for (ll j = i * i; j <= _sieve_size; j += i) {
        bs[j] = 0;
      }
      p.pb((int)i);
    }
}

bool isPrime(int N) {
  if (N < _sieve_size) {
    return bs[N];
  }
  for (int i = 0; i < (int)p.size() && (ll)p[i] * (ll)p[i] <= (ll)N; i++) {
    if (N % p[i] == 0)
      return false;
  }
  return true;
}

vi ans;

void gen_num(int num) {
  if (num >= pow(10, n - 1) && num < pow(10, n)) {
    ans.pb(num);
  }

  for (int i = 1; i < 10; i += 2) {
    num = num * 10 + i;
    if (isPrime(num)) {
      gen_num(num);
    }
    num = num / 10;
  }
}

void solve() {
  gen_num(2);
  gen_num(3);
  gen_num(5);
  gen_num(7);
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  sieve(10000000);

  ifstream fin("sprime.in");

  fin >> n;
  // cin >> n;
  fin.close();

  solve();

  ofstream fout("sprime.out");
  for (int var : ans) {
    fout << var << el;
    // cout << var << el;
  }
  fout.close();

  return 0;
}

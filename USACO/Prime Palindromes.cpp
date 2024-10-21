/*
ID: mehranh1
TASK: pprime
LANG: C++
*/

#include <bits/stdc++.h>
#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>

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

typedef vector<int> vint;

bool debug = false;

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

bool isPrime(int palindrome) {
  if (palindrome < _sieve_size) {
    return bs[palindrome];
  }
  for (int i = 0; i < (int)p.size() && (ll)p[i] * (ll)p[i] <= (ll)palindrome;
       i++) {
    if (palindrome % p[i] == 0)
      return false;
  }
  return true;
}

void solve(int a, int b) {
  ofstream fout("pprime.out");
  sieve(10000000);
  int palindrome = 0;

  if (a < 10)
    for (int d1 = a; d1 <= 9; d1 += 2) {
      palindrome = d1;
      if (palindrome > b)
        return;
      if (isPrime(palindrome))
        fout << palindrome << el;
    }
  if (a < 100 && b > 9)
    for (int d1 = 1; d1 <= 9; d1 += 2) {
      palindrome = d1 * 10 + d1;
      if (palindrome > b)
        return;
      if (palindrome < a)
        continue;
      if (isPrime(palindrome))
        fout << palindrome << el;
    }
  if (a < 1000 && b > 99)
    for (int d1 = 1; d1 <= 9; d1 += 2) {
      for (int d2 = 0; d2 <= 9; d2 += 1) {
        palindrome = d1 * 100 + d2 * 10 + d1;
        if (palindrome > b)
          return;
        if (palindrome < a)
          continue;
        if (isPrime(palindrome))
          fout << palindrome << el;
      }
    }
  if (a < 10000 && b > 999)
    for (int d1 = 1; d1 <= 9; d1 += 2) {
      for (int d2 = 0; d2 <= 9; d2 += 1) {
        palindrome = d1 * 1000 + d2 * 100 + d2 * 10 + d1;
        if (palindrome > b)
          return;
        if (palindrome < a)
          continue;
        if (isPrime(palindrome))
          fout << palindrome << el;
      }
    }
  if (a < 100000 && b > 9999)
    for (int d1 = 1; d1 <= 9; d1 += 2) {
      for (int d2 = 0; d2 <= 9; d2 += 1) {
        for (int d3 = 0; d3 <= 9; d3 += 1) {
          palindrome = d1 * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1;
          if (palindrome > b)
            return;
          if (palindrome < a)
            continue;
          if (isPrime(palindrome))
            fout << palindrome << el;
        }
      }
    }
  if (a < 1000000 && b > 99999)
    for (int d1 = 1; d1 <= 9; d1 += 2) {
      for (int d2 = 0; d2 <= 9; d2 += 1) {
        for (int d3 = 0; d3 <= 9; d3 += 1) {
          palindrome =
              d1 * 100000 + d2 * 10000 + d3 * 1000 + d3 * 100 + d2 * 10 + d1;
          if (palindrome > b)
            return;
          if (palindrome < a)
            continue;
          if (isPrime(palindrome))
            fout << palindrome << el;
        }
      }
    }
  if (a < 10000000 && b > 999999)
    for (int d1 = 1; d1 <= 9; d1 += 2) {
      for (int d2 = 0; d2 <= 9; d2 += 1) {
        for (int d3 = 0; d3 <= 9; d3 += 1) {
          for (int d4 = 0; d4 <= 9; d4 += 1) {
            palindrome = d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 +
                         d3 * 100 + d2 * 10 + d1;
            if (palindrome > b)
              return;
            if (palindrome < a)
              continue;
            if (isPrime(palindrome))
              fout << palindrome << el;
          }
        }
      }
    }
  if (a < 100000000 && b > 9999999)
    for (int d1 = 1; d1 <= 9; d1 += 2) {
      for (int d2 = 0; d2 <= 9; d2 += 1) {
        for (int d3 = 0; d3 <= 9; d3 += 1) {
          for (int d4 = 0; d4 <= 9; d4 += 1) {
            palindrome = d1 * 10000000 + d2 * 1000000 + d3 * 100000 +
                         d4 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
            if (palindrome > b)
              return;
            if (palindrome < a)
              continue;
            if (isPrime(palindrome))
              fout << palindrome << el;
          }
        }
      }
    }
  if (a < 1000000000 && b > 99999999)
    for (int d1 = 1; d1 <= 9; d1 += 2) {
      for (int d2 = 0; d2 <= 9; d2 += 1) {
        for (int d3 = 0; d3 <= 9; d3 += 1) {
          for (int d4 = 0; d4 <= 9; d4 += 1) {
            for (int d5 = 0; d5 <= 9; d5 += 1) {
              palindrome = d1 * 100000000 + d2 * 10000000 + d3 * 1000000 +
                           d4 * 100000 + d5 * 10000 + d4 * 1000 + d3 * 100 +
                           d2 * 10 + d1;
              if (palindrome > b)
                return;
              if (palindrome < a)
                continue;
              if (isPrime(palindrome))
                fout << palindrome << el;
            }
          }
        }
      }
    }
  fout.close();
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NUint);

  ifstream fin("pprime.in");

  int a, b;
  fin >> a >> b;
  cin >> a >> b;

  fin.close();

  solve(a, b);

  return 0;
}

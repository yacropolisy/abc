#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

// mod_nck(n, k) → nCk // O(n)
// 1. mod_fact(n); mod_inv_fact(n);
// 2. ll ans = mod_nck(n,k);

const ll MAX_N = 200000;
ll fact[MAX_N+1], inv_fact[MAX_N+1];

ll mod_pow(ll x, ll y){
  ll res = 1;
    while (y) {
        if (y & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        y >>= 1;
    }
  return res;
}

void mod_fact(ll n){
  fact[0] = 1;
  REP(i,n)fact[i+1] = fact[i] * (i+1) % MOD;
}

void mod_inv_fact(ll n){
  inv_fact[n] = mod_pow(fact[n], (MOD-2));
  REP(i,n){
    inv_fact[n-1-i] = inv_fact[n-i] * (n-i) % MOD;
  }
}

ll mod_comb(int n, int k){
  return fact[n] * inv_fact[k] % MOD * inv_fact[n-k] % MOD ;
}


int main(){
  ll n, k;
  cin >> n >> k;
  mod_fact(n+k-1); mod_inv_fact(n+k-1);
  ll ans = mod_comb(n+k-1,k);

  cout << ans << endl;

  return 0;
}

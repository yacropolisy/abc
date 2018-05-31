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

// bit_sum O(log n) for a query
// 1. set n;
// 2. init bit[n+1];

const int MAX_N = 100000;

ll bit[MAX_N+2], n;

ll bit_sum(int i){
  ll s = 0;
  while(i > 0){
    s = (s +  bit[i]) % MOD;
    i -= i & -i;
  }
  return s;
}

void bit_add(int i, ll x){
  while(i <= n){
    bit[i] = (bit[i] + x) % MOD ;
    i += i & -i;
  }
}



int main(){
  int m;
  cin >> n >> m;
  ll f[n];
  REP(i,n) cin >> f[i];

  n += 2;

  REP(i,n+2) bit[i] = 0;

  bit_add(1,1);

  int l[m];
  REP(i,m) l[i] = 0;
  int last = 0;

  REP(i,n-2){
    last = max(last, l[f[i]-1]);
    bit_add(i+2, (bit_sum(i+1) - bit_sum(last) + MOD ) % MOD);
    l[f[i]-1] = i+1;
  }



  cout << (bit_sum(n-1) - bit_sum(n-2) + MOD) % MOD << endl;




  return 0;
}

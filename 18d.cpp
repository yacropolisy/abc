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

ll gcd(ll x, ll y){
  if(x == 0)return y;
  return gcd(y%x, x);
}


int main(){
  int n, m, p, q, r;
  cin >> n >> m >> p >> q >> r;
  int x[r], y[r];
  ll z[r];
  REP(i,r){
    cin >> x[i] >> y[i] >> z[i];
    x[i]--;
    y[i]--;
  }
  vi happy(m);

  ll comb = (1 << p) -1;
  ll ans = 0;
  while(comb < 1 << n){
    REP(i, m) happy[i] = 0;
    REP(i, n){
      if (1 << i & comb){
        REP(j,r){
          if(x[j] == i) happy[y[j]] += z[j];
        }
      }
    }

    sort(ALL(happy), greater<int>());
    ll tmp = 0;
    REP(i,q){
      tmp += happy[i];
    }

    ans = max(ans, tmp);

    ll x = comb & -comb;
    ll y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
  }

  cout << ans << endl;

  return 0;
}

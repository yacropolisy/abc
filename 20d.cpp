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
  ll n, k;
  cin >> n >> k;

  ll g[k];
  REP(i,k){
    g[i] = gcd(i,k);
  }


  ll ans = 0;
  ll m = n % k;
  ll l = n / k;
  REP(i,m+1){
    ans = (ans + (i + (l) * k / 2 ) * (l + 1) / g[i] % MOD * k ) % MOD;
  }
  REP(i, min(n,k)-m-1){
    ans = (ans + (i+m+1 + (l -1) * k / 2 ) * (l) / g[i+m+1] % MOD * k ) % MOD;
  }



  cout << ans << endl;

  return 0;
}

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

int main(){
  ll a, b, c;
  cin >> a >> b >> c;
  ll r = 0, cc = 0;

  ll bunbo = (b * c % MOD + 2 * MOD - a * b % MOD - a * c % MOD) % MOD;
  ll inv = mod_pow(bunbo, (MOD-2));

  ll rbunshi = (a * c % MOD - b * c % MOD + MOD) % MOD;
  ll ccbunshi = (a * b % MOD - b * c % MOD + MOD) % MOD;


  r = rbunshi * inv % MOD;
  cc = ccbunshi * inv % MOD;

  cout << r << " " << cc << endl;

  return 0;
}

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

int main(){
  ll n;
  cin >> n;
  ll h[n], s[n];
  ll maxh = 0;
  ll maxs = 0;
  REP(i,n){
    cin >> h[i] >> s[i];
    maxh = max(maxh, h[i]);
    maxs = max(maxs, s[i]);
  }
  ll lb = maxh;
  ll ub = maxh * maxs * n;

  while(ub - lb > 1){
    ll mid = (ub + lb) / 2;
    ll k[n];
    REP(i,n){
       k[i] = (mid - h[i]) / s[i];
       if(k[i] > n) k[i] = n;
    }
    sort(k, k+n);
    bool flag = true;
    REP(i,n){
      if(k[i] < i) flag = false;
    }
    if(flag) ub = mid;
    else lb = mid;

  }

  cout << ub << endl;


  return 0;
}

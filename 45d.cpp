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
  ll h, w, n;
  cin >> h >> w >> n;
  ll a[n], b[n];
  map<pi, int> mp;
  REP(i,n){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    REP(j,min(a[i],2ll)+1){
      REP(k,min(b[i],2ll)+1){
        if(a[i]-j >= h-2 || b[i]-k >= w-2)continue;
        mp[pi(a[i]-j, b[i]-k)]++;
      }
    }
  }
  ll ans[10];
  REP(i,10) ans[i] = 0;
  ans[0] = (h-2) * (w-2);
  for(auto &p:mp){
    ans[p.second]++;
    ans[0]--;
    // cout << p.first.first << ", " << p.first.second << endl;
  }

  REP(i,10){
    cout << ans[i] << endl;
  }

  return 0;
}

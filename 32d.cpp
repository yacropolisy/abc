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

  ll n, W;
  cin >> n >> W;
  ll v[n], w[n];
  ll vmax = 0, wmax = 0;
  REP(i,n){
    cin >> v[i] >> w[i];
    vmax = max(vmax, v[i]);
    wmax = max(wmax, w[i]);
  }
  if(wmax <= 1000){
    W = min(W, wmax * n);
    ll dp[n+1][W+1];
    REP(i,n+1)REP(j,W+1) dp[i][j] = 0;
    dp[0][0] = 0;
    REP(i,n){
      REP(j,W+1){
        if(j >= w[i]) dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
        else dp[i+1][j] = dp[i][j];
      }
    }
    cout << dp[n][W] << endl;

  }else if(vmax <= 1000){
    static ll dp[201][200 * 1000+1];
    REP(i,n+1)REP(j,n * 1000+1) dp[i][j] = INFll;
    dp[0][0] = 0;
    REP(i,n){
      REP(j,n * 1000+1){
        if(j >= v[i]) dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]] + w[i]);
        else dp[i+1][j] = dp[i][j];
      }
    }
    ll ans = 0;
    REP(i,n+1){
      REP(j,n * 1000+1){
        if(dp[i][j] <= W) ans = max(ans, ll(j));
      }
    }
    cout << ans << endl;
  }else{
    pll vf[1 << n/2];
    REP(i, 1 << n/2){
      ll tv = 0;
      ll tw = 0;
      REP(j, n/2){
        if(1 << j & i){
          tv += v[j];
          tw += w[j];
        }
      }
      vf[i] = pll(tw, tv);
    }

    sort(vf, vf + (1 << n/2));
    int m = 1;
    for (int i = 1; i < 1 << n/2; i++){
      if(vf[m-1].second < vf[i].second){
        vf[m++] = vf[i];
      }
    }
    ll ans = 0;

    REP(i, 1 << (n - n/2)){
      ll tv = 0;
      ll tw = 0;
      REP(j, n - n/2){
        if(1 << j & i){
          tv += v[j + n/2];
          tw += w[j + n/2];
        }
      }
      if(tw <= W) ans = max(ans, tv + (upper_bound(vf, vf+m, pll(W - tw, INFll)) - 1 ) -> second);
    }
    cout << ans << endl;
  }

  return 0;
}

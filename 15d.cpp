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
  int w, n, k;
  cin >> w >> n >> k;
  int a[n], b[n];
  REP(i,n) cin >> a[i] >> b[i];
  int dp[n+1][k+1][w+1];
  REP(j,k+1)REP(l, w+1) dp[0][j][l] = 0;
  REP(i,n+1)REP(l, w+1) dp[i][0][l] = 0;

  REP(i,n){
    REP(j,k){
      REP(l,w+1){
        dp[i+1][j+1][l] = dp[i][j+1][l];
        if(a[i] <= l) dp[i+1][j+1][l] = max(dp[i+1][j+1][l], dp[i][j][l-a[i]] + b[i]);
      }
    }
  }

  int ans = 0;
  REP(i,k){
    ans = max(dp[n][i+1][w], ans);
  }

  cout << ans << endl;

  return 0;
}

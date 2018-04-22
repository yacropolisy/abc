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
  int n, ma, mb;
  cin >> n >> ma >> mb;
  int a[n], b[n], c[n];
  REP(i,n)cin >> a[i] >> b[i] >> c[i];

  int dp[41][401][401];
  REP(k,41)REP(i,401)REP(j,401)dp[k][i][j] = INFi;

  // REP(k,n)dp[k][0][0] = 0;

  // REP(k,n){
  //   REP(i,401){
  //     REP(j,401){
  //       if(i >= a[k] && j >= b[k]){
  //         dp[k+1][i][j] = min(dp[k][i-a[k]][j-b[k]] + c[k], dp[k][i][j]);
  //       }else{
  //         dp[k+1][i][j] = dp[k][i][j];
  //       }
  //     }
  //   }
  // }
  //
  // int ans = INFi;
  // for(int i = 1; i * (max(ma,mb)) <= 400; i++ ){
  //   // if( dp[n][i*ma][i*mb]!= INFi)cout << "i " << i << endl;
  //   ans = min(ans, dp[n][i*ma][i*mb]);
  // }
  //
  // if(ans == INFi){
  //   cout << -1 << endl;
  // }else{
  //   cout << ans << endl;
  // }

  return 0;
}

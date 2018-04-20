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
  ll n, k;
  cin >> n >> k;
  ll a[n];
  REP(i,n)cin >> a[i];

  bool dp1[n+1][k+1];
  // bool dp2[n+1][k+1];

  sort(a,a+n);

  int lb = -1, ub = lower_bound(a, a+n, k) - a;
  while(ub - lb > 1){
    int mid = (ub + lb) / 2;
    REP(i,n+1)REP(j,k+1){
      dp1[i][j] = false;
      // dp2[i][j] = true;
    }
    dp1[0][0] = true;
    // dp2[0][0] = true;

    REP(i,n){
      REP(j,k+1){
        if(i == mid){
          dp1[i+1][j] = dp1[i][j];
        }else{
          dp1[i+1][j] = dp1[i][j];
          if(j >= a[i] && dp1[i][j-a[i]]) dp1[i+1][j] = true;
        }
        // dp2[i+1][j] = dp1[i][j];
        // if(j >= a[n-1-i] || dp2[i][j - a[n-1-i]]) dp2[i+1][j] = true;
      }
    }

    // if(mid == 0){
    //   REP(i,n+1){
    //     REP(j,k+1){
    //       cout << "dp" << i << j << " : " << dp1[i][j] << ",";
    //     }
    //     cout << endl;
    //   }
    // }

    bool flag = false;
    REP(i,a[mid]){
      if(dp1[n][k-1-i])flag = true;
      // if(mid == 0)cout << "yes " <<  i << endl;
    }
    if(flag)ub = mid;
    else lb = mid;

    // cout << mid << endl;
  }

  cout << lb + 1 << endl;


  return 0;
}

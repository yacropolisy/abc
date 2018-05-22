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
  int x;
  int mp[25];
  REP(i,25) mp[i] = -1;

  REP(i,5)REP(j,5){
    cin >> x;
    if(x > 0) mp[x-1] = 5 * i + j;
  }

  static int dp[1<<25];
  REP(i,1<<25) dp[i] = 0;
  dp[0] = 1;
  REP(i, (1 << 25)-1){
    if(dp[i] == 0) continue;
    int n = 0;
    REP(j, 25){
      if(1 << j & i) n++;
    }
    if(mp[n] >= 0){
      int v = mp[n];
      int x = v % 5;
      int y = v / 5;
      if((1 << v) & i) continue;
      if(0 < x && x < 4 && ((i >> (v-1)) ^ (i >> (v+1))) & 1) continue;
      if(0 < y && y < 4 && ((i >> (v-5)) ^ (i >> (v+5))) & 1) continue;
      dp[i | (1 << v)] = (dp[i | (1 << v)] + dp[i]) % MOD;
    }else{
      REP(v, 25){
        int x = v % 5;
        int y = v / 5;
        if((1 << v) & i) continue;
        if(0 < x && x < 4 && ((i >> (v-1)) ^ (i >> (v+1))) & 1) continue;
        if(0 < y && y < 4 && ((i >> (v-5)) ^ (i >> (v+5))) & 1) continue;
        dp[i | (1 << v)] = (dp[i | (1 << v)] + dp[i]) % MOD;
      }

    }
  }

  cout << dp[(1<<25)-1] << endl;


  return 0;
}

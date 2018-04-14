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
  ll N, W;
  cin >> N >> W;
  ll w[N], v[N];
  REP(i,N){
    cin >> w[i] >> v[i];
  }

  if(w[0] > 3 ){

    ll memo[N+1][401];
    REP(i,N+1)REP(j,401)memo[i][j] = 0;
    REP(i,N){
      REP(j,401){

        if(j >= (w[i]/w[0] + w[i] % w[0])){
          memo[i+1][j] = max(memo[i][j], memo[i][j-(w[i]/w[0] + w[i] % w[0])] + v[i]);
        }else{
          memo[i+1][j] = memo[i][j];
        }

      }
    }

    if(W < w[0])cout << 0 << endl;
    else cout << memo[N][W/w[0] + W%w[0]] << endl;
  }else{
    ll ww = 100*w[0]+300;
    ll memo[N+1][ww+1];
    REP(i,N+1)REP(j,ww+1)memo[i][j] = 0;
    REP(i,N){
      REP(j,ww+1){
        if(j>0){memo[i+1][j] = memo[i+1][j-1];}
        if(j >= (w[i])){
          memo[i+1][j] = max(memo[i][j], memo[i][j-w[i]] + v[i]);
        }else{
          memo[i+1][j] = memo[i][j];
        }

      }
    }

    if(W < w[0])cout << 0 << endl;
    else cout << memo[N][W] << endl;
  }

  return 0;
}

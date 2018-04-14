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

#define MAX_V 100000

vector<int> G[MAX_V];

int main(){
  int n;
  cin >> n;
  ll x[n], y[n];
  REP(i,n)cin >> x[i] >> y[i];
  vll vx, vy;
  REP(i,n){
    vx.push_back(x[i]);
    vy.push_back(y[i]);
  }
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());

  ll ans = 0;
  ll minlen = INFll;

  REP(i,n){

    ll dx;
    if(lower_bound(vx.begin(), vx.end(), x[i])==vx.begin()){
      dx = *(lower_bound(vx.begin(), vx.end(), x[i])+1) - x[i];
    }else if(lower_bound(vx.begin(), vx.end(), x[i])==vx.end()-1){
      dx = x[i] - *(lower_bound(vx.begin(), vx.end(), x[i])-1);
    }else{
      dx = min(*(lower_bound(vx.begin(), vx.end(), x[i])+1) - x[i], x[i] - *(lower_bound(vx.begin(), vx.end(), x[i])-1));
    }

    ll dy;

    if(lower_bound(vy.begin(), vy.end(), y[i])==vy.begin()){
      dy = *(lower_bound(vy.begin(), vy.end(), y[i])+1) - y[i];
    }else if(lower_bound(vy.begin(), vy.end(), y[i])==vy.end()-1){
      dy = y[i] - *(lower_bound(vy.begin(), vy.end(), y[i])-1);
    }else{
      dy = min(*(lower_bound(vy.begin(), vy.end(), y[i])+1) - y[i], y[i] - *(lower_bound(vy.begin(), vy.end(), y[i])-1));
    }

    ll m = min(dx, dy);

    ans += m;
    minlen = min(minlen,m);
  }

  cout << ans - minlen << endl;





  return 0;
}

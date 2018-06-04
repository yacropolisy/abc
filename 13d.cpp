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
  ll n, m, d;
  cin >> n >> m >> d;
  ll a[m];
  ll result[n], t[n], t2[n];
  REP(i,n) {
    result[i] = i;
    t[i] = i;
    t2[i] = i;
  }


  REP(i,m){
    cin >> a[i];
    a[i]--;
    swap(result[a[i]], result[a[i]+1]);
  }


  while(d){
    if(d&1){
      REP(i,n){
        t[i] = result[t[i]];
      }
    }
    REP(i,n){
      t2[i] = result[i];
    }
    REP(i,n){
      result[i] = t2[t2[i]];
    }
    d >>= 1;

  }



  ll ans[n];
  REP(i,n) ans[t[i]] = i+1;
  REP(i,n) cout << ans[i] << endl;


  return 0;
}

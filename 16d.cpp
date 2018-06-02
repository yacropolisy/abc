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
  ll ax, ay, bx, by ;
  cin >> ax  >> ay >> bx >> by;
  int n;
  cin >> n;
  ll x[n], y[n];
  REP(i,n) cin >> x[i] >> y[i];

  bool last = x[n-1] * (ay - by) - y[n-1] * (ax - bx) -ay * bx + ax * by > 0;
  ll ans = 0;
  REP(i,n){
    if(x[i] * (ay - by) - y[i] * (ax - bx) -ay * bx + ax * by > 0){
      if(!last){
        last = true;
        ans ++;
      }
    }else{
      if(last){
        last = false;
        ans ++;
      }
    }
  }

  cout << ans/2 + 1<< endl;


  return 0;
}

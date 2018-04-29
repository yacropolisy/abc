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
  int n, t;
  cin >> n >> t;
  ll a[n];
  REP(i,n)cin >> a[i];
  ll mx[n];
  mx[n-1] = a[n-1];
  REP(i,n-1)mx[n-2-i] = max(mx[n-1-i], a[n-2-i]);
  ll gain[n-1];
  REP(i,n-1)gain[i] = mx[i+1] - a[i];
  sort(gain, gain+n-1);
  cout << n-1- (lower_bound(gain,gain+n-1, gain[n-2])-gain) << endl;

  return 0;
}

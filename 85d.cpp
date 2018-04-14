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

#define MAX_N 100000
ll n;

int main(){
  ll h;
  cin >> n >> h;
  ll a[n], b[n];
  REP(i,n)cin >> a[i] >> b[i];
  sort(a, a+n);
  sort(b, b+n);
  int b_use = upper_bound(b, b+n, a[n-1]) - b;
  if(b_use == n){
    cout << ll(ceil(h / double(a[n-1]))) << endl;
    return 0;
  }

  ll c[n - b_use];
  REP(i,n-b_use){
    if(i == 0)c[0] = b[n-1];
    else c[i] = c[i-1] + b[n-1-i];
  }
  if(c[n-b_use-1] > h){
    cout << (upper_bound(c, c + (n - b_use), h) - c) + 1 << endl;
  }else{
    cout << ll(ceil((h - c[n-b_use-1]) / double(a[n-1]))) + n - b_use << endl;
  }


  return 0;
}

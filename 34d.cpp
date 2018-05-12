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
  int n, k;
  cin >> n >> k;
  double w[n], p[n], v[n];
  REP(i,n){
    cin >> w[i] >> p[i];
    v[i] = w[i] * p[i] / 100;
  }

  double lb = 0;
  double ub = 100.0;
  while(ub - lb > 0.00000000001){
    double mid = (ub + lb) / 2;
    double tmp[n];
    REP(i,n) tmp[i] = v[i] - (mid * w[i]/100);
    sort(tmp, tmp+n, greater<double>());
    double s = 0;;
    REP(i, k){
      s += tmp[i];
    }
    if(s >= 0){
      lb = mid;
    }
    else{
      ub = mid;
    }
  }

  cout.precision(20);
  cout << fixed << std::setprecision(9) << ub << endl;


  return 0;
}

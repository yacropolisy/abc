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
  double a, b, c;
  cin >> a >> b >> c;
  double lb = 0.0, ub = 200.0;

  while(ub-lb>0.00000000001){
    double mid = (ub + lb) / 2;
    if(mid * a + b * sin(c * mid * PI) > 100.0){
      ub = mid;
    }else{
      lb = mid;
    }
  }

  cout << setprecision(15);
  cout << lb << endl;

  return 0;
}

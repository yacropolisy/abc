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
  ll n;
  cin >> n;
  double ax[n], ay[n], bx[n], by[n];
  double axm = 0, aym = 0, bxm = 0, bym = 0;

  REP(i,n){
    cin >> ax[i] >> ay[i];
    axm += ax[i];
    aym += ay[i];
  }
  REP(i,n){
    cin >> bx[i] >> by[i];
    bxm += bx[i];
    bym += by[i];
  }
  axm /= double(n);
  aym /= double(n);
  bxm /= double(n);
  bym /= double(n);

  double amax = 0, bmax = 0;


  REP(i,n){
    ax[i] -= axm;
    ay[i] -= aym;
    bx[i] -= bxm;
    by[i] -= bym;

    amax = max(ax[i] * ax[i] + ay[i] * ay[i], amax);
    bmax = max(bx[i] * bx[i] + by[i] * by[i], bmax);
  }

  cout << setprecision(10);
  cout << sqrt(bmax/amax) << endl;





  return 0;
}

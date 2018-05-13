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
  int n;
  cin >> n;
  int x[n], y[n];
  REP(i,n) cin >> x[i] >> y[i];
  ll don = 0, tyoku = 0;
  REP(i,n){
    double args[2*(n-1)];
    REP(j,n){
      if(j < i){
        args[j] = atan2(y[j] - y[i], x[j] - x[i]) * 180.0 / PI;
        args[j+n-1] = atan2(y[j] - y[i], x[j] - x[i]) * 180.0 / PI + 360;
      } else if(j > i) {
        args[j-1] = atan2(y[j] - y[i], x[j] - x[i]) * 180.0 / PI;
        args[j-1+n-1] = atan2(y[j] - y[i], x[j] - x[i]) * 180.0 / PI + 360;
      } else continue;
    }

    sort(args, args+2*(n-1));

    REP(j,2 * (n-1)){
      cout << args[j] << ",";
    }
    cout << endl;

    int k = 0, l = 0;
    while(l < 2*(n-1) && k<n-1){
      if((args[l] - args[k]) < 90 || (args[l] - args[k]) > 270){
        l++;
      }else{
        if(args[l] - args[k] == 90) tyoku++;
        else{
          don++;
          cout << "l " << l << ", k " << k << endl;
        }
        k++;
      }
    }


  }

  cout << n * (n-1) * (n-2) / 6 - don - tyoku << " " << tyoku << " " << don << endl;

  return 0;
}

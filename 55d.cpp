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
  string s;
  cin >> n >> s;
  int animal[n+2];

  animal[0] = -1;
  animal[1] = -1;
  REP(i,n){
    if(s[i] == 'o'){
      animal[i+2] = animal[i+1] * animal[i];
    }else{
      animal[i+2] = animal[i+1] * animal[i] * -1;
    }
  }
  if(animal[0] == animal[n] && animal[1] == animal[n+1]){
    REP(i,n){
      if(animal[i+1] == 1) cout << "S";
      else cout << "W";
    }
    cout << endl;
    return 0;
  }

  animal[0] = 1;
  animal[1] = -1;
  REP(i,n){
    if(s[i] == 'o'){
      animal[i+2] = animal[i+1] * animal[i];
    }else{
      animal[i+2] = animal[i+1] * animal[i] * -1;
    }
  }
  if(animal[0] == animal[n] && animal[1] == animal[n+1]){
    REP(i,n){
      if(animal[i+1] == 1) cout << "S";
      else cout << "W";
    }
    cout << endl;
    return 0;
  }

  animal[0] = -1;
  animal[1] = 1;
  REP(i,n){
    if(s[i] == 'o'){
      animal[i+2] = animal[i+1] * animal[i];
    }else{
      animal[i+2] = animal[i+1] * animal[i] * -1;
    }
  }
  if(animal[0] == animal[n] && animal[1] == animal[n+1]){
    REP(i,n){
      if(animal[i+1] == 1) cout << "S";
      else cout << "W";
    }
    cout << endl;
    return 0;
  }

  animal[0] = 1;
  animal[1] = 1;
  REP(i,n){
    if(s[i] == 'o'){
      animal[i+2] = animal[i+1] * animal[i];
    }else{
      animal[i+2] = animal[i+1] * animal[i] * -1;
    }
  }
  if(animal[0] == animal[n] && animal[1] == animal[n+1]){
    REP(i,n){
      if(animal[i+1] == 1) cout << "S";
      else cout << "W";
    }
    cout << endl;
    return 0;
  }

  cout << -1 << endl;


  return 0;
}

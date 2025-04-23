#include<bits/stdc++.h>
using namespace std;
// Better Solution.
int solve(vector<int> &nums){
  map<int,int> mp;
  for(auto it:nums){
    mp[it]++;
  }
  for(auto it: mp){
    if(it.second == 1)return it.first;
  }
  return -1;
}

//Optimal solution.
int solve2(vector<int> &nums){
  int ans=0;
  for(auto it: nums){
    ans^=it;
  }
  return ans;
}
int main(){
  vector<int> v={1,1,2,3,3,4,4,5,5};
  int ans=solve2(v);
  cout<<ans<<endl;
  return 0;
}
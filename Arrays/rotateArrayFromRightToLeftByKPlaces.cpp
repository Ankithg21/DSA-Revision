#include<bits/stdc++.h>
using namespace std;
// Brute-Force solution.
void solve(vector<int> &nums,int k){
  vector<int> temp;
  int n=nums.size();
  int j=n-k;
  for(int i=j;i<n;i=i+1){
    temp.push_back(nums[i]);
  }
  int d=n-k-1;
  while(d--){
    nums[d+k]=nums[d];
  }
  for(int i=0;i<k;i=i+1){
    nums[i]=temp[i];
  }
  return;
}
// Optimal Solution.
void solve2(vector<int> &nums,int k){
  int n=nums.size();
  reverse(nums.begin(),nums.begin()+(n-k));
  reverse(nums.begin()+(n-k),nums.end());
  reverse(nums.begin(),nums.end());
}
int main(){
  vector<int> v={1,2,3,4,5,6,7};
  int k=4;
  solve2(v,k);
  for(int i=0;i<v.size();i=i+1){
    cout<<v[i]<<" ";
  }
  cout<<endl;
  return 0;
}
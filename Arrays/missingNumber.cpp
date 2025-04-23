#include<bits/stdc++.h>
using namespace std;
bool LS(vector<int> &nums,int key){
  for(int i=0;i<nums.size();i=i+1){
    if(nums[i]==key){
      return true;
    }
  }
  return false;
}
// Brute-Force solution.
int solve(vector<int> &nums, int N){
  int missing=-1;
  for(int i=1;i<=N;i=i+1){
    if(!LS(nums,i)){
      missing=i;
      break;
    }
  }
  return missing;
}

//Better Solution.
int solve2(vector<int> &nums, int N){
  vector<int> hash(N,0);
  for(int i=0;i<nums.size();i=i+1){
    hash[nums[i]]=1;
  }
  for(int i=1;i<=N;i=i+1){
    if(hash[i]==0){
      return i;
    }
  }
  return -1;
}

// Optimal Solution.
int solve3(vector<int> &nums,int N){
  int total=(N*(N+1))/2;
  for(int i=0;i<nums.size();i=i+1){
    total-=nums[i];
  }
  return total;
}

int main(){
  vector<int> v={1,2,4,5};
  int N=5;
  int ans = solve3(v,N);
  cout<<ans<<endl;
  return 0;
}
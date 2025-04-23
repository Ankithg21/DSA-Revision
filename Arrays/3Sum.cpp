#include<bits/stdc++.h>
using namespace std;

// Brute Force solution.
vector<vector<int>> solve(int n, vector<int> &nums){
  set<vector<int>> st;
  vector<vector<int>> ans;
  for(int i=0;i<n;i=i+1){
    for(int j=i+1;j<n;j=j+1){
      for(int k=j+1;k<n;k=k+1){
        if(nums[i]+nums[j]+nums[k]==0){
          vector<int> temp={nums[i],nums[j],nums[k]};
          sort(temp.begin(),temp.end());
          st.insert(temp);
        }
      }
    }
  }
  for(auto it:st){
    ans.push_back(it);
  }
  return ans;
}

// Better solution
vector<vector<int>> solve2(int n, vector<int> &nums){
  map<int,int> mp;
  vector<vector<int>> ans;
  set<vector<int>> st;
  for(auto it:nums)mp[it]++;
  for(int i=0;i<n;i=i+1){
    for(int j=i+1;j<n;j=j+1){
      int k=-(nums[i]+nums[j]);
      int res=mp[k];
      if(res!=0){
        vector<int> temp={nums[i],nums[j],k};
        sort(temp.begin(),temp.end());
        st.insert(temp);
      }
    }
  }
  for(auto it:st)ans.push_back(it);
  return ans;
}

// Optimal Solution.
vector<vector<int>> solve3(int n, vector<int> &nums){
  vector<vector<int>> ans;
  sort(nums.begin(),nums.end());
  for(int i=0;i<n;i=i+1){
    if(i>0 && nums[i]==nums[i-1])continue;
    int j=i+1;
    int k=n-1;
    while(j<k){
      int sum=nums[i]+nums[j]+nums[k];
      if(sum < 0){
        j++;
      }
      else if(sum > 0){
        k--;
      }
      else{
        ans.push_back({nums[i],nums[j],nums[k]});
        j++;
        k--;
        while(j<k && nums[j]==nums[j-1])j++;
        while(j<k && nums[k]==nums[k+1])k--;
      }
    }
  }
  return ans;
}

int main(){
  vector<int> v={-1,0,1,2,-1,-4};
  int n=6;
  vector<vector<int>> ans=solve3(n,v);
  for(int i=0;i<ans.size();i=i+1){
    for(int j=0;j<ans[i].size();j=j+1){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
  
}
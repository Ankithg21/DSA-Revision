#include<bits/stdc++.h>
using namespace std;
// Brute-Force solution.
vector<int> solve(vector<int> &a,vector<int> &b){
  set<int> st;
  for(int i=0;i<a.size();i=i+1){
    st.insert(a[i]);
  }
  for(int i=0;i<b.size();i=i+1){
    st.insert(b[i]);
  }
  vector<int> ans;
  for(auto it: st){
    ans.push_back(it);
  }
  return ans;
}

// Optimal Solution.
vector<int> solve2(vector<int> &a, vector<int> &b){
  int i=0,j=0;
  int n1=a.size(), n2=b.size();
  vector<int> ans;
  while(i<n1 && j<n2){
    if(a[i] <= b[j]){
      if(ans.size()==0 || ans.back()!=a[i]){
        ans.push_back(a[i++]);
      }
      i++;
    }
    else{
      if(ans.size()==0 || ans.back()!=b[j]){
        ans.push_back(b[j++]);
      }
      j++;
    }
  }
  while(i<n1){
    if(ans.size()==0 || ans.back()!=a[i]){
      ans.push_back(a[i++]);
    }
  }
  while(j<n2){
    if(ans.size()==0 || ans.back()!=b[j]){
      ans.push_back(b[j++]);
    }
  }
  return ans;
}
int main(){
  vector<int> v1={1,1,2,3,4,5,6};
  vector<int> v2={2,3,4,4,5};
  vector<int> ans=solve2(v1,v2);
  for(int i=0;i<ans.size();i=i+1){
    cout<<ans[i]<<" ";
  }
  return 0;
}
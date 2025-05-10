#include<bits/stdc++.h>
using namespace std;

class Node{
  public: 
    int data;
    Node* next;
    Node(int data){
      this->data = data;
      next=NULL;
    }
};
// BRUTE
bool solve(Node* head){
  map<int,int> mp;
  Node* temp=head;
  while(temp!=NULL){
    if(mp.find(temp->data)==mp.end()){
      mp[temp->data]++;
      temp=temp->next;
    }
    else if(mp[temp->data]>1){
      return true;
    }
  }
  return false;
}


// OPTIMAL
bool detectCycle(Node* head){
  if(head==NULL || head->next==NULL)return head;
  Node* slow=head;
  Node* fast=head->next;
  while(fast!=NULL && fast->next!=NULL){
    if(slow==fast)return true;
    slow=slow->next;
    fast=fast->next->next;
  }
  return false;
}

// array to LL
Node* arrayToLL(vector<int> &nums){
  Node* head=new Node(nums[0]);
  Node* temp=head;
  for(int i=1;i<nums.size();i=i+1){
    Node* newNode=new Node(nums[i]);
    temp->next=newNode;
    temp=newNode;
  }
  return head;
}

//print LL.
void print(Node* head){
  if(head==NULL)return;
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  return;
}


int main(){
  // vector<int> v={1,2,3,4,5,6,7};
  // Node* head = arrayToLL(v);
  Node* n1=new Node(1);
  Node* n2=new Node(2);
  Node* n3=new Node(3);
  Node* n4=new Node(4);
  Node* n5=new Node(5);
  Node* n6=new Node(6);
  Node* n7=new Node(7);
  n1->next=n2;
  n2->next=n3;
  n3->next=n4;
  n4->next=n5;
  n5->next=n6;
  n6->next=n7;
  n7->next=n3;
  bool ans=detectCycle(n1);
  if(ans)cout<<"CYCLE"<<endl;
  else cout<<"NO CYCLE"<<endl;
  return 0;
}
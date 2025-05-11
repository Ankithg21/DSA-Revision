
#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
      int data;
      Node* next;
      Node* prev;
      Node(int data){
        this->data = data;
        next=NULL;
        prev=NULL;
      }
};

pair<int,int> solve(Node* head, int target){
  Node* tail=head;
  while(tail->next!=NULL){
    tail=tail->next;
  }
  while(head!=tail){
    if(head->data + tail->data == target){
      pair<int,int> res;
      res.first=head->data;
      res.second=tail->data;
      return res;
    }
    if(head->data + tail->data > target){
      tail=tail->prev;
    }
    else{
      head=head->next;
    }
  }
  pair<int,int> res={-1,-1};
  return res;
}

Node* arrayToDLL(vector<int> &nums){
  Node* head=new Node(nums[0]);
  Node* temp=head;
  for(int i=1;i<nums.size();i=i+1){
    Node* newNode=new Node(nums[i]);
    temp->next=newNode;
    newNode->prev=temp;
    temp=newNode;
  }
  return head;
}

void print(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  return;
}

void printReverse(Node* head){
  Node* temp=head;
  while(temp->next != NULL){
    temp=temp->next;
  }
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->prev;
  }
  return;
}
int main(){
  
  vector<int> v={1,2,3,4,9};
  int target=5;
  Node* head=arrayToDLL(v);
  print(head);
  cout<<endl;
  pair<int,int> ans=solve(head, target);
  cout<<ans.first<<","<<ans.second<<endl;
  
  return 0;
}

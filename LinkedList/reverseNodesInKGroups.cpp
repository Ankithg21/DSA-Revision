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

Node* reverse(Node* head){
  Node* prev=NULL;
  if(head==NULL){
    return head;
  }
  Node* temp=head;
  while(temp!=NULL){
    Node* nextNode=temp->next;
    temp->next=prev;
    prev=temp;
    temp=temp->next;
  }
  return prev;
}

Node* getKthNode(Node* temp, int k){
  k--;
  while(temp!=NULL && k>0){
    k--;
    temp=temp->next;
  }
  return temp;
}

Node* solve(Node* head, int k){
  Node* temp=head;
  Node* prevLast=NULL;
  while(temp!=NULL){
    Node* kNode=getKthNode(temp,k);
    if(kNode==NULL){
      if(prevLast)prevLast->next=temp;
      break;
    }
    Node* nextNode=kNode->next;
    kNode->next=NULL;
    temp=reverse(temp);
    if(temp==head){
      head=kNode;
    }else{
      prevLast->next=kNode;
    }
    prevLast=temp;
    temp=nextNode;
  }
  return head;
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
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  Node* head = arrayToLL(v);
  head=solve(head,3);
  print(head);
  return 0;
}
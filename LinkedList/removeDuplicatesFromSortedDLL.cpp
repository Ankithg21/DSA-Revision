
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

Node* solve(Node* head){
  Node* temp=head;
  Node* curr=head->next;
  while(curr!=NULL){
    while(curr!=NULL && temp->data == curr->data){
      curr=curr->next;
    }
    if(temp==head && curr==NULL){
      Node* newNode=new Node(temp->data);
      return newNode;
    }
    temp->next=curr;
    curr->prev=temp;
    temp=curr;
    curr=curr->next;
  }
  return head;
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
  
  vector<int> v={1,1,1,2};
  int target=5;
  Node* head=arrayToDLL(v);
  print(head);
  cout<<endl;
  head=solve(head);
  print(head);
  return 0;
}

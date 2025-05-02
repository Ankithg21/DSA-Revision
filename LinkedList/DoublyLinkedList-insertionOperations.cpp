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

// insert at head.
Node* insertHead(Node* head, int data){
  if(head==NULL)return head=new Node(data);
  Node* newNode=new Node(data);
  newNode->next=head;
  head->prev=newNode;
  head=newNode;
  return head;
}

// insert at Tail.
Node* insertTail(Node* head, int data){
  if(head==NULL)return head=new Node(data);
  Node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  Node* newNode=new Node(data);
  temp->next=newNode;
  newNode->prev=temp;
  return head;
}

// insert at specific position.
Node* insertAtKthPosition(Node* head, int data, int pos){
  if(head==NULL)return head=new Node(data);
  Node* temp=head;
  Node* prev=NULL;
  pos--;
  while(pos--){
    prev=temp;
    temp=temp->next;
  }
  Node* newNode=new Node(data);
  prev->next=newNode;
  newNode->prev=prev;
  newNode->next=temp;
  temp->prev=newNode;
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
  
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  Node* head=arrayToDLL(v);
  print(head);
  cout<<endl;
  head=insertAtKthPosition(head, 100, 6);
  print(head);
  return 0;
}
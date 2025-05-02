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

// insert @ head
Node* insertHead(Node* head, int data){
  if(head==NULL){
    return head=new Node(data);
  }
  Node* newNode = new Node(data);
  newNode->next=head;
  head=newNode;
  return head;
}

// insert @ tail.
Node* insertTail(Node* head, int data){
  if(head==NULL){
    return head=new Node(data);
  }
  Node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  Node* newNode= new Node(data);
  temp->next=newNode;
  return head;
}

// insert @ kth position.
Node* insertAtKthPosition(Node* head, int k, int data){
  Node* temp=head;
  Node* prev=NULL;
  k--;
  while(k--){
    prev=temp;
    temp=temp->next;
  }
  Node* newNode=new Node(data);
  prev->next=newNode;
  newNode->next=temp;
  return head;
}

int main(){
  
  vector<int> v={1,2,3,4,5,6};
  Node* head = arrayToLL(v);
  head=insertAtKthPosition(head, 5, 100);
  print(head);
  
  return 0;
}
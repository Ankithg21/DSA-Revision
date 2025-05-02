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

// delete head.
Node* deleteHead(Node* head){
  if(head==NULL)return head;
  Node* temp=head;
  head=head->next;
  temp->next=NULL;
  temp->prev=NULL;
  delete(temp);
  return head;
}

// delete Tail.
Node* deleteTail(Node* head){
  if(head==NULL)return NULL;
  Node* temp=head;
  Node* prev=NULL;
  while(temp->next!=NULL){
    prev=temp;
    temp=temp->next;
  }
  prev->next=NULL;
  temp->prev=NULL;
  delete(temp);
  return head;
}

// delete at specific position.
Node* deleteAtKthPosition(Node* head, int pos){
  Node* temp=head;
  Node* prev=NULL;
  pos=pos-1;
  while(pos--){
    prev=temp;
    temp=temp->next;
  }
  prev->next=temp->next;
  temp->next->prev=prev;
  delete(temp);
  return head;
}

// delete by searching a target element.
Node* deleteBySearch(Node* head, int target){
  if(head==NULL)return head;
  Node* temp=head;
  Node* prev=NULL;
  while(temp!=NULL){
    if(temp->data == target){
      prev->next=temp->next;
      temp->next->prev=prev;
      delete(temp);
      return head;
    }
    prev=temp;
    temp=temp->next;
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
  
  vector<int> v={1,2,3,4,5,6,7,8,9,10};
  Node* head=arrayToDLL(v);
  print(head);
  cout<<endl;
  head=deleteBySearch(head, 6);
  print(head);
  
  return 0;
}
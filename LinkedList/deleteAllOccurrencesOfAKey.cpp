
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

Node* solve(Node* head, int key){
  Node* temp=head;
  Node* prev=NULL;
  while(temp!=NULL){
    if(temp->data == key){
      if(temp==head){
        head=head->next;
      }
      Node* nextNode = temp->next;
      Node* prevNode=temp->prev;
      if(nextNode!=NULL)nextNode->prev=prevNode;
      if(prevNode!=NULL)prevNode->next=nextNode;
      delete(temp);
      temp=nextNode;
    }
    else{
      temp=temp->next;
    }
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
  
  vector<int> v={10,4,10,10,6,10};
  Node* head=arrayToDLL(v);
  print(head);
  cout<<endl;
  head=solve(head, 10);
  print(head);
  
  return 0;
}

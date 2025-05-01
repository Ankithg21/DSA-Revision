#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node(int data){
      this->data=data;
      next=NULL;
    }
};

void traverse(Node* head){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  return;
}

bool search(Node* head, int target){
  Node* temp=head;
  while(temp!=NULL){
    if(target == temp->data){
      return true;
    }
    temp=temp->next;
  }
  return false;
}

int lengthOfLinkedList(Node* head){
  int count=0;
  while(head!=NULL){
    count++;
    head=head->next;
  }
  return count;
}

int main(){
  return 0;
}
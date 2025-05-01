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

int main(){
  return 0;
}
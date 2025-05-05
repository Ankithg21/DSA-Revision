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

Node* solve(Node* head, int N){
  int count=0;
  Node* temp=head;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  if(count==N){
    head=head->next;
    return head;
  }
  // count--;
  int res=count-N;
  temp=head;
  res--;
  while(res--){
    temp=temp->next;
  }
  Node* dNode=temp->next;
  temp->next=dNode->next;
  dNode->next==NULL;
  delete(dNode);
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
  
  vector<int> v={1,2,3,4,5,6};
  Node* head = arrayToLL(v);
  head=solve(head, 1);
  print(head);
  
  return 0;
}

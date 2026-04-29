#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node* Convert2DLL(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* node=new Node(arr[i],nullptr,prev);
        prev->next=node;
        prev=node;
    }
    return head;
}

void printLL(Node* &head){
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void printLLBack(Node* &head){
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    while(temp){
        cout<<temp->data <<" -> ";
        temp=temp->back;
    }
    cout << "nullptr" << endl;
}

Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    Node* node=head;
    head=head->next;
    head->back=nullptr;
    node->next=nullptr;
    delete(node);
    return head;
}

void insertionOfNodeBeforeHead(Node *&head,int val){
    Node *temp=new Node(val,head,nullptr);
    head->back=temp;
    head=temp;
}

void insertionOfNodeBeforeTail(Node *&head,int val){
    Node *temp=head;
    while(temp->next){
        temp=temp->next;
    }
    Node *x=new Node(val,temp,temp->back);
    temp->back=x;
    x->back->next=x;
}

void insertionOfNodeBeforeKth(Node *&head,int val,int k){
    Node *temp=head;
    if(k==0){
        Node* x=new Node(val,temp,nullptr);
        temp->back=x;
        temp=x;
        head=temp;
        return;
    }
    int count=0;
    while(temp){
        count++;
        if(count==k)break;
        temp=temp->next;
    }
    if(count==k){
        Node *x=new Node(val,temp,temp->back);
        temp->back=x;
        x->back->next=x;
    }

}

void insertionOfNodeBeforeEle(Node *&head,int val,int ele){
    
}

int main(){
    vector<int>arr={12,3,7,9};
    Node* head=Convert2DLL(arr);
    printLL(head);
    // printLLBack(head);
    // head=deleteHead(head);
    // printLL(head);
    // printLLBack(head);
    insertionOfNodeBeforeHead(head,10);
    printLL(head);
    insertionOfNodeBeforeTail(head,8);
    printLL(head);
    insertionOfNodeBeforeKth(head,18,7);
    printLL(head);
    
    return 0;
}
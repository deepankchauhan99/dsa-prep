#include<iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printLL(ListNode*&head){
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void addNode(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(ListNode *&head) {
    if (head == nullptr) return;
    ListNode* temp = head;
    head = (head)->next;
    free(temp);
}

void deleteNodeByIndex(ListNode *&head,int index){
    if(head == nullptr) return;
    ListNode* temp = head;
    while(index && temp->next->next){
        temp=temp->next;
        index--;
    }
}

void deleteTailNode(ListNode *&head) {
    if (head == nullptr) return;
    ListNode* temp = head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    ListNode* temp1 = temp->next;
    temp->next=nullptr;
    free(temp1);
}

void insertElementbeforeK(ListNode *&head,int k,int ele){
    if (head== nullptr){
        return ;
    }
    if (head->val==k){
        ListNode* temp = new ListNode(ele);
        temp->next=head;
        head=temp;
        return ;
    }
    ListNode* temp =head;
    while(temp->next!=nullptr){
        if(temp->next->val==k){
            ListNode*n= new ListNode(ele);
            n->next=temp->next;
            temp->next=n;
            return;
        }
        temp=temp->next;
    }
    return;
}


int main(){
    ListNode* head = nullptr;
    addNode(head, 10);
    addNode(head, 20);
    addNode(head, 80);
    addNode(head, 40);
    addNode(head, 60);
    addNode(head, 30);
    addNode(head, 50);
    addNode(head, 90);

    insertElementbeforeK(head,40,69);
    printLL(head);
    deleteNode(head);
    printLL(head);
    deleteTailNode(head);
    printLL(head);

    return 0;
}


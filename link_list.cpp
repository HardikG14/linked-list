#include<bits/stdc++.h>
using namespace std;
#include "Node_Class.cpp"

#define ll                long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll


const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
const int N=0;
/* -------------------------------------------------------------------------- */
void print(node* head){
    while(head!=nullptr){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<endl;
}
/* -------------------------------------------------------------------------- */
// Time Complexity.... O(n^2).....
node* takeInput1(){
    int data;
    cin>>data;
    node* head = nullptr;
    while(data!=-1){
        node* newNode = new node(data);
        if(head==nullptr){
            head=newNode;
        }else{
            node* temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next= newNode;
        }
        cin>>data;
    }
    return head;
}
/* -------------------------------------------------------------------------- */
// Time Complexity...O(n).....
node* takeInput2(){
    int data;
    cin>>data;
    node* head = nullptr;
    node* tail = nullptr;
    while(data!=-1){
        node* newNode = new node(data);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }else{
            tail->next = newNode;
            tail=tail->next; //tail = newNode;
        }
        cin>>data;
    }
    return head;
}

/* ----------------------------- insert at tail ----------------------------- */
void insertAtTail(node* &head,int val){
    node* newNode = new node(val);

    if(head==nullptr){
        head=newNode;
        return;
    }
    node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next = newNode;
}

/* -------------------- delete all node with given value from linked list -------------------- */
node* deleteVal(node* head,int val){
    if(head==nullptr){
        return head;
    }
    node* newHead = deleteVal(head->next,val);
    if(head->data==val){
        delete head;
        return newHead;
    }else{
        head->next = newHead;
        return head;
    }
}

/* ----------------------------- insert at head ----------------------------- */
node* insertAtHead(node*head,int data){
    node* newHead = new node(data);
    if(head==nullptr){
        return newHead;
    }

    newHead->next = head;
    return newHead;
}

/* -------------------------- search in linked list ------------------------- */
bool searchInLL(node* head,int key){
    if(head==nullptr){
        return false;
    }

    while(head!=nullptr){
        if(head->data==key){
            return true;
        }
        head=head->next;
    }
    return false;
}
/* -------------------------- length of linked list ------------------------- */
int lengthOfLL(node* head){
    int i=0;
    while(head!=nullptr){
        i++;
        head = head->next;
    }
    return i;
}

/* ----------------------------- print Ith node ----------------------------- */
void printIthNode(node* head,int i){
    if(head==nullptr){
        return;
    }
    int count=0;
    while(count!=i&&head!=nullptr){
        count++;
        head = head->next;
    }
    if(count<i){
        return;
    }else{
        cout<<head->data<<endl;
    }
}

//? when count(starting from 0)==i count will keep address of ith node(indexing from 0);
/* -------------------------------------------------------------------------- */

/* ---------------------------- node at Tth Index --------------------------- */

node* insertAtI(node* head,int i,int data){
    node* newNode = new node(data);
    node* temp= head;
    if(i==0){
        newNode->next=temp;
        temp = newNode;
        return temp;
    }
    int count=0;
    while(count<i-1&&temp!=nullptr){
        temp=temp->next;
        count++;
    }

    if(temp!=nullptr){
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

/* -------------------- remove Duplicates Recursive Code -------------------- */
node *removeDuplicates(node *head)
{
    //Write your code here
    if(head->next==nullptr){
        return head;
    }
    node* temp = removeDuplicates(head->next);
    if(head->data==temp->data){
        delete head;
        return temp;
    }else{
        head->next= temp;
        return head;
    }
}

node* reverseLL(node* head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }

    node* curr = head;
    node* prev=nullptr;
    node* next;

    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    return prev;
}

node* reverseLLRec(node* head){

    if(head==nullptr||head->next==nullptr){
        return head;
    }

    node* newHead = reverseLLRec(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

/* ----------------------- mid Point of a linked list ----------------------- */
node* midOfLL(node* head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    node* slow = head;
    node* fast = head->next;
    
    while(fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int intersectionOfLL(node* head1,node* head2){
    int n = lengthOfLL(head1);
    int m = lengthOfLL(head2);

    int d=0;
    node* ptr1;
    node* ptr2;

    if(n>m){
        d=n-m;
        ptr1=head1;
        ptr2=head2;
    }else{
        d=m-n;
        ptr1=head2;
        ptr2=head1;
    }

    while(d){
        ptr1=ptr1->next;
        if(ptr1==nullptr){
            return -1;
        }
        d--;
    }

    while(ptr1!=nullptr&&ptr2!=nullptr){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return -1;
}

/* -------------- cycle detection in linked list //floyds algo -------------- */
bool detectCycle(node* head){
    if(head==nullptr){
        return false;
    }

    node* slow = head;
    node* fast = head;

    while(fast!=nullptr&&fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

void makeCycle(node* head,int pos){
    if(head==nullptr){
        return;
    }
    int count=1;
    node* startNode;
    while(head->next!=nullptr){
        if(count==pos){
            startNode=head;
        }
        head = head->next;
        count++;
    }
    head->next = startNode;
}

/* ------------------------------- insert node ------------------------------ */
void insertNode(node* &head,int i,int data){
    node* newNode = new node(data);
    if(i==0){
        newNode->next=head;
        head=newNode;
        return;
    }
    int count=0;
    node* temp = head;
    while(count<i-1&&temp!=nullptr){
        count++;
        temp=temp->next;
    }
    if(temp!=nullptr){
        newNode->next=temp->next;
        temp->next = newNode;
    }
}

node* inserNodeRec(node* head,int i,int data){
    if(head==nullptr){
        return head;
    }

    if(i==0){
        node* newNode = new node(data);
        newNode->next = head;
        return newNode;
    }

    node* temp = inserNodeRec(head->next,i-1,data);
    head->next = temp;
    return head;
}
/* --------------------- print mid value of linked list --------------------- */
void midPoint(node* head){
    if(head==nullptr){
        return;
    }
    node* slow = head;
    node* fast = head->next;

    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
}

/* -------------------- break linked list from mid point -------------------- */
node* breakLL(node* head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }

    node* slow = head;
    node* fast = head->next;

    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    node* nextHead = slow->next;
    slow->next=nullptr;
    return nextHead;
}

/* ---------------------- merge two sorted linked list ---------------------- */
node* mergeTwoSortedLL(node* head1,node* head2){
    if(head1==nullptr){
        return head2;
    }
    if(head2==nullptr){
        return head1;
    }

    node*head=nullptr;
    node*tail=nullptr;

    if(head1->data<head2->data){
        head=head1;
        tail=head1;
        head1=head1->next;
    }else{
        head=head2;
        tail=head2;
        head2=head2->next;
    }
    while(head1!=nullptr&&head2!=nullptr){
        if(head1->data<head2->data){
            tail->next = head1;
            tail=head1;
            head1=head1->next;
        }else{
            tail->next=head2;
            tail=head2;
            head2=head2->next;
        }
    }

    if(head1!=nullptr){
        tail->next=head1;
    }

    if(head2!=nullptr){
        tail->next=head2;
    }

    return head;
}
//* /* ------------------------ merge sort on linked list ----------------------- */
node* mergeSortOnLL(node* head){
    // if(head==nullptr){
    //     return head;
    // }

    if(head==nullptr||head->next==nullptr){
        return head;
    }
    node* newHead = breakLL(head);
    node* head1 = mergeSortOnLL(head);
    node* head2 = mergeSortOnLL(newHead);
    node* newList = mergeTwoSortedLL(head1,head2);
    return newList;
}
//? /* ---------------------------------- main ---------------------------------- */
int main(){

node* head = takeInput2();
// node* newHead = breakLL(head);
// print(head);
// print(newHead);
print(head);
node* newHead = reverseLL(head);
print(newHead);
return 0;
}
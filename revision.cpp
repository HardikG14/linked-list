#include <bits/stdc++.h>
using namespace std;
// #include "Node_Class.cpp"
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Pair
{
public:
    Node *head;
    Node *tail;
};

#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define null nullptr
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 0;

void print(Node *head)
{
    while (head != null)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *takeInput1()
{
    int data;
    cin >> data;
    Node *head = null;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == null)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != null)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin >> data;
    }
    return head;
}

Node *takeInput2()
{
    int data;
    cin >> data;
    Node *head = null;
    Node *tail = null;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == null)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int lenOfLLIter(Node *head)
{
    int len = 0;
    while (head != null)
    {
        len++;
        head = head->next;
    }
    return len;
}

int lenOfLLRec(Node *head)
{
    if (head == null)
    {
        return 0;
    }
    int smallAns = lenOfLLRec(head->next);
    return smallAns + 1;
}

void printIthNode(Node *head, int i)
{
    int count = 0;
    while (head != null && count < i)
    {
        head = head->next;
        count++;
    }

    if (head != null)
    {
        cout << head->data;
    }
}
void printIth(Node *head, int i)
{
    if (head == nullptr)
    {
        return;
    }

    if (i == 0)
    {
        cout << head->data;
        return;
    }

    printIth(head->next, i - 1);
}

Node *insertAtIth(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    if (i == 0)
    {
        newNode->next = head;
        return newNode;
    }
    int count = 0;
    Node *temp = head;
    while (temp != null && count < i - 1)
    {
        count++;
        temp = temp->next;
    }
    if (temp != null)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node *deleteIthNode(Node *head, int i)
{
    if (i == 0)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    Node *temp = head;
    int count = 0;
    while ((temp != null && temp->next != null) && count < i - 1)
    {
        count++;
        temp = temp->next;
    }

    if (temp != null && temp->next != null)
    {
        Node *newConn = temp->next->next;
        delete temp->next;
        temp->next = newConn;
    }
    return head;
}

Node *insertNodeAtI(Node *head, int i, int data)
{
    if (head == null)
    {
        if (i == 0)
        {
            Node *newNode = new Node(data);
            return newNode;
        }
        return head;
    }

    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }

    Node *smallAns = insertNodeAtI(head->next, i - 1, data);
    head->next = smallAns;
    return head;
}

Node *deleteAtIth(Node *head, int i)
{
    if (head == null)
    {
        return head;
    }

    if (i == 0)
    {
        Node *newNode = head->next;
        delete head;
        return newNode;
    }

    Node *smallAns = deleteAtIth(head->next, i - 1);
    head->next = smallAns;
    return head;
}

Node *deleteNodeRec(Node *head, int pos)
{
    if (head == nullptr)
    {
        return head;
    }
    if (pos == 0)
    {
        Node *newNode = head->next;
        delete head;
        return newNode;
    }
    Node *smallAns = deleteNodeRec(head->next, pos - 1);
    head->next = smallAns;
    return head;
}

Node *midPtOfLL(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != null && fast->next != null)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }
    if (head2 == nullptr)
    {
        return head1;
    }

    Node *head = nullptr;
    Node *tail = nullptr;

    if (head1->data < head2->data)
    {
        head = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data < head2->data)
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    if (head1 != nullptr)
    {
        tail->next = head1;
    }

    if (head2 != nullptr)
    {
        tail->next = head2;
    }
    return head;
}

Node *breakLLAtMid(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *fast = head->next;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp = slow->next;
    slow->next = nullptr;
    return temp;
}

Node *mergeSort(Node *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *breakLL = breakLLAtMid(head);
    Node *head1 = mergeSort(head);
    Node *head2 = mergeSort(breakLL);
    return mergeTwoSortedLL(head1, head2);
}

Node *reverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *smallAns = reverseLL(head->next);
    head->next->next = head;
    head->next = nullptr;

    return smallAns;
}

Pair reversell(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        Pair p;
        p.head = head;
        p.tail = head;
        return p;
    }

    Pair nP = reversell(head->next);
    nP.tail->next = head;
    head->next = nullptr;
    Pair newP;
    newP.head = nP.head;
    newP.tail = head;
    return newP;
}

Node *revLLIter(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *front;

    while (curr != null)
    {
        front = curr->next;

        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

Node *removeDup(Node *head)
{
    if (head == nullptr || head->next == null)
    {
        return head;
    }
    Node *smallAns = removeDup(head->next);
    if (head->data == smallAns->data)
    {
        delete head;
        return smallAns;
    }
    head->next = smallAns;
    return head;
}

Node *remove(Node *head, unordered_map<int, bool> &m)
{
    if (head == nullptr)
    {
        return head;
    }

    if (head->next == nullptr)
    {
        m.insert({head->data, true});
        return head;
    }
    Node *smallAns = remove(head->next, m);
    if (m.count(head->data) == 1)
    {
        delete head;
        return smallAns;
    }
    m.insert({head->data, true});
    head->next = smallAns;
    return head;
}

int main()
{
    Node *head = takeInput2();
    // Node *head2 = takeInput2();
    // Node(head);
    // print(p.head);
    // print(head);
    // print(head2);

    // cout << lenOfLLRec(head);
    // printIth(head, 2);
    unordered_map<int, bool> p;
    Node *newhead = remove(head, p);
    // Node *newHead = revLLIter(head);
    print(newhead);
    cout << p.size() << endl;
    // print(head);
    // print(head2);
    // cout << newHead->data << endl;

    return 0;
}
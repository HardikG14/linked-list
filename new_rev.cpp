#include <bits/stdc++.h>
using namespace std;
#include "Node_Class.cpp"

class Pair
{
public:
    node *head;
    node *tail;
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

void print(node const *head)
{
    while (head != null)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "Null" << endl;
}

node *takeInput1()
{
    node *head = null;
    int data;
    cin >> data;
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == null)
        {
            head = newNode;
        }
        else
        {
            node *temp = head;
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

node *takeInput2()
{
    node *head = null;
    node *tail = null;
    int data;
    cin >> data;
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == null)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            // or
            // tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
/* ------------------------- length of ll iter & rec ------------------------ */
int lenOfLLiter(node *head)
{
    int len = 0;
    while (head != null)
    {
        head = head->next;
        len++;
    }
    return len;
}

int lenOfLLRec(node *head)
{
    if (head == null)
    {
        return 0;
    }

    int prev_len = lenOfLLRec(head->next);

    return 1 + prev_len;
}

/* ----------------------------- print ith node ----------------------------- */
void ithNode(node *head, int i)
{
    int count = 0;
    while (head != null && count < i)
    {
        count++;
        head = head->next;
    }
    if (head != null)
    {
        cout << head->data;
    }
}

void ithNodeRec(node *head, int i)
{
    if (head == null)
    {
        return;
    }

    if (i == 0)
    {
        cout << head->data << endl;
        return;
    }

    ithNodeRec(head->next, i - 1);
}

/* ------------------------- insert node at ith pos ------------------------- */
node *insertAtIthPos(node *head, int pos, int data)
{
    node *newNode = new node(data);
    if (pos == 0)
    {
        newNode->next = head;
        return newNode;
    }

    node *temp = head;
    int count = 0;
    while (count < pos - 1 && temp != null)
    {
        temp = temp->next;
        count++;
    }

    if (temp != null)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

node *insertNodeRec(node *head, int pos, int data)
{
    if (head == null)
    {
        if (pos == 0)
        {
            node *newHead = new node(data);
            return newHead;
        }
        return head;
    }

    if (pos == 0)
    {
        node *newNode = new node(data);
        newNode->next = head;
        return newNode;
    }

    node *newHead = insertNodeRec(head->next, pos - 1, data);
    head->next = newHead;
    return head;
}

/* ----------------------------- delete Ith Node ---------------------------- */
node *deleteNode(node *head, int pos)
{
    if (head == null)
    {
        return head;
    }

    if (pos == 0)
    {
        node *newHead = head->next;
        delete head;
        return newHead;
    }

    int count = 0;
    node *temp = head;
    while (temp != null && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == null || temp->next == null)
    {
        return head;
    }

    node *newConn = temp->next->next;
    delete temp->next;
    temp->next = newConn;

    return head;
}

node *deleteNodeRec(node *head, int pos)
{
    if (head == null)
    {
        return head;
    }

    if (pos == 0)
    {
        node *newSmall = head->next;
        delete head;
        return newSmall;
    }

    node *newHead = deleteNodeRec(head->next, pos - 1);
    head->next = newHead;
    return head;
}

/* ------------------------------- reverse ll ------------------------------- */
node *reverseLL(node *head)
{
    if (head == null || head->next == null)
    {
        return head;
    }

    node *newHead = reverseLL(head->next);
    head->next->next = head;
    head->next = null;

    return newHead;
}

// Pair revLL(node* head){
//     if(head==null||head->next==null){
//         Pair ans;
//         ans.head=head;
//         ans.tail=head;
//         return ans;
//     }

//     Pair smallAns = revLL(head->next);
//     smallAns.tail->next = head;
//     head->next = null;

//     Pair NewAns;
//     NewAns.head = smallAns.head;
//     NewAns.tail = head;

//     return NewAns;
// }

// node* revLLPair(node* head){
//     return revLL(head).head;
// }

node *revIter(node *head)
{
    if (head == null || head->next == null)
    {
        return head;
    }

    node *prev = null;
    node *fir = head;
    node *sec;

    while (fir != null)
    {
        sec = fir->next;
        fir->next = prev;

        prev = fir;
        fir = sec;
    }

    return prev;
}

/* ------------------------------ mid pt of ll ------------------------------ */
int midOfLL(node *head)
{
    if (head == null)
    {
        return 0;
    }

    node *slow = head;
    node *fast = head->next;

    while (fast != null && fast->next != null)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

/* ------------------------ Merge 2 sorted linked list ------------------------ */
node *merge2SortedLL(node *head1, node *head2)
{
    if (head1 == null)
    {
        return head2;
    }

    if (head2 == null)
    {
        return head1;
    }

    node *head = null;
    node *tail = null;

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

    while (head1 != null && head2 != null)
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

    if (head1 != null)
    {
        tail->next = head1;
    }

    if (head2 != null)
    {
        tail->next = head2;
    }
    return head;
}

/* -------------------------- merge sort functions -------------------------- */
node *breakLLAtMid(node *head)
{
    if (head == null || head->next == null)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;

    while (fast != null && fast->next != null)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *newHead = slow->next;
    slow->next = null;
    return newHead;
}

node *mergeLL(node *head1, node *head2)
{
    if (head1 == null)
    {
        return head2;
    }

    if (head2 == null)
    {
        return head1;
    }

    node *head = null;
    node *tail = null;

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

    while (head1 != null && head2 != null)
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

    if (head1 != null)
    {
        tail->next = head1;
    }

    if (head2 != null)
    {
        tail->next = head2;
    }

    return head;
}

node *mergeSort(node *head)
{
    if (head == null || head->next == null)
    {
        return head;
    }
    node *newHead = breakLLAtMid(head);
    node *fs = mergeSort(head);
    node *ss = mergeSort(newHead);
    return mergeLL(fs, ss);
}

/* ----------------------------- even after odd ----------------------------- */
node *evenAfterOdd(node *head)
{
    if (head == null || head->next == null)
    {
        return head;
    }

    node *evenH = null, *evenT = null, *oddH = null, *oddT = null;
    while (head != null)
    {
        if (head->data % 2 == 0)
        {
            if (evenH == null)
            {
                evenH = head;
                evenT = head;
                head = head->next;
            }
            else
            {
                evenT->next = head;
                evenT = head;
                head = head->next;
            }
        }
        else
        {
            if (oddH == null)
            {
                oddH = head;
                oddT = head;
                head = head->next;
            }
            else
            {
                oddT->next = head;
                oddT = head;
                head = head->next;
            }
        }
    }
    if (evenH == null)
    {
        oddT->next = null;
        return oddH;
    }
    else if (oddH == null)
    {
        evenT->next = null;
        return evenH;
    }
    else
    {
        evenT->next = null;
        oddT->next = evenH;
        return oddH;
    }
}
/* -------------------------- delete every n nodes -------------------------- */
node *deleteNNodes(node *head, int M, int N)
{
    if (head == null || M == 0)
    {
        return null;
    }

    if (N == 0)
    {
        return head;
    }
    int i = 1, j = 1;
    node *temp1 = head, *temp2, *flag;
    while (true)
    {
        while (temp1 != null && i < M)
        {
            i++;
            temp1 = temp1->next;
        }
        if (temp1 == null)
        {
            break;
        }

        temp2 = temp1->next;
        while (temp2 != null && j < N)
        {
            flag = temp2->next;
            j++;
            delete temp2;
            temp2 = flag;
        }
        if (temp2 == null)
        {
            temp1->next = null;
            break;
        }
        temp2 = temp2->next;
        temp1->next = temp2;
        temp1 = temp2;
        i = 1, j = 1;
    }
    return head;
}

/* ---------------------------------- kRev ---------------------------------- */
Pair revLL(node *head)
{
    if (head == null || head->next == null)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = revLL(head->next);
    head->next = null;
    smallAns.tail->next = head;

    Pair newAns;
    newAns.head = smallAns.head;
    newAns.tail = head;

    return newAns;
}

node *kReverse(node *head, int k)
{
    if (head == null || head->next == null)
    {
        return head;
    }

    int i = 1;
    node *temp = head;

    while (temp != null && i < k)
    {
        i++;
        temp = temp->next;
    }

    node *newHead = null;
    if (temp != null)
    {
        newHead = temp->next;
        temp->next = null;
    }

    Pair rev = revLL(head);

    node *small = kReverse(newHead, k);

    rev.tail->next = small;

    return rev.head;
}
void traversal(node *&head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data;
        ptr = ptr->next;
    }
}

/* ---------------------- intersection of two SortedLL ---------------------- */
node *intersection(node *head1, node *head2)
{
    if (head1 == null || head2 == null)
    {
        return null;
    }

    node *head = null;
    node *tail = null;

    while (head1 != null && head2 != null)
    {
        if (head1->data == head2->data)
        {
            if (head == null)
            {
                head = head1;
                tail = head1;
            }
            else
            {
                tail->next = head1;
                tail = head1;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else
        {
            head2 = head2->next;
        }
    }
    tail->next = null;
    return head;
}

/* -------------------------- linked list to number ------------------------- */
int listToNo(node *head)
{
    if (head == null)
    {
        return 0;
    }

    int sum = 0;
    while (head != null)
    {
        sum = sum * 10 + head->data;
        head = head->next;
    }

    return sum;
}

/* ------------------------ 0 1 2 sort on linked list ----------------------- */
node *sort012(node *head)
{
    if (head == null || head->next == null)
    {
        return head;
    }
    node *zH = null, *zT = null, *oH = null, *oT = null, *tT = null, *tH = null;

    while (head != null)
    {
        if (head->data == 0)
        {
            if (zH == null)
            {
                zH = head;
                zT = head;
            }
            else
            {
                zT->next = head;
                zT = head;
            }
        }
        else if (head->data == 1)
        {
            if (oH == null)
            {
                oH = head;
                oT = head;
            }
            else
            {
                oT->next = head;
                oT = head;
            }
        }
        else
        {
            if (tH == null)
            {
                tH = head;
                tT = head;
            }
            else
            {
                tT->next = head;
                tT = head;
            }
        }
        head = head->next;
    }
    zT->next = oH;
    oT->next = tH;
    tT->next = null;
    return zH;
}

/* --------------------------- max element to last -------------------------- */
void maxToLast(node *head)
{
    while (head != null && head->next != null)
    {
        if (head->data > head->next->data)
        {
            int temp = head->data;
            head->data = head->next->data;
            head->next->data = temp;
            head = head->next;
        }
        else
        {
            head = head->next;
        }
    }
}

void bubbleSort(node *head)
{
    if (head == null || head->next == null)
    {
        return;
    }
    int size = lenOfLLRec(head);
    for (int i = 0; i < size - 1; i++)
    {
        maxToLast(head);
    }
}

void deleteAlternateNodes(node *head)
{
    // Write your code here
    if (head == null || head->next == null)
    {
        return;
    }

    node *temp = head->next->next;
    delete head->next;
    head->next = temp;

    deleteAlternateNodes(head->next);
}

/* ---------------------------- print reverse ll ---------------------------- */
void printReverseLL(node *head)
{
    stack<node *> sta;
    while (head->next != null)
    {
        sta.push(head);
        head = head->next;
    }

    while (!sta.empty())
    {
        cout << sta.top()->data << " ";
        sta.pop();
    }
}
/* -------------------------------------------------------------------------- */
/* ---------------------------- remove duplicates --------------------------- */
node *removeNodes(node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        return head;
    }

    node *smallAns = removeNodes(head->next);
    if (smallAns != nullptr && smallAns->data == head->data)
    {
        node *temp = smallAns->next;
        delete smallAns;
        return temp;
    }
    else
    {
        head->next = smallAns;
        return head;
    }
}

/* ------------------------------ min max of ll ----------------------------- */
pair<int, int> minMax(node *head)
{
    if (head == nullptr)
    {
        pair<int, int> p1;
        p1.first = INT_MIN;
        p1.second = INT_MAX;
        return p1;
    }

    pair<int, int> smallAns = minMax(head->next);

    pair<int, int> ans;
    ans.first = max(head->data, smallAns.first);
    ans.second = min(head->data, smallAns.second);
    return ans;
}
int main()
{

    node *head = takeInput2();
    // node* head2 = takeInput2();
    // maxToLast(head);
    // deleteAlternateNodes(head);
    // bubbleSort(head);
    // ithNodeRec(head, 7);
    // print(head);
    node *newLL = removeNodes(head);
    print(newLL);
    // printReverseLL(head);
    // node* head1 = takeInput2();
    // print(head);
    // node *newHead = sort012(head);
    // cout<<listToNo(head);
    // print(newHead);
    return 0;
}
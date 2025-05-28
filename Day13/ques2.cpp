#include <bits/stdc++.h>
using namespace std;

struct DNode
{
    int data;
    DNode *prev, *next;
    DNode(int val)
    {
        data = val;
        prev = next = nullptr;
    }
};

void insert(DNode *&head, int val)
{
    if (!head)
    {
        head = new DNode(val);
        return;
    }

    DNode *temp = head;
    while (temp->next)
        temp = temp->next;

    DNode *newnode = new DNode(val);
    temp->next = newnode;
    newnode->prev = temp;
}

DNode *sortList(DNode *head)
{
    vector<int> vals;
    DNode *temp = head;
    while (temp)
    {
        vals.push_back(temp->data);
        temp = temp->next;
    }

    sort(vals.begin(), vals.end());

    DNode *newHead = nullptr, *last = nullptr;
    for (int val : vals)
    {
        DNode *node = new DNode(val);
        if (!newHead)
        {
            newHead = node;
        }
        else
        {
            last->next = node;
            node->prev = last;
        }
        last = node;
    }

    return newHead;
}

void print(DNode *head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    DNode *head = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert(head, val);
    }

    cout << "Original Doubly Linked List:\n";
    print(head);

    head = sortList(head);

    cout << "Sorted Doubly Linked List:\n";
    print(head);

    return 0;
}

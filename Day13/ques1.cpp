#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void insert(Node *&head, int val)
{
    if (!head)
    {
        head = new Node(val);
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new Node(val);
}

vector<Node *> split(Node *head, int k)
{
    vector<Node *> result(k, nullptr);
    int total = 0;
    Node *temp = head;

    while (temp)
    {
        total++;
        temp = temp->next;
    }

    int basesize = total / k;
    int extra = total % k;

    temp = head;
    for (int i = 0; i < k && temp; i++)
    {
        result[i] = temp;
        int partsize = basesize + (i < extra ? 1 : 0);

        for (int j = 1; j < partsize; j++)
            temp = temp->next;

        Node *nextpart = temp->next;
        temp->next = nullptr;
        temp = nextpart;
    }

    return result;
}

void print(Node *head)
{
    if (!head)
    {
        cout << "[]";
    }
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    int n, val, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert(head, val);
    }

    cout << "Enter number of parts : ";
    cin >> k;

    vector<Node *> parts = split(head, k);

    cout << "Split Parts:\n";
    for (auto part : parts)
    {
        print(part);
    }

    return 0;
}

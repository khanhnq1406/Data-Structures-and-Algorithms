#include <iostream>
using namespace std;

struct Node
{
    int data; // data of Node
    Node *next; // *link
};

void init(Node *&head)
{
    head = NULL;
}

bool isEmpty(Node *&head)
{
    return (head == NULL);
}

Node* createNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->next = NULL;
}

void addFirst(Node *&head, int value)
{
    // 1. Create new node
    Node *p = createNode(value);
    // 2. Point NEXT to HEAD node
    p->next = head;
    // 3. Point HEAD to this node
    head = p;
}

void addLast(Node *&head, int value)
{
    // 1. Create new node
    Node *p = createNode(value);
    // 2. Find last node
    if (isEmpty(head))
    {
        head = p;
    }
    else
    {
        Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        // 3. Add last
        last->next = p;
    }
}

void addAfter(Node *head, int value_node, int value_input)
{
    Node *p = createNode(value_input);
    // Find node have value_node
    Node *q = head;
    while (q != NULL && q->data != value_node)
    {
        q = q->next;
    }
    if (q != NULL)
    {
        p->next = q->next;
        q->next = p;
    }
}

Node* search(Node *head, int value_node)
{
    Node *q = head;
    while (q != NULL && q->data != value_node)
    {
        q = q->next;
    }
}

void output(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->next; 
    }
    cout << endl;
}
void deleteFirst(Node *&head)
{
    if (head != NULL)
    {
        Node *p = head;
        head = p->next;
        p->next = NULL;
        delete (p);
    }
}
void deleteLast(Node *&head)
{
    if (head != NULL)
    {
        Node *last = head;
        Node *prev_last = NULL;
        while (last->next != NULL)
        {
            prev_last = last;
            last = last->next;
        }
        if (prev_last == NULL) // only have one element
        {
            deleteFirst(head);
        }
        else
        {
            prev_last->next = NULL;
            delete(last);
        }
    }
}
void deleteNode(Node *head, int value_input)
{
    if (head != NULL)
    {
        Node *p = head;
        Node *prev = NULL;
        while (p != NULL && p->data != value_input)
        {
            prev = p;
            p = p->next;
        }
        if (p != NULL)
        {
            if (prev == NULL)
            {
                deleteFirst(head);
            }
            else
            {
                prev->next = p->next;
                p->next = NULL;
                delete(p);
            }
        }
    }
}
void clean(Node *&head)
{
    while (head != NULL)
    {
        deleteFirst(head);
    }
    
}
int main()
{
    Node *head;

    init(head);

    addLast(head, 7);
    addFirst(head, 10);
    addFirst(head, 15);
    addLast(head, 100);
    addFirst(head, 9);
    addLast(head, 99);
    output(head);

    addAfter(head, 100, 1000);
    output(head);

    deleteFirst(head);
    output(head);

    deleteLast(head);
    output(head);

    deleteNode(head, 1007);
    output(head);

    clean(head);
    if (head == NULL)
    {
        cout << "Empty" << endl;
    }
    return 0;
}
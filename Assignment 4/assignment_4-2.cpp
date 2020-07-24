#include <iostream>
#include <string.h>
using namespace std;

int ctr;
struct node
{
    int no;
    node *next;
    node *prev;
};
node *head = NULL;
node *rear = NULL;
node *create_new_node(int card)
{
    node *ptr;
    ptr = new node;
    ptr->no = card;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}
bool isEmpty()
{
    if (head==NULL)
        return true;
    else
        return false;
}
bool isFull()
{
    if (ctr == 52)
        return true;
    else
        return false;
}
void insertFront(node *new_card)
{
    if (isFull())
        return;
    if (head == NULL)
    {
        head = rear = new_card;
        ctr++;
    }
    else
    {
        head->prev = new_card;
        new_card->next = head;
        head = new_card;
        ctr++;
    }
}
void insertLast(node *new_card)
{
    if (isFull())
        return;
    if (head == NULL)
    {
        head = rear = new_card;
        ctr++;
    }
    else
    {
        rear->next = new_card;
        new_card->prev = rear;
        rear = new_card;
        ctr++;
    }
}
int deleteFront()
{
    node *temp = head;
    int ele = temp->no;
    if (head->next == NULL)
    {
        head = rear = NULL;
        delete temp;
        ctr--;
        return ele;
    }
    head = head->next;
    head->prev = NULL;

    delete temp;
    ctr--;
    return ele;
}
int deleteLast()
{
    node *temp = rear;
    int ele = temp->no;
    if (rear->prev == NULL)
    {
        head = rear = NULL;
        delete temp;
        ctr--;
        return ele;
    }
    rear = rear->prev;
    rear->next = NULL;
    delete temp;
    ctr--;
    return ele;
}
int getFront()
{
    return head->no;
}
int getRear()
{
    return rear->no;
}

int main()
{
    int i, m, n;
    cin >> n;
    cin >> m;
    char op[20];
    int no;
    head = rear = NULL;
    ctr = 0;
    node *ptr;
    for (i = 0; i < n; i++)
    {
        ptr = create_new_node(i + 1);
        insertLast(ptr);
    }
    for (i = 0; i < m; i++)
    {
        cin >> op;
        if (strcmp(op, "addFront") == 0)
        {
            cin >> no;
            ptr = create_new_node(no);
            insertFront(ptr);
        }
        else if (strcmp(op, "addRear") == 0)
        {
            cin >> no;
            ptr = create_new_node(no);
            insertLast(ptr);
        }
        else if (strcmp(op, "DrawFront") == 0)
        {
            if (!isEmpty())
                cout << deleteFront() << '\n';
            else
                cout << "Deck is empty\n";
        }
        else if (strcmp(op, "DrawRear") == 0)
        {
            if (!isEmpty())
                cout << deleteLast() << '\n';
            else
                cout << "Deck is empty\n";
        }
        else if (strcmp(op, "PeekFront") == 0)
        {
            if (!isEmpty())
                cout << getFront() << '\n';
            else
                cout << "Deck is empty\n";
        }
        else if (strcmp(op, "PeekRear") == 0)
        {
            if (!isEmpty())
                cout << getRear() << '\n';
            else
                cout << "Deck is empty\n";
        }
        else if (strcmp(op, "isEmpty") == 0)
        {
            if (isEmpty())
                cout << "Yes\n";
            else
                cout << "no\n";
        }
        else if (strcmp(op, "isFull") == 0)
        {
            if (isFull())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}

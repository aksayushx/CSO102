#include <iostream>
#include <string.h>
using namespace std;

int deck[52], front, rear, len;
bool isEmpty()
{
    if (rear == front)
        return true;
    else
        return false;
}
bool isFull()
{
    if (rear - front == 52)
        return true;
    else
        return false;
}
void insertFront(int ele)
{
    int i;
    if (isFull())
    {
        cout << "Deck is full\n";
        return;
    }
    for (i = rear - front; i > front; i--)
    {
        deck[i] = deck[i - 1];
    }
    deck[front] = ele;
    rear++;
}
void insertLast(int ele)
{
    if (isFull())
    {
        cout << "Deck is full\n";
        return;
    }
    deck[rear] = ele;
    rear++;
}
int deleteFront()
{
    int ele = deck[front];
    for (int i = front; i < rear - front - 1; i++)
    {
        deck[i] = deck[i + 1];
    }
    rear--;
    return ele;
}
int deleteLast()
{
    int ele = deck[rear - 1];
    rear--;
    deck[rear] = 0;
    return ele;
}
int getFront()
{
    return deck[front];
}
int getRear()
{
    return deck[rear - 1];
}
void printDeck()
{
    for (int i = front; i < rear - front; i++)
        cout << deck[i] << " ";
}

int main()
{
    int i, m, n;
    cin >> n;
    cin >> m;
    char op[20];
    int no;
    front = rear = 0;
    for (i = 0; i < n; i++)
    {
        deck[rear] = i + 1;
        rear++;
    }
    for (i = 0; i < m; i++)
    {
        cin >> op;
        if (strcmp(op, "addFront") == 0)
        {
            cin >> no;
            insertFront(no);
        }
        else if (strcmp(op, "addRear") == 0)
        {
            cin >> no;
            insertLast(no);
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
            if(!isEmpty())
                cout << getFront() << '\n';
            else
                cout<<"Deck is empty\n";
        }
        else if (strcmp(op, "PeekRear") == 0)
        {
            if(!isEmpty())
                cout << getRear() << '\n';
            else
                cout<<"Deck is empty\n";
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
    return 0;
}
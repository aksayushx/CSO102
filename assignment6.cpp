#include <iostream>
using namespace std;
typedef long long ll;

ll *heap;
int size;

int parent(int x)
{
    if (x > 0)
        return (x - 1) / 2;
    else
        return 0;
}
int left(int x)
{
    return 2 * x + 1;
}
int right(int x)
{
    return 2 * x + 2;
}

void push(ll x)
{
    heap[size] = x;
    size++;
    int i = size - 1;
    ll temp;
    while (i > 0 && heap[i] > heap[parent(i)])
    {
        temp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = temp;
        i = parent(i);
    }
}
void formHeap(int x)
{
    int r = right(x);
    int l = left(x);
    int big = x;
    if (l < size && heap[l] > heap[big])
        big = l;
    if (r < size && heap[r] > heap[big])
        big = r;
    if (big != x)
    {
        ll temp = heap[x];
        heap[x] = heap[big];
        heap[big] = temp;
        formHeap(big);
    }
}

ll pop()
{
    if (size == 0)
    {
        cout << "Underflow\n";
        return -1;
    }
    else if (size == 1)
    {
        size = 0;
        return heap[0];
    }
    else
    {
        ll value = heap[0];
        heap[0] = heap[size - 1];
        size--;
        formHeap(0);
        return value;
    }
}

int main()
{
    int n;
    cin >> n;
    int i, j;
    ll maximums[3];
    ll x;
    heap = new ll[n];
    size = 0;
    ll *products = new ll[n];
    for (i = 0; i < n; i++)
    {
        cin >> x;
        push(x);
        if (i < 2)
            products[i] = -1;
        else
        {
            products[i] = 1;
            for (j = 0; j < 3; j++)
            {
                maximums[j] = pop();
                products[i] *= maximums[j];
            }
            for (j = 0; j < 3; j++)
                push(maximums[j]);
        }
    }

    for (i = 0; i < n; i++)
        cout << products[i] << '\n';

    return 0;
}
#include<iostream>

using namespace std;


struct DoublyList
{
    DoublyList *next, *prev;
    int addr;
    int len;
    DoublyList(int a, int l): addr(a), len(l), next(nullptr), prev(nullptr) {}
};

DoublyList *fhead, *bhead;

int Request(int numLength)
{
    DoublyList *p = fhead;
    while (p)
    {
        if (p -> len >= numLength) break;
        p = p -> next;
    }
    if (!p) return -1;

    int ret = p -> addr;
    if (p -> len == numLength)
    {
        remove(p);
        add_to_busy(p);
    }
    else
    {
        p -> len -= numLength;
        DoublyList *w = new DoublyList(p -> addr, numLength);
        p -> addr += numLength;
        add_to_busy(w);
    }
    return ret;
}

int Release(int addr)
{
    DoublyList *p = bhead;
    while (p && p -> addr != addr) p = p -> next;
    if (!p) return -1;

    remove(p);
    add_to_free(p);
    return 0;
}

int main()
{
    fhead = new DoublyList(0, 100);
}
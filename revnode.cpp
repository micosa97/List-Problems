#include <iostream>
using namespace std;

struct node
{
    int w;
    node *next;
};
node *rev (node *p, node*q) //null and first na pocz¹tku //wskaznik na poprzedni do ktorego trzeba sie odwolac w last oraz first;
{
        if (q==NULL) return p;
        node *r = q->next;
        q->next = p;
        return rev (q, r);

}

node *revunrec (node *p)
{
    node *q = NULL, *r;
    while (p!=NULL)
    {

        //swap (q, p->next);
        p->next=(node*)((int)(q)^(int)(p->next));
        q=(node*)((int)(q)^(int)(p->next));
        p->next=(node*)((int)(q)^(int)(p->next));
        p=(node*)((int)(q)^(int)(p));
        q=(node*)((int)(q)^(int)(p));
        p=(node*)((int)(q)^(int)(p));
        //swap (p, q);

    }
    return q;
}
void wstaw (int w, node* &p)
{
    node* q = new node;
    q->w=w;
    q->next=p;
    p=q;
}

int main ()
{
    node *p = NULL;
    for (int i=0; i<5; i++)
    {
        int a;
        cin>>a;
        wstaw (a, p);
    }


    p = rev (NULL, p);
    p = revunrec (p);

    while (p!=NULL)
    { //listing from end to beg

        cout<<p->w;
        p=p->next;
    }



}


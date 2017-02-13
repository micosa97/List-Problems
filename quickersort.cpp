#include <iostream>
using namespace std;

struct node
{
    int w;
    node *next;
};
void create (node *&x, int arr[], int length)
{
    node *tmp = NULL;
    for (int i=0; i<length; i++)
    {
        x = new node;
        x -> w = arr[i];
        x -> next = tmp;
        tmp = x;
    }
}
void show (node *beg)
{
    while (beg != NULL)
    {
        cout << beg -> w << "  ";
        beg = beg -> next;
    }
    cout << endl;
}

void qs (node *&p, node *e)  //p - prime e - end, q - ghost, c - pivot a- actual k - kopia
{
    if (p==e) return;
    if (p->next==e and p->w<=e->w) return;
    node *k=e->next;

    node *c=p;
    node *q=p;
    node *a=p->next;
    while (a!=k)
    {

        if (a->w<c->w)
        {
            //node *tmp;
            q->next=a->next;
            a->next=p;
            p=a;
            a=q->next;

        } else
        {
            q=a;
            a=a->next;
        }
    }
    qs (p, c);
    if (c->next!=NULL)
    qs (c->next, q);
    return;

}

void quicksort (node *&p)
{
    if (p==NULL) return;
    node *c=p;
    while (c->next!=NULL)
    {
        c=c->next;
    }
    qs (p, c);
    return;
}

int main() {
    node *x = NULL;
    int t[10] =   {3,7,1,12,16,9,4,2,3,7};
    create(x,t,10);
    show(x);
    quicksort (x);
    show(x);


}

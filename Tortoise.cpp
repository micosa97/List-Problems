#include<iostream>
using namespace std;
struct node{
    node* next;
};
int LengthOfCycle(node* first){
    node* A = first;
    node* B = first;
    // przy A skacze o jeden przy B o dwa. Jak si� spotkaj�, to znaczy, �e jeste�my w cyklu
    do
    {
        A = A->next;
        B = B->next->next;
    } while(A != B);

    int length = 1; //oblicza d�ugo�� cyklu
    B = B->next;
    while(B!=A){
        B = B->next;
        length++;
    }
    return length;
}
int main(){
    node* first = new node;
    node* last = first;
    for(int i = 0; i<3; i++){
        last->next = new node;
        last = last->next;
    }
    node* middle = last;
    for(int i = 0; i<5; i++){
        last->next = new node;
        last = last->next;  //przyk�adowy test
    }
    last->next = middle;
    cout << LengthOfCycle(first) << endl;

}

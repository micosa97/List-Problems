/*Quite useless, but interesting Algo. Let us consider a directed list with a loop. In fact, there's no end of the list. 
Point is to find length of the loop. It's not obvious, because we don't know if we are "in loop" in the beginning.*/

#include<iostream>
using namespace std;
struct node{
    node* next;
};
int LengthOfCycle(node* first){
    node* A = first;
    node* B = first;
    // przy A skacze o jeden przy B o dwa. Jak siê spotkaj¹, to znaczy, ¿e jesteœmy w cyklu
    do
    {
        A = A->next;
        B = B->next->next;
    } while(A != B);

    int length = 1; //oblicza d³ugoœæ cyklu
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
        last = last->next;  //przyk³adowy test
    }
    last->next = middle;
    cout << LengthOfCycle(first) << endl;

}

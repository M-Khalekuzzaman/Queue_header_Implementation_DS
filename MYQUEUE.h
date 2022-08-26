#include<bits/stdc++.h>
using namespace std;

template <typename N> class Node
{
public:
    N data;
    Node *Next;

    //Constructor declare
    Node(N data)
    {
        this -> data = data;
        this -> Next = NULL;
    }
};

template <typename Q> class Queue
{
    Node <Q> *Front;
    Node <Q> *Rear;
    int count;
public:
    Queue()
    {
        this -> Front = NULL;
        this -> Rear = NULL;
        this -> count = 0;
    }
    //ENQUEUE
    void enqueue(Q value)
    {
        Node <Q> *newNode = new Node<Q>(value);
        if(Front == NULL && Rear == NULL)
        {
            Front = Rear = newNode;
            count++;
            return;
        }
        Rear->Next = newNode;
        Rear = Rear->Next;
        count++;
    }
    //DEQUEUE
    Q dequeue(void)
    {
        Node <Q> *delNode = Front;
        Q chk;
        if(Rear == NULL)
        {
            cout<<"Queue is Underflow"<<endl;
            return chk;
        }
        Front = Front->Next;
        if(Front == NULL)
        {
            Rear = NULL;
        }
        chk = delNode->data;
        count--;
        delete delNode;

        return chk;
    }
    //PEAK
    Q peakFront(void)
    {
        Q chk;
        if(Front == NULL) return chk;
        else{
            chk = Front->data;
            return chk;
        }
    }
    Q peakBack(void)
    {
        Q chk;
        if(Rear == NULL) return chk;
        else{
            chk = Rear->data;
            return chk;
        }
    }
    //EMPTY
    bool empty(void)
    {
        if(Front == NULL) return true;
        else false;
    }
    //SIZE
    int size(void)
    {
        return count;
    }
    //MID-VALUE
    Q mid(void){
        Node <Q> *slow = Front;
        Node <Q> *fast = Front;
        while(fast != NULL && fast->Next != NULL){
            slow = slow->Next;
            fast = fast->Next;
        }

        return slow->data;
    }
};


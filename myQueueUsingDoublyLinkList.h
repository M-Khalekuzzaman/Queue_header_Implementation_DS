#include<bits/stdc++.h>
using namespace std;

template <typename N> class Node
{
public:
    N data;
    Node *Next;
    Node *Prev;

    //Constructor declare
    Node(N data)
    {
        this -> Prev = NULL;
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
    //Setter function has called
    Queue(void)
    {
        this -> Front = NULL;
        this -> Rear = NULL;
        this -> count = 0;
    }
    //ENQUEUE --> PUSH
    void enqueue(Q value)
    {
        Node <Q> *newNode = new Node <Q>(value);
        if(Front == NULL && Rear == NULL)
        {
            Front = Rear = newNode;
            count++;
            return;
        }
        Rear->Next = newNode;
        newNode->Prev = Rear;
        Rear = Rear->Next;
        count++;
    }
    //DEQUEUE --> POP
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
        Front->Prev = NULL;
        delete delNode;
        count--;

        return chk;
    }
    //PEAK --> TOP
    //1) PEAKFRONT
    //2) PEAKBACK
    Q peakFront(void)
    {
        Q chk;
        if(Front == NULL)
        {
            return chk;
        }
        else
        {
            chk = Front->data;
            return chk;
        }
    }

    Q peakBack(void)
    {
        Q chk;
        if(Rear == NULL)
        {
            return chk;
        }
        else
        {
            chk = Rear->data;
            return chk;
        }
    }
    //EMPTY
    bool empty(void){
        if(Front == NULL) return true;
        else return false;
    }
    //SIZE
    int size(void)
    {
        return count;
    }
    //MID-VALUE
    Q mid(void)
    {
        Node <Q> *slow;
        Node <Q> *fast;
        while(fast != NULL && fast->Next != NULL){
            slow = slow->Next;
            fast = fast->Next;
        }

        return slow->data;
    }

};

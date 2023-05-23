#include <iostream>
#define size 4
using namespace std;

struct queue{
    int items[size];
    int front,rear;
};

void initQueue(struct queue *pq){
    pq->front = -1;
    pq->rear = -1;
}

bool isQueueempty(struct queue *pq){
    if (pq->rear == -1)
    {
        return true;
    }
    return false;
}

bool isQueuefull(struct queue *pq){
    if (pq->rear == size - 1)
    {
        return true;
    }
    return false;
}

void insert(struct queue *pq, int value){
    if (isQueuefull(pq))
    {
       cout<<"Queue is full"<< endl;
       return;
    }
    pq->rear++;
    pq->items[pq->rear] = value;
    if (pq->front == -1)
    {
        pq->front = 0;
    }
    
}

int remove(struct queue *pq){
    int value;
    if (isQueueempty(pq))
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    value = pq->items[pq->front];
    pq->front++;
    if (pq->front > pq->rear)
    {
       pq->front = pq->rear = -1;
    }
    return value;
}

void copy_Queue(struct queue *p, struct queue *q){
    struct queue temp2;
    int a, b;
    initQueue(&temp2);

    cout<<"Original Queue is: "<<endl;
    while (isQueueempty(p)==0)
    {
       a = remove(p);

       cout<<a<<endl;
       insert(&temp2,a);
    }

    cout<<"Copied Queue is :"<<endl;
    while (isQueueempty(&temp2)==0)
    {
       b = remove(&temp2);
       cout<<b<<endl;
       insert(q,b);
       // cout<<q;
    }
    
    
}

int main()
{
    struct queue pq;
    struct queue pq2;
    initQueue(&pq);
    initQueue(&pq2);
    insert(&pq, 1);
    insert(&pq, 2);
    insert(&pq, 3);
    


    copy_Queue(&pq,&pq2);
    system("PAUSE");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

const int MAX_PRIORITY = 999;

typedef struct
{

  int num;
  struct Qnode *next;
  int prty;

} Qnode, *QnodePtr;

typedef struct Queue
{

    QnodePtr top;
    QnodePtr tail;

} Queuetype, *Queue;

Queue initQueue();
int isEmpty(Queue q);
void enqueue(Queue q, int num);
void pEnqueue(Queue q, int num, int prty);
int dequeue(Queue q);

int main()
{
    Queue q = initQueue();
    enqueue(q, 54);
    enqueue(q, 32);
    enqueue(q, 12);
    enqueue(q, 27);
    enqueue(q, 34);
    pEnqueue(q,2, 1);
    pEnqueue(q,8, 5);
    while(!isEmpty(q))
    {

        printf("%d\n", dequeue(q));

    }
    return 0;
}

Queue initQueue()
{
    Queue newQueue = malloc(sizeof(Queuetype));
    newQueue->top = NULL;
    newQueue->tail = NULL;
    return newQueue;

}

int isEmpty(Queue q)
{return q->top == NULL;}

void enqueue(Queue q, int num)
{
    QnodePtr newNode = malloc(sizeof(Qnode));
    newNode->num = num;
    newNode->next = NULL;
    newNode->prty = MAX_PRIORITY;

    if(isEmpty(q)) {q->top = newNode; q->tail = newNode;}
    else
    {
            q->tail->next = newNode;
            q->tail = newNode;

    }

}

void pEnqueue(Queue q, int num, int prty)
{

    QnodePtr newNode = malloc(sizeof(Qnode));
    newNode->num = num;
    newNode->next = NULL;
    newNode->prty = prty;

    if(isEmpty(q)) {q->top = newNode; q->tail = newNode;}
    else
    {
            q->tail->next = newNode;
            q->tail = newNode;

            QnodePtr temp = q->top;
            if(temp->prty > newNode->prty)
            {
                q->top = newNode;
                newNode->next = temp;
                return;

            }

            while(temp->next != NULL && temp->next->prty < newNode->prty)
                {temp = temp->next;}

            if(temp->next != NULL) {newNode->next = temp->next;}
            temp->next = newNode;

    }

}

int dequeue(Queue q)
{

    if(isEmpty(q)) {printf("Queue is already empty, no nodes to remove"); return;}
    QnodePtr temp = q->top;
    int tempNum = q->top->num;
    q->top = q->top->next;
    free(temp);
    return tempNum;

}

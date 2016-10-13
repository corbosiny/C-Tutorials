#include <stdio.h>
#include <stdlib.h>

const int MAX_PRIORITY = 999;

typedef struct
{

  int num;
  struct Qnode *next;
  int priority;

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
    pEnqueue(q,2, -10);
    pEnqueue(q,8, 1);

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
    newNode->priority = MAX_PRIORITY;

    if(!isEmpty(q))
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    else
    {
        q->top = newNode;
        q->tail = newNode;
    }

}

void pEnqueue(Queue q, int num, int prty)
{

    QnodePtr newNode = malloc(sizeof(Qnode));
    newNode->num = num;
    newNode->next = NULL;
    if(prty > MAX_PRIORITY) {prty = MAX_PRIORITY;}
    newNode->priority = prty;

    if(!isEmpty(q))
    {

        if(newNode->priority < q->top->priority) {newNode->next = q->top; q->top = newNode;}
        else
        {
            QnodePtr prevTemp = q->top;
            QnodePtr temp = q->top->next;
            while(temp != NULL && temp->priority < newNode->priority)
            {
                prevTemp = temp;
                temp = temp->next;
            }

            if(temp == NULL) {prevTemp->next = newNode; q->tail = newNode;}
            else{newNode->next = temp; prevTemp->next = newNode;}

        }

    }
    else
    {
        q->top = newNode;
        q->tail = newNode;
    }

}

int dequeue(Queue q)
{

  if(isEmpty(q)) {printf("Queue is empty"); return;}
  int topNum = q->top->num;
  QnodePtr temp = q->top;
  q->top = q->top->next;
  free(temp);
  return topNum;

}

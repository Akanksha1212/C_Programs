// Queue implementation using Single Link list

#include<stdio.h>
#include<stdlib.h>

#define capacity 100

struct Queue{
   int front, rear , size ;
   int arr[capacity];
};

void init(struct Queue * queue){
    queue->front = 0;
    queue->rear = capacity-1;
    queue->size = 0;
}

int isEmpty(struct Queue * queue){
    return queue->size == 0;
}

int isFull(struct Queue * queue){
    return queue->size == capacity;
}

int front(struct Queue * queue){
    return queue->arr[queue->front];
}

int rear(struct Queue * queue){
    return queue->arr[queue->rear];
}

int enqueue(struct Queue * queue, int data){
    if(isFull(queue)){
        printf("Queue is overflow\n");
        return 0;
    }

    queue->rear = (queue->rear + 1 ) % capacity;
    queue->arr[queue->rear] = data;
    queue->size++;
    printf("%d enqueued to queue\n", data); 
    return 1;
}

int dequeue(struct Queue * queue){
    if(isEmpty(queue)){
        printf("Queue is Empty\n");
        return -1;
    }
    
    int temp = queue->arr[queue->front];
    queue->front = (queue->front + 1) % capacity;
    queue->size--;
    return temp;

}

int main(){

    struct Queue Q;
    struct Queue *queue = &Q;

    enqueue(queue, 10); 
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40); 
  
    //printf("%d dequeued from queue\n\n", dequeue(queue)); 
  
    printf("Front item is %d\n", front(queue)); 
    printf("Rear item is %d\n", rear(queue)); 
  
    
    return 0;
}
#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 1000

class Queue{
	int rear; 
	int front;
public:
	int queue_arr[MAX];
	Queue(){
		rear = -1;
		front = -1;
	}
	void insert(int x);
	int del();
	int peek();
	int isEmpty();
	int isFull();
	void display(); 

};


void Queue::insert(int data){
	if(isFull()){
		cout<<"Queue Overflow\n";
		return;
	}
	if(front == -1)
		front = 0;
	rear = rear + 1;
	queue_arr[rear] = data;
}


int Queue::del(){
	int data;
	if(isEmpty()){
		cout<<"Queue Underflow\n";
		exit(1);
	}
	data = queue_arr[front];
	front += 1;
	return data;
}


int Queue::peek(){
	if(isEmpty()){
		cout<<"Queue Underflow\n";
		exit(1);
	}
	return queue_arr[front];
}


int Queue::isEmpty(){
	if(front == -1 || front == rear+1)
		return 1;
	else
		return 0;
}

int Queue::isFull(){
	if(rear == MAX-1)
		return 1;
	else
		return 0;
}


void Queue::display(){
	if(isEmpty()){
		cout<<"Queue Underflow\n";
		return ;
	}
	cout<<"Queue is: \n";
	for(int i=front; i<=rear; i++){
		cout<<queue_arr[i]<<"\n";
	}
}


int main(){
	int a;
	Queue q;
	q.display();
	q.insert(2);
	q.insert(4);
	q.insert(6);
	q.display();
	q.del();
	q.display();
	a = q.peek();
	cout<<"The top element is: "<<a<<"\n";
	q.insert(8);
	q.display();

	return 0;
}

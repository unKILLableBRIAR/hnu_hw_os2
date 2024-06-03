#include <iostream>

using namespace std;

//Queue 구현
typedef struct queue_node {
	int data;
	struct queue_node* next;
}QNode;

//Stack 구현
typedef struct Node {
	QNode** Front; //enqueue 및 dequeue과정에서 변경을 위해 이중포인터 선언 및 정의
	QNode** Rear;
	struct Node* next;
}Node;

//Queue ADT 구현
QNode* createQueue(int data) {
	QNode* tmp = new QNode;
	tmp->data = data;
	tmp->next = NULL;

	return tmp;
}

int isEmpty_q(Node* node) {
	if (*(node->Front) == NULL) return 1;
	else return 0;
}

void enqueue(Node* node, int data_q) {
	QNode* tmp = new QNode;
	tmp->data = data_q;
	tmp->next = NULL;

	if (isEmpty_q(node)) {
		*(node->Front) = tmp;
		*(node->Rear) = tmp;
	}
	else {
		(*(node->Rear))->next = tmp;
		*(node->Rear) = tmp;
	}
}

int dequeue(Node* node) {
	if (isEmpty_q(node)) {
		cout << "Queue is empty!\n";
		return 0;
	}
	else {
		int resert = (*(node->Front))->data;
		QNode* tmp = *(node->Front);
		*(node->Front) = (*(node->Front))->next;

		if (isEmpty_q(node)) {
			*(node->Rear) = NULL;
		}

		delete(tmp);
		return resert;
	}
}

//Stack ADT구현
int isEmpty(Node* top) {
	if (top == NULL) return 1;
	else return 0;
}

void push(Node** top, QNode** Front_q) {
	QNode* tmp_q = *Front_q;

	while (tmp_q->next != NULL) {
		tmp_q = tmp_q->next;
	}
	
	Node* tmp = new Node;
	tmp->Front = Front_q;
	tmp->Rear = &tmp_q;
	tmp->next = *top;
	*top = tmp;
}

void pop(Node** top) {
	if (isEmpty(*top)) {
		cout << "Stack is empty.\n";
	}
	else {
		Node* tmp = *top;
		*top = (*top)->next;
		delete tmp;
	}
}



int main() {
	Node* top = NULL;
	
	QNode* tmp = createQueue(100);
	push(&top, &tmp);
	enqueue(top, 200);
	enqueue(top, 300);
	enqueue(top, 500);

	QNode* tmp_2 = createQueue(200);
	push(&top, &tmp_2);
	enqueue(top, 1);
	enqueue(top, 2);
	enqueue(top, 3);
	enqueue(top, 4);
	enqueue(top, 5);
	enqueue(top, 6);

	while (!isEmpty_q(top)) {
		cout << dequeue(top) << '\n';
	}
	pop(&top);

	while (!isEmpty_q(top)) {
		cout << dequeue(top) << '\n';
	}
	pop(&top);

	return 0;
}
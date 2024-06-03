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
int isEmpty_q(Node* node) {
	if (*(node->Front) == NULL) return 1;
	else return 0;
}

void enqueue(Node* node, int data_q) {
	QNode* tmp = new QNode;
	tmp->data = data_q;

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

void push(Node** top, int data) {
	Node* tmp = new Node;
	tmp->data = data;
	tmp->next = *top;
	*top = tmp;
}

int pop(Node** top) {
	int tmp_int;
	Node* tmp = *top;

	if (*top == NULL) {
		cout << "Stack is empty.\n";
		return 0;
	}
	else {
		tmp_int = tmp->data;
		*top = tmp->next;
		delete(tmp);
		return tmp_int;
	}
}



int main() {
	Node* top = NULL;


}
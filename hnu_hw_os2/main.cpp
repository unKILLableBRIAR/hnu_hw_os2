#include <iostream>

using namespace std;

typedef struct Node {
	int data;
	struct Node* next;
}Node;

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
	for (int i = 0; i < 10; i++) {
		push(&top, i * 2 + 17);
	}

	cout << isEmpty(top) << '\n';

	for (int i = 0; i < 10; i++) {
		cout << pop(&top) << '\n';
	}

	cout << isEmpty(top) << '\n';

	delete(top);

	return 0;
}
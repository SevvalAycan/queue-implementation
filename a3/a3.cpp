#include <iostream>
using namespace std;

class Node {

public:

	int data;
	Node* next;
	Node* prev;

};

class Queue {

public:

	Queue();

	void enqueue(int);
	void dequeue();
	void print();
	bool empty();
	int size();
	int getFront();
	int getBack();
	int findMax(Queue Qa);


private:

	Node* head;
	Node* tail;

};

Queue::Queue() {

	head = NULL;
	tail = NULL;
}

bool Queue::empty() {


	if (head == NULL) {

		return true;
	}

	else {

		return false;
	}



}

void Queue::enqueue(int value) {

	Node* node = new Node();
	node->data = value;

	if (empty() == false) {

		node->prev = tail;
		tail->next = node;
		node->next = NULL;
		tail = node;
	}
	else {

		node->next = NULL;
		node->prev = NULL;
		head = node;
		tail = node;

	}
}

void Queue::dequeue() {


	if (empty() == false) {

		Node* temp = head;
		head = temp->next;
		head->prev = NULL;
		free(temp);

	}
	else {

		cout << "QUEUE IS EMPTY!";
	}
}

int Queue::size() {

	int count = 0;
	Node* temp = head;

	while (temp != NULL) {
		count++;
		temp = temp->next;
	}

	cout << count;
	return count;
}

int Queue::getFront() {

	int a = head->data;


	return a;

}

int Queue::getBack() {


	int a = tail->data;


	return a;


}

int Queue::findMax(Queue Qa) {

	Queue Q = Qa;


	if (empty() == false) {

		while (head->next != NULL) {

			if (head->data <= tail->data) {

				dequeue();

			}
			else {

				enqueue(head->data);
				dequeue();


			}
		}

		return head->data;


	}
	else {

		cout << "QUEUE IS EMPTY!";
	}



}

void Queue::print() {

	Node* temp = head;

	while (temp->next != NULL) {

		cout << temp->data << " ";
		temp = temp->next;

	}

	cout << temp->data << " ";

}

int main() {

	Queue Q1;

	cout << "QUEUE :";
	Q1.enqueue(5);
	Q1.enqueue(4);
	Q1.enqueue(6);
	Q1.enqueue(9);
	Q1.enqueue(3);
	cout << Q1.print(); << "\n";
	cout << "size:" Q1.size(); << "\n";
	cout << "Rair:" Q1.getBack(); << "\n";
	cout << "Front: "Q1.getFront(); << "\n";
	cout << "Max of queue is :";
	cout << Q1.findMax(Q1) << endl;



	return 0;
}
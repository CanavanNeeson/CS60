#include <iostream>
#include "node.h"

void list_clear(node*&, node*&);

int main() {
	node *head = new node(0, nullptr);
	node *tail = head;
	for (int i = 1; i < 5; i++) {
		head = new node(i, head);
	}
	
	node *temp = head;
// 	std::cout << head->link() << ' ' << tail->link() << std::endl;
	while (temp != nullptr) {
		std::cout << temp->data() << ' ';
		temp = temp->link();
	}
	std::cout << std::endl;
	
	
	list_clear(head, tail);
// 	std::cout << "Still running\n";//Testing
	
	temp = head;
	while (temp != nullptr) {
		std::cout << temp->data() << ' ';
		temp = temp->link();
	}
	std::cout << std::endl;
	
	return 0;
}

void list_clear(node* & head, node* & tail) {
	node *temp;
// 	int i = 0;//Testing
	while (head != nullptr) {
// 		std::cout << i << ' ';//Testing
// 		i++;//Testing
		head->set_data(0);
		temp = head->link();
		delete head;
		head = temp;
	}
}
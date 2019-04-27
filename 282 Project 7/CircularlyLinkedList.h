// CircularlyLinkedList.h
/////////////////////

#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
class CircularlyLinkedList
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	CircularlyLinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	~CircularlyLinkedList() {

	}

	int size() {
		return size;
	}

	bool isEmpty() {
		if (size == 0) {
			return true;
		}
		return false;
	}

	T first() {
		return head->data;
	}

	T last() {
		return tail->data;
	}

	void addFirst(T data) {
		// create new temp node
		Node <T> temp = new Node <T>;

		// assign the given data
		temp->data = data;

		// insert the node at the beginning of the list
		temp->next = head;

		// change the head to the current node
		head = temp;
	}

	void addLast(T data) {
		// create new temp node
		Node <T> temp = new Node <T>;

		// assign the given data
		temp->data = data;

		// the next node after that should be NULL 
		// since its the end of the list
		temp->next = NULL;

		// insert the node at the end of the list
		tail->next = temp;

		// update last node
		tail = temp;
	}

	T removeFirst() {
		// get the contents of the first node
		T data = head->data;

		// replace the first node with the second one
		head = head->next;
	}

	T removeLast() {
		// get the contents of the last node
		T data = tail->data;

		// remove the last node in the list
		
		// create temp current var
		Node <T> current = head;
		// iterate to the second to last node
		for (int i = 0; i < size - 1; i++) {
			current = current.next;
		}

		// remove the last node
		current->next = NULL;

		// update tail
		tail = current;
	}

	void display() {
		cout << toString();
	}

	string toString() {
		string str = "";

		// temp node to look at data
		Node <T> current = head;

		// get all contents besides the last one
		for (int i = 0; i < size - 1; i++) {
			// add the current data to the string
			str += current->data + ", ";

			// go to the next node
			current = current->next;
		}
		
		// add the last data without a comma
		str += current->data;

		// return the tostring
		return str;
	}
};


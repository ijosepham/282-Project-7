// DoublyLinkedList.h
/////////////////////

#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
	Node* prev;
};

template <typename T>
class DoublyLinkedList
{
private:
	Node* header;
	Node* trailer;
	int size;
public:
	DoublyLinkedList() {
		header = NULL;
		trailer = NULL;
		size = 0;
	}

	~DoublyLinkedList() {

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

	}

	T last() {

	}
	
	void addFirst(T data) {

	}

	void addLast(T data) {

	}

	T removeFirst() {

	}

	T removeLast() {

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


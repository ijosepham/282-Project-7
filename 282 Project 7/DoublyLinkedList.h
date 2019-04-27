// DoublyLinkedList.h
/////////////////////

#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
template <typename T>
struct Node {
	T data;
	Node* next;
	Node* prev;
};
*/

template <typename T>
class DoublyLinkedList
{
private:
	Node <T>* header;
	Node <T>* trailer;
	int length;
public:
	DoublyLinkedList() {
		header = NULL;
		trailer = NULL;
		length = 0;
	}

	~DoublyLinkedList() {

	}

	int size() {
		return length;
	}

	bool isEmpty() {
		if (length == 0) {
			return true;
		}
		return false;
	}

	T first() {
		return new T;
	}

	T last() {
		return new T;
	}
	
	void addFirst(T data) {

	}

	void addLast(T data) {

	}

	T removeFirst() {
		return new T;
	}

	T removeLast() {
		return new T;
	}

	void display() {
		cout << toString();
	}

	string toString() {
		// any datatype to string
		stringstream stream;
		// temp string of each element
		string temp = "";
		// entire tostring 
		string str = "";

		// temp node to look at data
		Node <T>* current = header;

		// get all contents besides the last one
		for (int i = 0; i < length - 1; i++) {
			// add the current data to the string
			stream << current->data << ", ";

			// put the element string on temp
			stream >> temp;

			// add the temp string to the entire tostirng
			str += temp;

			// go to the next node
			current = current->next;
		}

		// add the last data without a comma
		stream << current->data;

		// add the last temp string to the tostring
		stream >> temp;
		str += temp;

		// return the tostring
		return str;
	}
};


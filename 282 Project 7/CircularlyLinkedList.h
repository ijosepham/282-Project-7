// CircularlyLinkedList.h
/////////////////////

#pragma once
#include <iostream>
#include <sstream>
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
	Node <T>* head;
	Node <T>* tail;
	int length;
public:
	CircularlyLinkedList() {
		head = NULL;
		tail = NULL;
		length = 0;
	}

	~CircularlyLinkedList() {

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
		return head->data;
	}

	T last() {
		return tail->data;
	}

	void addFirst(T data) {
		// create new temp node
		Node <T>* temp = new Node <T>;

		// assign the given data
		temp->data = data;

		// insert the node at the beginning of the list
		temp->next = head;

		// change the head to the current node
		head = temp;

		// increase size
		length++;

		// if size is now 1, tail is also head
		if (length == 1) {
			tail = head;
		}
	}

	void addLast(T data) {
		// create new temp node
		Node <T>* temp = new Node <T>;

		// assign the given data
		temp->data = data;

		// the next node after that should be NULL 
		// since its the end of the list
		temp->next = NULL;

		// if the list is empty
		if (length == 0) {
			head = temp;
			tail = temp;
		}
		else { // list isnt empty
			// insert the node at the end of the list
			tail->next = temp;

			// update last node
			tail = temp;
		} 

		// increase size
		length++;
	}

	T removeFirst() {
		// get the contents of the first node
		T data = head->data;

		// replace the first node with the second one
		head = head->next;

		// decrease size
		length--;
	}

	T removeLast() {
		// get the contents of the last node
		T data = tail->data;

		// remove the last node in the list
		
		// create temp current var
		Node <T>* current = head;

		// iterate to the second to last node
		for (int i = 0; i < size - 1; i++) {
			current = current.next;
		}

		// remove the last node
		current->next = NULL;

		// update tail
		tail = current;

		// decrease size
		length--;
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
		Node <T>* current = head;

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


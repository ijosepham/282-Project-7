// CircularlyLinkedList.h
/////////////////////

#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
struct CNode {
	// data of the node
	T data;

	// reference to the next node in the list
	CNode* next;
};

template <typename T>
class CircularlyLinkedList
{
private:
	// represents the first node in the list
	CNode <T>* head;

	// represents the last node in the list, points to the head
	CNode <T>* tail;

	// size of the list
	int length;
public:
	// description: default constructor
	CircularlyLinkedList() {
		head = new CNode <T>;
		tail = new CNode <T>;

		head->data = NULL;
		head->next = tail;

		tail->data = NULL;
		tail->next = head;

		length = 0;
	}

	// description: destructor
	~CircularlyLinkedList() {

	}

	// description: gets the size of the list
	// postcondition: size of the list
	int size() {
		return length;
	}

	// description: returns whether the list is empty or not
	// postcondition: t/f if list is empty
	bool isEmpty() {
		if (length == 0) {
			return true;
		}
		return false;
	}

	// description: gets the first item in the list
	// postcondition: first item in the list
	T first() {
		if (length > 0) {
			return head->data;
		}
		else {
			cout << "The list is empty.";
			return NULL;
		}
	}

	// description: gets the last item in the list
	// postcondition: last item in the list
	T last() {
		if (length > 0) {
			return tail->data;
		}
		else {
			cout << "The list is empty.";
			return NULL;
		}
	}

	// description: adds the data to the list at the beginning of thelist
	// preconditions: data - data to add to the list
	void addFirst(T data) {
		// create new temp node
		CNode <T>* temp = new CNode <T>;

		// assign the given data
		temp->data = data;

		// insert the node at the beginning of the list
		temp->next = head;

		// change the head to the current node
		head = temp;

		// increase size
		length++;

		// if size is now 1, head points to tail, and tail points to head
		if (length == 1) {
			tail->data = head->data;
			head->next = tail;
			tail->next = head;
		}
	}

	// description: adds the data to the list at the end of thelist
	// preconditions: data - data to add to the list
	void addLast(T data) {
		// create new temp node
		CNode <T>* temp = new CNode <T>;

		// assign the given data
		temp->data = data;

		// the next node after that should be NULL 
		// since its the end of the list
		temp->next = NULL;

		// increase size
		length++;

		// if size is now 1
		if (length == 1) {
			// both head and tail are the same
			head = temp;
			tail = temp;

			// and they point to eachother
			head->next = tail;
			tail->next = head;
		}
		else { // list isnt empty
			// insert the node at the end of the list
			tail->next = temp;

			// update last node
			tail = temp;
		}
	}

	// description: removes and returns the first item in the list
	// postcondition: the first item in the list
	T removeFirst() {
		// check if lsit is empty
		if (length > 0) {
			// get the contents of the first node
			T data = head->data;

			// replace the first node with the second one
			head = head->next;

			// decrease size
			length--;

			// if the list is empty/size 1, both head and tail are the same
			if (length == 0 || length == 1) {
				tail = head;

				// and they point to eachother
				head->next = tail;
				tail->next = head;
			}

			// return the data
			return data;
		}
		else {
			cout << "The list is empty.";
			return NULL;
		}
	}

	// description: removes and returns the last item in the list
	// postcondition: the last item in the list
	T removeLast() {
		// check if its empty
		if (length > 0) {
			// get the contents of the last node
			T data = tail->data;

			// remove the last node in the list

			// create temp current var
			CNode <T>* current = head;

			// iterate to the second to last node
			for (int i = 0; i < length - 2; i++) {
				current = current->next;
			}

			// remove the last node
			current->next = NULL;

			// update tail
			tail = current;

			// decrease size
			length--;

			// if the list is empty/size 1, both head and tail are the same
			if (length == 0 || length == 1) {
				tail = head;

				// and they point to eachother
				head->next = tail;
				tail->next = head;
			}

			// return the data
			return data;
		}
		else {
			cout << "The list is empty.";
			return NULL;
		}
	}

	// description: prints out the list
	void display() {
		cout << toString();
	}

	// description: gets a stirng representation of the list
	// postcondition: the list
	string toString() {
		// check if the list is empty
		if (length > 0) {
			// any datatype to string
			stringstream stream;
			// temp string of each element
			string temp = "";
			// entire tostring 
			string str = "";

			// temp node to look at data
			CNode <T>* current = head;

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
		else {
			return "The list is empty.";
		}
	}

	void rotate() {
		// if size is 2 or bigger
		if (length > 1) {
			// temp node to keep track of, but it points to null
			CNode <T>* temp = new CNode <T>;
			temp->data = head->data;
			temp->next = NULL;
			
			// delete the first node by updating head
			head = head->next;

			// add the head to the end of the list
			tail->next = temp;

			// update the tail
			tail = temp;
		}
		// else do nothing
	}
};


// DoublyLinkedList.h
/////////////////////

#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct DNode {
	// data of the node
	T data;

	// reference to the next node in the list
	DNode* next;

	// reference to the previous node in the list
	DNode* prev;
};

template <typename T>
class DoublyLinkedList
{
private:
	// dummy node that represents the beginning of the list
	DNode <T>* header;

	// dummy node that rrepresents the end of the list
	DNode <T>* trailer;
	
	// length of the list
	int length;
public:
	// description: default constructor
	DoublyLinkedList() {
		header = new DNode <T>;
		trailer = new DNode <T>;

		header->data = NULL;
		header->next = trailer;

		trailer->data = NULL;
		trailer->prev = header;

		length = 0;
	}

	// description: destructor
	~DoublyLinkedList() {

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
		// this should be the second item in the list
		// the first item is the dummy header
		if (length > 0) {
			return header->next->data;
		}
		cout << "The list is empty.";
		return NULL;
	}

	// description: gets the last item in the list
	// postcondition: last item in the list
	T last() {
		// this should be the second to last item in the list
		// the last item should be the dummy trailer
		if (length > 0) {
			return trailer->prev->data;
		}
		cout << "The list is empty.";
		return NULL;
	}

	// description: adds the data to the list at the beginning of thelist
	// preconditions: data - data to add to the list
	void addFirst(T data) {
		// create new temp node
		DNode <T>* temp = new DNode <T>;

		// assign the given data
		temp->data = data;

		// the node after this should be the node currently after header
		temp->next = header->next;

		// the temp should be before the current first node
		header->next->prev = temp;

		// the node before temp should be header
		temp->prev = header;

		// insert the node
		header->next = temp;

		// increase size
		length++;

		// if size is now 1, change prev of trailer to current node
		if (length == 1) {
			trailer->prev = temp;
		}
	}

	// description: adds the data to the list at the end of thelist
	// preconditions: data - data to add to the list
	void addLast(T data) {
		// create new temp node
		DNode <T>* temp = new DNode <T>;

		// assign the given data
		temp->data = data;

		// the next node after that should be trailer 
		// since its the end of the list
		temp->next = trailer;

		// increase size
		length++;

		// if size is now 1
		if (length == 1) {
			// header and trailer point inward to this node
			temp->prev = header;

			header->next = temp;
			trailer->prev = temp;
		}
		else { // list isnt empty
			// change the current last node to point to our temp
			temp->prev = trailer->prev;
			trailer->prev->next = temp;

			// insert the node at the end of the list
			trailer->prev = temp;
		}
	}

	// description: removes and returns the first item in the list
	// postcondition: the first item in the list
	T removeFirst() {
		// check if lsit is empty
		if (length > 0) {
			// get the contents of the first node
			T data = header->next->data;

			// replace the first node with the second one
			header->next = header->next->next;

			// change the new first node's prev to header
			header->next->prev = header;

			// decrease size
			length--;

			// if the list is empty/size 1, trailer should point back to the header
			if (length == 0) {
				trailer->prev = header;
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
			T data = trailer->prev->data;

			// remove the last node in the list
			trailer->prev = trailer->prev->prev;

			// change the new last node's next to trailer
			trailer->prev->next = trailer;

			// decrease size
			length--;

			// if the list is empty, header points to trailer
			if (length == 0) {
				header->next = trailer;
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
		if (length > 0) {
			// any datatype to string
			stringstream stream;
			// temp string of each element
			string temp = "";
			// entire tostring 
			string str = "";

			// temp node to look at data
			DNode <T>* current = header->next;

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
};
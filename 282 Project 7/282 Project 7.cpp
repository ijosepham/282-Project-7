// 282 Project 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "CircularlyLinkedList.h"
#include "DoublyLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

void circularlyTester() {
	cout << "Circularly Linked List Tester." << endl;
	CircularlyLinkedList <int> cList;

	cout << "isEmpty: " << cList.isEmpty(); // should return 1

	cout << endl << "addLast Tester:";
	for (int i = 0; i < 5; i++) {
		cList.addLast(i); 
		cout << endl;
		cList.display();
	}

	cout << endl;

	cout << endl << "isEmpty: " << cList.isEmpty(); // should return 0
	cout << endl << "Size: " << cList.size(); // should be 5

	cout << endl << endl << "addFirst Tester:";
	for (int i = 0; i < 5; i++) {
		cList.addFirst(i);
		cout << endl;
		cList.display();
	}

	cout << endl;

	cout << endl << "removeLast Tester:";
	for (int i = 0; i < 5; i++) {
		cout << endl << cList.removeLast() << " - ";
		cList.display();
	}
	cout << endl;

	cout << endl << "removeFirst Tester:";
	for (int i = 0; i < 5; i++) {
		cout << endl << cList.removeFirst() << " - ";
		cList.display();
	}
	cout << endl;
}

void doublyTester() {
	cout << endl << endl << "Doubly Linked List Tester." << endl;
	DoublyLinkedList <int> dList;

	cout << "isEmpty: " << dList.isEmpty(); // should return 1

	cout << endl << "addLast Tester:";
	for (int i = 2; i < 8; i++) {
		dList.addLast(i);
		cout << endl;
		dList.display();
	}

	cout << endl;

	cout << endl << "isEmpty: " << dList.isEmpty(); // should return 0
	cout << endl << "Size: " << dList.size(); // should be 5

	cout << endl << endl << "addFirst Tester:";
	for (int i = 0; i < 5; i++) {
		dList.addFirst(i);
		cout << endl;
		dList.display();
	}

	cout << endl;
	
	cout << endl << "removeLast Tester:";
	for (int i = 0; i < 10; i++) {
		cout << endl << dList.removeLast() << " - ";
		dList.display();
	}

	cout << endl << dList.size();

	cout << endl << "removeFirst Tester:";
	for (int i = 0; i < 5; i++) {
		cout << endl << dList.removeFirst() << " - ";
		dList.display();
	}
	cout << endl;


}

int main()
{
	circularlyTester();
	doublyTester();
	
	return 0;
}

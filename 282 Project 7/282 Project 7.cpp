// 282 Project 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "CircularlyLinkedList.h"
#include "DoublyLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

void circularlyTester() {
	CircularlyLinkedList <int> cList;

	cout << "isEmpty: " << cList.isEmpty(); // should return 1

	cout << endl << "addLast Tester:";
	for (int i = 0; i < 5; i++) {
		cList.addLast(i); 
	}

	cout << endl;
	cList.display(); // 0-4

	cout << endl << "isEmpty: " << cList.isEmpty(); // should return 0
	cout << endl << "Size: " << cList.size(); // should be 5

	cout << endl << "addFirst Tester:";
	for (int i = 0; i < 5; i++) {
		cList.addFirst(i); 
	}

	cout << endl;
	cList.display(); // 4-0, 0-4

	cout << endl << "removeLast Tester:";
	for (int i = 0; i < 5; i++) {
		cout << endl << cList.removeLast();
	}
	cout << endl;
	cList.display(); // 4-0

	cout << endl << "removeFirst Tester:";
	for (int i = 0; i < 5; i++) {
		cout << endl << cList.removeFirst();
	}
	cout << endl;
	cList.display(); // empty
}

void doublyTester() {

}

int main()
{
	circularlyTester();
	doublyTester();
	
	return 0;
}

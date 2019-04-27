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

	for (int i = 0; i < 11; i++) {
		cList.addLast(i); // 0-10
	}

	cList.display();

	for (int i = 0; i < 11; i++) {
		cList.addFirst(i); // 10-0, 0-10
	}

	cList.display();
}

void doublyTester() {

}

int main()
{
	circularlyTester();
	doublyTester();
	
	return 0;
}

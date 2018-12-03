/*
 * File: List.h
 * Author: Ming
 * Source: creating a linked list project in c++, from Paul Programming on Youtube
 * Version 1: Dec 02, 2014
 */

#ifndef LIST_H
#define LIST_H

class List{

	private:

		struct node{
			int data;
			node* next; // node pointer inside each node which points next node in the list
		};
		
		typedef struct node* nodePtr; // prefix of the struct
		
		// combine the section between line 15-20 together

		/*
		   typedef struct node{
			   int data;
			   node* next;
		   }* nodePtr;
		*/

		nodePtr head;
		nodePtr curr;// current pointer
		nodePtr temp;// temporary pointer

	public: // This is where the functions go
		List();
		void AddNode(int addData);
		void DeleteNode(int delData);
		void PrintList();
};

#endif /* LIST_H */
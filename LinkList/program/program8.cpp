/*
-------------------------------- Program 8 --------------------------------------
Write a program which search first occurrence of particular
element from singly linear linked list.
Function should return position at which element is found.
Function Prototype :
int SearchFirstOcc(
struct node *Head, int no
);
______________________________________________________________________________________________________________________________________
*/

#include <iostream>
#include <malloc.h>

//structure declareation
struct node {
	int no;
	// Data element
	struct node *next; // Address of next node
};

//search function
int searchFirstOcc(struct node *head, int no) {
	
		int count = 1;
		struct node *temp =head;
		while(temp != NULL) {
			if(temp->no == no) 
				return count;
			count++;
			temp= temp->next;
		}
		return -1;
}

//create node function
struct node* createNode(struct node* head) {
		//allocate memory
		struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
		struct node* temp = head;
		std::cin >> newNode->no;	//accpet data from user
		newNode->next = NULL;

		if(head == NULL){
			head = newNode;
		}else {
			
			while(temp->next != NULL) 	//traverse upto the last node
				temp=temp->next;
			temp->next = newNode;	
		}
	
		return head;
}//end of function



int main() {
	struct node * head= NULL;
	
	int n ,data;

	std::cout << "Enter number of nodes for the list: " ;
	std::cin >> n;
	
	//first create a list	
	for(int i=0; i<n; i++) {
		std::cout <<"Enter data "<< i+1 << ": ";
		head = createNode(head);
	}

	//display function
	std::cout << "\nEnter data for search: ";
	std::cin >> data;
	
	int pos = searchFirstOcc(head , data);
	if(pos != -1)  
		std::cout << "Element found at location " << pos << " in the list" << std::endl;  	
	else
		std::cout << "Entered lement not found " << std::endl;  	
		
}

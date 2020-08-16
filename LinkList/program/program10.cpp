/*
-------------------------------- Program 10 --------------------------------------
Write a program which search second last occurrence of
particular element from singly linear linked list.
Function should return position at which element is found.
Function Prototype :
int SearchSecLastOcc(
struct node *Head , int no);
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
int searchSecLastOcc(struct node *head, int no) {
	
		int count = 0, prevPos = -1,currentPos = 0;
		struct node *temp =head;
		while(temp != NULL) {
			count++;
			if(temp->no == no) { 
				prevPos = currentPos;		//store previos poistion of the element
				currentPos = count;	//stor current position of the element
			}
			temp= temp->next;
		}
		//if second last occurance found
		if(prevPos > 0)
			return prevPos;
		//when only one element is present
		else if(prevPos == 0) 
				return 0;
		// not found 
		else 
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
	
	//call function for searching
	int pos = searchSecLastOcc(head , data);
	if(pos > 0)  
		std::cout << "Second Last Occurance of Element found at location " << pos << " in the list" << std::endl;  	
	else if(pos == 0)
		std::cout << "Only one element is found!! No any second last occurance of this element" << std::endl;  	
	else
		std::cout << "Entered element not present in th list" << std::endl;
}

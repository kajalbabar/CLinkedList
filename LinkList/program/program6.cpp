/*
-------------------------------- Program 6 --------------------------------------
Write a program which remove node from singly linear
linked list which is at specified position.
Function Prototype :
int DeleteAtPosition(
struct node **Head, int pos
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

//to get lenght of list
int getLength(struct node *head) {
	struct node *temp = head;
	int count = 0;
	while(temp != NULL ) {
		count++;
		temp = temp->next;
	}
	return count;

}

//delete node at specific position
int deleteAtPosition(struct node** head, int pos) {
		
		struct node* temp1 = *head, *temp2 =NULL;
		int count=1;
		
		//get length of list
		int len = getLength(temp1);
		
		//if user entered wrong position the return -1
 		if(pos > len || pos < 1) {
			return -1;
		} 
		//if the list contain only one node 
		if(pos == 1) {
			*head = temp1->next;
			temp1->next =NULL;
			free(temp1);
		}
		else {
			while(count < pos-1) {
				temp1= temp1->next; 	//will point to the previous of position node
				count++;
			}
			
			temp2 = temp1->next; //point to the position node
			temp1->next = temp2->next;	//attach it to the next node
			temp2->next = NULL;		//make position node link NULL and then free
			free(temp2);
		}
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


//display function
void displayList(struct node* head) {
	
	struct node* temp =head;
	
	if(temp == NULL) {
		std::cout << "\t******* List is Empty *******" << std::endl;
	}else {
		//last node condition
		while(temp !=NULL) {
			std::cout <<"|"<<temp->no <<"|"; 
			temp = temp->next;
			if(temp !=NULL) 	
				std::cout << " --> ";	

		}
	}
	std::cout << std::endl;
}

int main() {
	struct node * head= NULL;
	
	int n , data , status, pos;

	std::cout << "Enter number of nodes for the list: " ;
	std::cin >> n;
	
	//first create a list	
	for(int i=0; i<n; i++) {
		std::cout <<"Enter data "<< i+1 << ": ";
		head = createNode(head);
	}

	//display function
	std::cout << "\nOriginal List:" <<std::endl;
	displayList(head);

	//get a position from user	
	std::cout <<"Enter position for deletion of node: ";
	std::cin >> pos;

	//call function for insertion
	status = deleteAtPosition(&head, pos);
	
	//check inserted or not
	if(status == 0) {
		std::cout << "\n\t********* deleted Successfully *******" <<std::endl;
		std::cout << "\nAfter deletion of specific position:" <<std::endl;
		displayList(head);
	}else { 
		std::cout << "\t******** Wrong postion entered ***********" <<std::endl;
	}

	return 0;
}

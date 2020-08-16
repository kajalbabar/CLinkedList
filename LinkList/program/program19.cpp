/*

--------------------Program 19-------------------------
Write a program which copies contents of source singly
linear linked list to destination singly linear linked list which lies
between the particular range'
which is accepted from user.Function Prototype :
int LLCopyRange(struct node **Src, struct node **Dest, int start, int end);
_______________________________________________________________________________________________________________________________________
*/

#include <iostream>
#include <malloc.h>

//structure declareation
struct node {
	int no;
	// Data element
	struct node *next; // Address of next node
};


//calculate length of list
int getLength(struct node* head) {
		struct node* temp= head;
		int count=0;
		while(temp != NULL) { 		
			count++;
			temp =temp->next;
		}
		return count;
} 


//copy function 
int LLCopyRange(struct node** srcHead, struct node** destHead, int start , int end) {
			
		struct node *temp1 = *srcHead;
		struct node *temp2 = NULL;
		int count= 0;
		
	
		//copy n characters
		while(temp1 != NULL) {
			count++;
			if(count>=start && count <= end) {
			//allocate memory to new node
			struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
		
			//std::cout << "**********" <<std::endl;
		
			newNode->no = temp1->no;	//copy data accpeted  from src list
			newNode->next = NULL;
		
			//if head is null then directly insert
			if(temp2 == NULL) {		
				*destHead = newNode;
				temp2 = newNode;
					
			}
			else {
				temp2->next = newNode;	
				temp2 = temp2->next;
			}
		
			}
			temp1 = temp1->next;
		}
		temp2->next = NULL;
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
}

//display function
void displayList(struct node* head) {
	struct node* temp =head;

	if(head == NULL) 
		std::cout << "************* List is Empty ***********\n" <<std::endl;
	else {
	//last node condition
	while(temp !=NULL) {
		std::cout <<"|"<<temp->no <<"|"; 
		temp = temp->next;
		if(temp !=NULL) 	
			std::cout << " --> ";	

	}
	std::cout << std::endl;
	}
}


//main function
int main() {
	struct node *src= NULL, *dest = NULL;
	
	int n;
	std::cout << "Enter number of nodes for the list: " ;
	std::cin >> n;
	
	//first create a list	
	for(int i=0; i<n; i++) {
		std::cout <<"Enter data "<< i+1 << ": ";
		src = createNode(src);
	}
	
	//display function
	std::cout << "************Source List:************" <<std::endl;
	displayList(src);
	
	int start,end;
	std::cout << "Enter starting num to copy from src to dest: ";
	std::cin >> start; 
	
	std::cout << "Enter end num to copy from src to dest: ";
	std::cin >> end; 
		
	std::cout << "before Copy, destination list: " <<std::endl;
	displayList(dest);
	

	//call function for copy
	LLCopyRange(&src, &dest, start,end);


	std::cout << "After Copy, destination list: " <<std::endl;
	displayList(dest);
	return 0;
}

/*

-------------------- Program 21 -------------------------
Write a program which copies contents of source singly
linear linked list whose addition of digits is even number to destination
singly linear linked list.
Function Prototype :
int LLCopyEx(struct node **Src , struct node **Dest
);
__________________________________________________________________________________________________________________-
*/

#include <iostream>
#include <malloc.h>

//structure declareation
struct node {
	int no;
	// Data element
	struct node *next; // Address of next node
};


//copy function 
int LLCopy(struct node** srcHead, struct node** destHead) {
			
		struct node *temp1 = *srcHead;
		struct node *temp2 = NULL;
		int sum=0,mod,num;
		while(temp1 != NULL) {
			
			//calculate addition of digits
			num = temp1->no;	//access num
			sum =0;
			while(num != 0) {
				mod = num%10;
				sum +=mod;
				num /=10;		
			}
			if(sum%2 == 0) {
			//allocate memory to new node
			struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
		
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

	
	std::cout << "before Copy, destination list: " <<std::endl;
	displayList(dest);
	
	//call function for copy
	LLCopy(&src, &dest);


	std::cout << "After Copy, destination list: " <<std::endl;
	displayList(dest);
	return 0;
}

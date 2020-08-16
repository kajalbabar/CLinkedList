/*
-------------------------------- Program 25 --------------------------------------
Write a program which accept source singly linear linked
list from user and copy the contents into destination singly linear
linked in ascending order.
Function Prototype :
int CopyAsc(
struct node **Src , struct node **Dest
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

int getLength(struct node *head) {
	struct node *temp = head;
	int count=0;
	while(temp!=NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}//end Of getLength

//copy in asceding order
int CopyAsc( struct node **src , struct node **dest, int arr[]) {
		//struct node *srcTemp = *src;
		//struct node *destTemp = *dest;
		//struct node *tempInsert =NULL;
		int len = getLength(*src);

		struct node *temp = *dest;
		for(int i=0; i<len; i++) {
			
			struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
			newNode->no = arr[i];	
			newNode->next = NULL;
		
			if(*dest == NULL) {
				*dest =newNode;
				temp =newNode;
			}else {
				temp->next = newNode;
				temp=newNode;	
			}
		}
}	

//display function
void displayList(struct node* head) {
        struct node* temp =head;
	if(head ==NULL) {
		std::cout << "-----------List Is Empty--------------";
	}
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

	//head of src and dest link list
	struct node *srcHead= NULL;
	struct node *destHead = NULL;
	int src, dest ,data;

	std::cout << "Enter number of nodes in the source list: " ;
	std::cin >> src;
	
	//accept source list	
	for(int i=0; i<src; i++) {
		std::cout <<"Enter data "<< i+1 << ": ";
		srcHead = createNode(srcHead);
	}

	
	//display src and dest lists
	std::cout << "\nSource List-----------------" << std::endl;
	displayList(srcHead);
	
	//take all src list into an array
	int len= getLength(srcHead);
	int arr [len],i=0;
	struct node* temp=srcHead;
	
	while(temp != NULL) {
		arr[i++] = temp->no;
		temp=temp->next;
	}
	
	//sort data 
	for(int i=0; i<len ;i++) {
		for(int j=i;j<len;j++) {
			if(arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] =temp;
			} 
		
		}
	}

	//call concate fun
	int status = CopyAsc(&srcHead, &destHead, arr); 
	std::cout << "Array after sorting " <<std::endl;
	displayList(destHead);
	
		
}

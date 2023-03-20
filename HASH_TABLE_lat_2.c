#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	char nama[50];
	int nilai;
	struct Node *next;
	
}*head[26], *temp, *curr;

void insertNode(char nama[], int nilai){
	int index = nama[0] - 'A';
	
	temp = (struct Node *) malloc (sizeof(struct Node));
	strcpy(temp->nama, nama);
	temp->nilai = nilai;
	
	if(head[index] == NULL){
		head[index] = temp;
	}else{
		int counter = 0;
		while(head[index]!=NULL){
			index++;
			index%=26;
			counter++;
			if(counter>=26) return;
		}
		head[index] = temp;
	}
}

void deleteChar(char nama[]){
	for(int i = 0; i < 26; i++){
		if(head[i] != NULL){
			if(strcmp(head[i]->nama,nama) == 0){
				free(head[i]);
				head[i] = NULL;
			}
		}
	}
}

void search(char nim[]){
int index = nama[0] - 'A';
if(head[index] == NULL){
	return;
	{else{
		curr = head[index];
		while(curr){
			if(strcmp(curr->nama, nama)==0){
				printf("Found At Index: %d\n", index);
			}
		}	curr = curr->next;
	}
}

void display(){
	for(int i = 0; i < 26; i++){
		if(head[i]!=NULL){
				printf("[%d] - %s - %d\n", i, head[i]->nama, head[i]->nilai);
		}
	}
}

int main(){
	
	insertNode("Dandy", 20);
	insertNode("Denis", 12);
	insertNode("Zebra", 22);
	insertNode("Zenis", 23); // karena sudah ada zebra sehingga ditaruh ke paling atas jika terjadi collision
	display();
	
}

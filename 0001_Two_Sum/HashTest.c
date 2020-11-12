#include <stdio.h>
#include <stdlib.h>

struct ArchiHash{
	int Active;
	int key;
	int value;
	struct ArchiHash *next;
};

int addEnu(struct ArchiHash *Head, int index, int value){

	struct ArchiHash *newpoint;
	struct ArchiHash *tmp;

	if(!Head->Active){
		printf("Head is NULL\n");
		Head->Active = 1;
		Head->key = index;
		Head->value = value;
		return 0;
	}

	tmp = Head;

	while(tmp != NULL){
		if( tmp->value == value ){
			printf("skip over numer %d\n", value);
			return 2;
		}
		if( tmp->value < value ){
			if( tmp->next->value > value){
				newpoint = malloc(sizeof(struct ArchiHash));
				newpoint->key = index;
				newpoint->value = value;
				newpoint->next = tmp->next;
				tmp->next = newpoint;
				printf("insert new numer in list %d\n", value);
				return 1;
			}else{
				tmp = tmp->next;
			}
		}
	}

	newpoint = malloc(sizeof(struct ArchiHash));
	newpoint->key = index;
	newpoint->value = value;
	newpoint->next = NULL;
	tmp->next = newpoint;
	printf("insert new numer in list %d\n", value);
	return 1;
}

void main(){
	struct ArchiHash *ah;
	struct ArchiHash *tmp;
	struct ArchiHash *tmp2;

	int array2[] = {11,11,11,11};
	int Index = 0;

	
	ah = malloc(sizeof(struct ArchiHash));
	ah->Active = 0;

	for(Index=0;Index<sizeof(array2)/sizeof(int);Index++){
		addEnu(ah, Index, array2[Index]);	
	}

	tmp = ah;

	while(tmp){
		tmp2 = tmp->next;
		while(tmp2){
			if( (tmp->value + tmp2->value)==66 ){
				printf("[%d, %d]\n", tmp->key, tmp2->key);
				return;
			}
			tmp2 = tmp2->next;
		}
		//printf("%d %d\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}

	printf("[0,0]\n");

	return;
}


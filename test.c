
#include <stdio.h>
#include <stdlib.h>


typedef struct info_
{
	int val;
	struct info_ *nxt;
}info;

info *lis;

info *new_el(int a){
	info *ret;
	ret = (info *)malloc(sizeof(info));
	ret->nxt = 0;
	ret-> val = a;
	return ret;
}

void push(int bb){
	info *temp;
	if(!lis)
		lis = new_el(bb);
	else{
		temp = lis;
		lis = new_el(bb);
		lis->nxt = temp;
	}
}

void free_(){
	info *temp;

	while(lis != 0)
	{	
		printf("%d\n", lis->val);
		temp = lis;
		lis = lis->nxt;
		free(temp);
	}
}

int main(){

	for(int i = 0; i < 10; ++i){
		push(i);
	}
	free_();
}
#include <stdio.h>
#include <conio.h>
#define MAX 3

typedef struct Person{
	char strName[30];
	int intAge;
	int intHigh;
	int intWeight;
	
};
 
void TestPointer (Person *p){
	printf("---------------\n");
	printf("Name : %s\n",(*p).strName);
	printf("Age : %d\n",(*p).intAge);
	printf("High : %d\n",(*p).intHigh);
	printf("Weight : %d\n",(*p).intWeight);
}

void TestscanPointer (Person *p){
	printf("Enter Name = ");
	scanf("%s",(*p).strName);
	printf("Enter Age = ");
	scanf("%d",&(*p).intAge);
	printf("Enter High = ");
	scanf("%d",&(*p).intHigh);
	printf("Enter Weight = ");
	scanf("%d",&(*p).intWeight);
	printf("---------------\n");
}

main(){
	Person pCustomer[MAX] ;
	for(int i=0;i<MAX;i++){
		TestscanPointer(&pCustomer[i]);	
	}
	for(int j=0;j<MAX;j++){
		TestPointer(&pCustomer[j]);	
	}
	getch;
}

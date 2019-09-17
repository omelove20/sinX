#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAXSTD 50
#define IDLEN 4
#define NAMELEN 20
#define MAXSJ 5
#define SUBLEN 10


	double getStudent(char id[MAXSTD][IDLEN],char name[MAXSTD][NAMELEN]){
	int n;
	
	printf("Enter number of student : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter id and Name student [id Name] = ");
		scanf("%s %s",&id[i],&name[i]);
		
	}
	return n;
	}

	/*-----------------------------------------------------------------------------*/

	double getSubject(char subject[MAXSJ][SUBLEN]){
	int n;
	
	printf("Enter number of Subject : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter Name Subject%d [calculus] = ",i);
		scanf("%s",&subject[i]);
		
	}
	return n;
	}
	
	/*-----------------------------------------------------------------------------*/	

/*	double	getScore(char a[10],int score[MAXSTD],int nbStd,int nbSub){
		for(int i=0;i<nbStd;i++){
			printf("Enter score %s %s: ",a,id[i]);
			scanf("%d",&score[i]);
		}
	}
	*/
	/*-----------------------------------------------------------------------------*/	
	
	void showstd(int nbStd,char id[MAXSTD][IDLEN],char name[MAXSTD][NAMELEN],char subject[MAXSJ][SUBLEN]){
		printf("%10s%10s%10s%10s\n","Number ID","Name",subject[0],subject[1]);
		for ()
		for(int i=1;i<nbStd;i++){
			printf("%5s\t%5s\t%s\n",id[i],name[i],subject[i]);
		}
	}
	
int main(){
	char id[MAXSTD][IDLEN],name[MAXSTD][NAMELEN];
	char subject[MAXSJ][SUBLEN];
	int score[MAXSTD][MAXSJ];
	char grade[MAXSTD][MAXSJ];
	int nbStd,nbSub;
	nbStd = getStudent(id,name);
	nbSub = getSubject(subject);
	showstd(nbStd,id,name,subject);
//	getScore(subject,score,nbStd,nbSub);
//	grtGr(score,grade,nbStd,nbSub);
//	showGr(............);
}

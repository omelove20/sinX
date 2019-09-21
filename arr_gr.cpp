#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAXSTD 50
#define IDLEN 4
#define NAMELEN 20
#define MAXSJ 5
#define SUBLEN 10


	int getStudent(char id[MAXSTD][IDLEN],char name[MAXSTD][NAMELEN]){
		int n;
		
		printf("Enter number of student : ");
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			printf("Enter id and Name student [id Name] = ");
			scanf("%s %s",id[i],name[i]);
			
		}
		return n;
	}

	/*-----------------------------------------------------------------------------*/

	int getSubject(char subject[MAXSJ][SUBLEN]){
		int n;
		
		printf("Enter number of Subject : ");
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			printf("Enter Name Subject%d [calculus] = ",i);
			scanf("%s",subject[i]);
			
		}
		return n;
	}
	
	/*-----------------------------------------------------------------------------*/	

	void getScore(char sj[MAXSJ][SUBLEN],int sc[MAXSTD][MAXSJ],int nbStd,int nbSub,char name[MAXSTD][NAMELEN]){
		for(int i=0;i<nbStd;i++){
			for(int j=0;j<nbSub;j++){

			printf("Enter score %s %s: ",name[i],sj[j]);
			scanf("%d",&sc[i][j]);
			}
		}
	}
		
	/*-----------------------------------------------------------------------------*/	
	
	char setGr(int score[MAXSTD][MAXSJ],char* grade[MAXSTD][MAXSJ],int nbStd,int nbSub){
		for(int i=0;i<nbStd;i++){
			for(int j=0;j<nbSub;j++){
				if(score[i][j]>=80){
					grade[i][j]="A";
				}else if(score[i][j]>=75){
					grade[i][j]="B+";
				}else if(score[i][j]>=70){
					grade[i][j]="B";
				}else if(score[i][j]>=65){
					grade[i][j]="C+";
				}else if(score[i][j]>=60){
					grade[i][j]="C";
				}else if(score[i][j]>=55){
					grade[i][j]="D+";
				}else if(score[i][j]>=50){
					grade[i][j]="D";
				}else{
					grade[i][j]="F";
				}
			}
		}
	}

	/*-----------------------------------------------------------------------------*/	
	
	void header(char subject[MAXSJ][SUBLEN],int nbSub){
		printf("%10s%10s","ID","Name");
		for (int i=0;i<nbSub;i++){
			printf("%10s",subject[i]);
		}
		printf("\n");
	}
	
	void showstd(int nbStd,char id[MAXSTD][IDLEN],char name[MAXSTD][NAMELEN],char subject[MAXSJ][SUBLEN],int nbSub,char* grade[MAXSTD][MAXSJ]){
		header(subject,nbSub);
		for (int i=0;i<nbStd;i++){
			printf("%10s%10s",id[i],name[i]);
			for (int j=0;j<nbSub;j++){
				printf("%10s",grade[i][j]);
			}
			printf("\n");
			
		}
	}
	
	/*-----------------------------------------------------------------------------*/	
	
int main(){
	char id[MAXSTD][IDLEN],name[MAXSTD][NAMELEN];
	char subject[MAXSJ][SUBLEN];
	int score[MAXSTD][MAXSJ];
	char* grade[MAXSTD][MAXSJ];
	int nbStd,nbSub;
	nbStd = getStudent(id,name);
	nbSub = getSubject(subject);
	getScore(subject,score,nbStd,nbSub,name);
	setGr(score,grade,nbStd,nbSub);
	showstd(nbStd,id,name,subject,nbSub,grade);
}

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAXSTD 50
#define IDLEN 10
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

	int getSubject(char subject[MAXSJ][SUBLEN],float creditsj[MAXSJ]){
		int n;
		
		printf("Enter number of Subject : ");
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			printf("Enter Name Subject %d [Name] = ",i+1);
			scanf("%s",subject[i]);
			printf("Enter credit of Subject : ");
			scanf("%f",&creditsj[i]);
			
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
	
	char setGr(int score[MAXSTD][MAXSJ],char* grade[MAXSTD][MAXSJ],int nbStd,int nbSub,float grnum[MAXSTD][MAXSJ]){
		for(int i=0;i<nbStd;i++){
			for(int j=0;j<nbSub;j++){
				if(score[i][j]>=80){
					grade[i][j]="A";
					grnum[i][j]=4;
				}else if(score[i][j]>=75){
					grade[i][j]="B+";
					grnum[i][j]=3.5;
				}else if(score[i][j]>=70){
					grade[i][j]="B";
					grnum[i][j]=3;
				}else if(score[i][j]>=65){
					grade[i][j]="C+";
					grnum[i][j]=2.5;
				}else if(score[i][j]>=60){
					grade[i][j]="C";
					grnum[i][j]=2;
				}else if(score[i][j]>=55){
					grade[i][j]="D+";
					grnum[i][j]=1.5;
				}else if(score[i][j]>=50){
					grade[i][j]="D";
					grnum[i][j]=1;
				}else{
					grade[i][j]="F";
					grnum[i][j]=0;
				}
			}
		}
	}

	/*-----------------------------------------------------------------------------*/	
	
	void header(char subject[MAXSJ][SUBLEN],int nbSub){
		printf("%20s%10s","ID","Name");
		for (int i=0;i<nbSub;i++){
			printf("%10s",subject[i]);
		}
		printf("\n");
	}
	
	void showstd(int nbStd,char id[MAXSTD][IDLEN],char name[MAXSTD][NAMELEN],char subject[MAXSJ][SUBLEN],int nbSub,char* grade[MAXSTD][MAXSJ]){
		header(subject,nbSub);
		for (int i=0;i<nbStd;i++){
			printf("%10d%10s%10s",i+1,id[i],name[i]);
			for (int j=0;j<nbSub;j++){
				printf("%10s",grade[i][j]);
			}
			printf("\n");
			
		}		
	}
	
	/*-----------------------------------------------------------------------------*/
	
	int countgr(int score[MAXSTD][MAXSJ],int nbStd,int nbSub){
		int count=0;
		for(int i=0; i<nbStd ; i++){
			for(int j=0 ;j<nbSub ; j++){
				if(score[i][j]<50){
					count=count+1;
				}	
			}
		}
		return count;	
	}
		
	/*-----------------------------------------------------------------------------*/
	
	float showcd(	float grnum[MAXSTD][MAXSJ],float creditsj[MAXSJ],int nbStd,int nbSub,float sumgpa[MAXSTD][MAXSJ]){
	float sumgr=0,sumcd=0,gpa;
		for(int i=0;i<nbStd;i++){
			for(int j=0;j<nbSub;j++){
				sumgpa[i][j]=grnum[i][j]*creditsj[j];
				sumgr=sumgr+sumgpa[i][j];
				sumcd=sumcd+creditsj[j];
			}
		}
		
		gpa=sumgr/sumcd;
		return gpa;
	}
	
	/*-----------------------------------------------------------------------------*/
	
	void chakgr(int nbStd,int nbSub,int score[MAXSTD][MAXSJ],char id[MAXSTD][IDLEN]){
		char getid[IDLEN];
		int count=0;
		printf("Enter number id students : ");
		scanf("%s",getid);
		
		for(int i=0;i<nbStd;i++){
			for(int j=0;j<nbSub;j++){
				if(strcmp(getid,id[i])==0){
					if(score[i][j]<50){
						count=count+1;	
					}					
				}
			}
		}
		printf("\nstudents of id %s have grade F = %d",getid,count);
	}
	
	
	
	
	
	
int main(){
	char id[MAXSTD][IDLEN],name[MAXSTD][NAMELEN];
	char subject[MAXSJ][SUBLEN];
	int score[MAXSTD][MAXSJ];
	char* grade[MAXSTD][MAXSJ];
	int count=0;
	int nbStd,nbSub;
	float grnum[MAXSTD][MAXSJ];
	float creditsj[MAXSJ];
	float sumgpa[MAXSTD][MAXSJ];
	
	
	nbStd = getStudent(id,name);
	nbSub = getSubject(subject,creditsj);
	getScore(subject,score,nbStd,nbSub,name);
	setGr(score,grade,nbStd,nbSub,grnum);
	showstd(nbStd,id,name,subject,nbSub,grade);
	count=countgr(score,nbStd,nbSub);
	printf("Students in the room are in F = %d",countgr(score,nbStd,nbSub));
	printf("\n\nGPA of the room : %.2f",showcd(grnum,creditsj,nbStd,nbSub,sumgpa));
	chakgr(nbStd,nbSub,score,id);
}

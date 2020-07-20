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
	
	char setGr(int score[MAXSTD][MAXSJ],char grade[10][MAXSTD][MAXSJ],int nbStd,int nbSub,float grnum[MAXSTD][MAXSJ]){
	char FFF[][10]={"A","B+","B","C+","C","D+","D","F"};
	
		for(int i=0;i<nbStd;i++){
			for(int j=0;j<nbSub;j++){
				if(score[i][j]>=80){
					grnum[i][j]=4;
					strcpy(grade[i][j],FFF[0]);
				}else if(score[i][j]>=75){
					grnum[i][j]=3.5;
					strcpy(grade[i][j],FFF[1]);
				}else if(score[i][j]>=70){
					grnum[i][j]=3;
					strcpy(grade[i][j],FFF[2]);
				}else if(score[i][j]>=65){
					grnum[i][j]=2.5;
					strcpy(grade[i][j],FFF[3]);
				}else if(score[i][j]>=60){
					grnum[i][j]=2;
					strcpy(grade[i][j],FFF[4]);
				}else if(score[i][j]>=55){
					grnum[i][j]=1.5;
					strcpy(grade[i][j],FFF[5]);
				}else if(score[i][j]>=50){
					grnum[i][j]=1;
					strcpy(grade[i][j],FFF[6]);
				}else{
					grnum[i][j]=0;
					strcpy(grade[i][j],FFF[7]);
				}
			}
		}
	}

	/*-----------------------------------------------------------------------------*/	
	
	void header(char subject[MAXSJ][SUBLEN],int nbSub){
		printf("%10s|%10s|%10s|"," ","ID","Name");
		for (int i=0;i<nbSub;i++){
			printf("%10s|",subject[i]);
		}
		printf("\n __________________________________________________________________\n");
	}
	
	void showstd(int nbStd,char id[MAXSTD][IDLEN],char name[MAXSTD][NAMELEN],char subject[MAXSJ][SUBLEN],int nbSub,char grade[5][MAXSTD][MAXSJ]){
		header(subject,nbSub);
		for (int i=0;i<nbStd;i++){
			printf("%10d|%10s|%10s|",i+1,id[i],name[i]);
			for (int j=0;j<nbSub;j++){
				printf("%10s|",grade[i][j]);
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
		printf("\nstudents of id %s have grade F = %d\n",getid,count);
	}
	
	/*-----------------------------------------------------------------------------*/
	
	void gpaper(int nbStd,int nbSub,int score[MAXSTD][MAXSJ],char id[MAXSTD][IDLEN],float creditsj[MAXSJ],float grnum[MAXSTD][MAXSJ]){
		char getid[IDLEN];
		float sumcd=0,sumscore=0;
		float gpa;
		printf("Enter number id students : ");
		scanf("%s",getid);
		
		for(int i=0;i<nbStd;i++){
			for(int j=0;j<nbSub;j++){
				if(strcmp(getid,id[i])==0){
					sumscore=sumscore+(grnum[i][j]*creditsj[j]);
					sumcd=sumcd+creditsj[j];
				}
			}
		}
		gpa=sumscore/sumcd;
		printf("GPA%5s = %5.2f\n",getid,gpa);
		
	}
	
	/*-----------------------------------------------------------------------------*/
	
int main(){
	char id[MAXSTD][IDLEN],name[MAXSTD][NAMELEN];
	char subject[MAXSJ][SUBLEN];
	int score[MAXSTD][MAXSJ];
	char grade[5][MAXSTD][MAXSJ];
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
	printf("\n\nGPA of the room : %.2f\n",showcd(grnum,creditsj,nbStd,nbSub,sumgpa));
	chakgr(nbStd,nbSub,score,id);
	gpaper(nbStd,nbSub,score,id,creditsj,grnum);
}
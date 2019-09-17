#include<stdio.h>
#define MAXSTD 50
#define IDLEN 4
#define NAMELEN 20


int getStudent(char id[MAXSTD][IDLEN],char name[MAXSTD][NAMELEN]){
	int n;
	
	printf("Enter number of student : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter id and Name student [id Name] = ");
		scanf("%s %s",&id[i],&name[i]);
		
	}
	return n;
}


int	getScore(char a[10],int score[MAXSTD],int nbStd,char id[MAXSTD][IDLEN]){
	for(int i=0;i<nbStd;i++){
		printf("Enter score %s %s: ",a,id[i]);
		scanf("%d",&score[i]);
	}
}

char sumgrade(int score){
	char a[MAXSTD]={'A','B','C','D','F'};
	if(score>=80){
		return a[0];
	}else if ( score>=70){
		return a[1];
	}else if (score>=60){
		return a[2];
	}else if (score>=50){
		return a[3];
	}else{
		return a[4];
	}
		
	
}


int	setGr(int score[MAXSTD],char grade[MAXSTD][MAXSTD],int nbStd){
		for(int i=0;i<nbStd;i++){
			grade[i][0]=sumgrade(score[i]);
		}
}

void showstd(int nbStd,char id[MAXSTD][IDLEN],char name[MAXSTD][NAMELEN],char calGr[MAXSTD][MAXSTD],char engGr[MAXSTD][MAXSTD]){
	for(int i=0;i<nbStd;i++){
		printf("%5s\t%5s\t%s\t%s\n",id[i],name[i],calGr[i],engGr[i]);
	}
}


int main(){
	char id[MAXSTD][IDLEN],name[MAXSTD][NAMELEN];
	int cal[MAXSTD],eng[MAXSTD];
	char calGr[MAXSTD][MAXSTD],engGr[MAXSTD][MAXSTD];
	int nbStd;
	nbStd=getStudent(id,name);
	getScore("calculus",cal,nbStd,id);
	getScore("English",eng,nbStd,id);
	setGr(cal,calGr,nbStd);
	setGr(eng,engGr,nbStd);
	showstd(nbStd,id,name,calGr,engGr);


}

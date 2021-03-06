#include<stdio.h>
#include<math.h>

#define PI 22.0/7
#define LOOP 10
int Key;

double Err(double x,double y){
  	double error;
  		error= (x-y)/y*100;
	return error;
}	

double fac(double n){
   double fact = 1;
   for(int i=1; i<=n; i++)
      fact = fact * i;
   return fact ;
}

double pow(double base,int exponent){
	double pow=1;
    for(int i=1;i<=exponent;i++){
       pow = pow * base;    }
   return pow;	
}

double Deg2Red(double x){
	double sum;
  	sum=(x*PI)/180;
return sum;
}

double mysin(double x){
	double sum=0;
	for(int i=1;i<=LOOP;i++){
		if(i%2==0){
			sum = sum - (pow(x,2*i-1)/fac(2*i-1));
			Err(sum,sin(Key));
		}else{
			sum = sum + (pow(x,2*i-1)/fac(2*i-1));
			Err(sum,sin(Key));
		}
	}
	return sum;	
}

double Showsin(){
	double Mysin,Realsin,Error,Red;
	char str1 [10] = "Mysin",str2 [10] = "sin",str3 [10] = "Error",str4 [10] = "Degree";
	
	printf("Enter Number Degree = ");
	scanf("%d",&Key);
	printf("%15s%15s%15s%15s\n",str4,str1,str2,str3);
	for(int i=0 ; i<=Key ;i=i+10){
		Red=Deg2Red(i);
		Mysin =mysin(Red);
		Realsin = sin(Red);
		Error = Err(Mysin,Realsin);
		
		printf("%15d",i);
		printf("%15.3f\t",Mysin);
		printf("%15.3f\t",Realsin);
		printf("%12.3f\n",Error);
	}
}

main(){
	Showsin();
}

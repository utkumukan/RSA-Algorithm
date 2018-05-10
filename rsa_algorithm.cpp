#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void finding_D(long a,long b,long *x,long *y,int *d);
int gcd(int num1,int num2);
int crypte(long m,long n,long e);


int main(){
    
    long x,y;
    int prime[10]={101,103,107,109,113,127,131,137,139,149};
    int prime_e[10]={5,7,11,13,17,19,23,29,31,37};
    int P,Q,E,D,N,phi,m1,m2;
    int Message;
    srand(time(NULL));
    P=prime[rand()%10];
    Q=prime[rand()%10];
    if(P==Q){
             Q=prime[rand()%10];
             }
             printf("P=%d",P);
             printf("\tQ=%d",Q);
             N=P*Q;
             phi=(P-1)*(Q-1);
             printf("\n\nN=%d",N);
             printf(" \tphi(%d)=%d",N,phi);
             Message=rand()%101;
             
             E=prime_e[rand()%10];
             while (gcd(phi,E)!=1){
                   E=prime_e[rand()%10];
                   }
                   
                   printf("\n\nE=%d",E);
                   
                   finding_D(phi,E,&x,&y,&D);
                   D=y;
                   if(D>phi){
                             D=D%phi;
                             }
                             if(D<0){
                                     D=D+phi;
                                     }
                                     
                                     printf("\n\nD=%d",D);
                                     printf("\n\nMessage=%d",Message);
                                     
                                     
                                     m1=crypte(Message,N,E);
                                     printf("\n\nEncryped Message: %d",m1);
                                     printf(" \tPUBLIC KEY=(%d,%d)",E,N);
                                     
                                     m2=crypte(m1,N,D);
                                     printf("\n\nOriginal Message: %d",m2);
                                     printf(" \tPRIVATE KEY=(%d,%d)",D,N);
                                     
                                     getchar();
                                     return 0;
                                     }
             

int gcd(int num1,int num2){
    if(num1<num2){
                  int swap=num1;
                  num1=num2;
                  num2=swap;
                  }
                  while(num2!=0){
                                 int remainder=num1%num2;
                                 num1=num2;
                                 num2=remainder;
                                 }
                                 return num1;
                                 }
                                 
                                 
int crypte(long m,long N,long E){
    int result=1;
    while(E>0){
               if(E%2==1){
                          result=(result*m)%N;
                          }
                          E=E/2;
                          m=(m*m)%N;
                          }
                          return result;
                          }
                          
                          
void finding_D(long a,long b,long*x,long *y,int *D){
     long Q,r,x1,x2,y1,y2;
     if(b==0){
              *D=a,*x=1,*y=0;
              return;
              }
              x2=1,x1=0,y2=0,y1=1;
              while(b>0){
                         Q=a/b, r=a-Q*b;
                         *x=x2-Q*x1, *y=y2-Q*y1;
                         a=b,b=r;
                         x2=x1,x1=*x,y2=y1,y1=*y;
                         }
                         *D=a,*x=x2,*y=y2;
                         }

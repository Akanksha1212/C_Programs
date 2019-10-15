 #include<stdio.h>
 #include<math.h>
 int main(){
 long long int n,x,y,N=0,i,baseTen=0,k=0;
 int j;
 scanf("%lld %lld %lld" ,&n,&x,&y);
 for(i=0; n>0; i++){
     baseTen += (n%10)*pow(x,i);
     n=n/10;
 }
 for(j=0;;j++){
 if((baseTen)/(long long int)(pow(y,j))==0)
     break;
 }
 for(k=j;k>=0;k--){
 N = N + (baseTen)/(long long int)pow(y,k)*pow(10,k);
 baseTen = (baseTen % (long long int)pow(y,k));
 }
 printf("%lld",N);
 return 0;
 }                                                                           

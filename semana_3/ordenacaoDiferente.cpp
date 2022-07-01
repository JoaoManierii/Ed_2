#include<bits/stdc++.h>

 using namespace std;

 struct factor{
    int numero_fatores;
    int serial;
 };

 const int mx=2000000+1;

 bool status[mx];///
 factor dp[mx];

 void sieve()
 {
     int i, j;
     dp[1].numero_fatores=0;
     dp[1].serial=1;
     for( i = 2; i <mx; i += 1 ) 
     {
		 if( status[i]==0)
		 {
		     dp[i].serial=i;
		     dp[i].numero_fatores=1;
	 		 for( j = 2*i; j <mx; j += (i) )
			 {
				 status[j]=1;
				 dp[j].numero_fatores=dp[j/i].numero_fatores+1;
				 dp[j].serial=j;
	 		 }
		 }
	 }
 }

 bool comp( factor a, factor b)
 {
    if(a.numero_fatores==b.numero_fatores) return (a.serial<b.serial);
    else return (a.numero_fatores<b.numero_fatores);
 }

 int main()
 {
      sieve();
      sort(dp,dp+mx,comp);
      int n;
      int cas=1;
      while(scanf("%d",&n)&&n!=0)
      {
          printf("Caso %d: %d\n",cas,dp[n].serial);
          cas++;
      }
      return 0;
 }

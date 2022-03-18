#include<stdio.h>
//计算小于给定数字除1外的素数 
int main(void)
{
	int a,i,j;
	
	scanf("%d",&a);
	for(i = 2; i <= a; i++){
		for(j = 2; j <= i; j++){
			if(i%j) continue;
			else break;//返回最小约数 
		}
		if(j == i) printf("%d ",i);//判断是否为素数 
		else continue;
	} 

	return 0;
}

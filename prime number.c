#include<stdio.h>
//����С�ڸ������ֳ�1������� 
int main(void)
{
	int a,i,j;
	
	scanf("%d",&a);
	for(i = 2; i <= a; i++){
		for(j = 2; j <= i; j++){
			if(i%j) continue;
			else break;//������СԼ�� 
		}
		if(j == i) printf("%d ",i);//�ж��Ƿ�Ϊ���� 
		else continue;
	} 

	return 0;
}

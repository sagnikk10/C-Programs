#include <stdio.h>


struct emp{
	int id;
	char name[20];
	int age;
	float salary;
	float gro;
	float da;
	float hra;
	
	
};struct emp e1,e2;

int main()
{
	printf("ID :");
	scanf("%d",&e1.id);
	printf("ID :");
	scanf("%d",&e2.id);
	printf("NAME :");
	scanf("%s",e1.name);
	printf("NAME :");
	scanf("%s",e2.name);
	printf("AGE :");
	scanf("%d",&e1.age);
	printf("AGE :");
	scanf("%d",&e2.age);
	printf("SALARY :");
	scanf("%f",&e1.salary);
	printf("SALARY :");
	scanf("%f",&e2.salary);
	e1.da=e1.salary*0.8;
	e2.da=e2.salary*0.8;
	e1.hra=e1.salary*0.1;
	e2.hra=e2.salary*0.1;
	e1.gro=(e1.salary+e1.da+e1.hra);
	e2.gro=(e2.salary+e2.da+e2.hra);
	printf("DISPLAYING INFORMATION :");
	printf("\nID OF FIRST :%d",e1.id);
	printf("\nID OF SECOND :%d",e2.id);
	printf("\nNAME OF FIRST :%s",e1.name);
	printf("\nNAME OF SECOND :%s",e2.name);
	printf("\nAGE OF FIRST:%d",e1.age);
	printf("\nAGE OF SECOND :%d",e2.age);
	printf("\nGROSS SALARY:%f",e1.gro);
	printf("\nGROSS SALARY:%f",e2.gro);

}

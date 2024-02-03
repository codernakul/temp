#include <stdio.h>
typedef struct
{
	char roll[10];
	int marks;
}stud;

int main()
{
	int i=0;
	stud data[500], temp;
	FILE *fpr, *fpi;
	fpr=fopen("w.txt", "r");
	while(feof(fpr)==0)
	{
		fscanf(fpr, "%s %d", data[i].roll, &data[i].marks);
		i++;
	}
	fclose(fpr);
	fpr=fopen("x.txt", "r");
	while(feof(fpr)==0)
	{
		fscanf(fpr, "%s %d", data[i].roll, &data[i].marks);
		i++;
	}
	fclose(fpr);
	fpr=fopen("y.txt", "r");
	while(feof(fpr)==0)
	{
		fscanf(fpr, "%s %d", data[i].roll, &data[i].marks);
		i++;
	}
	fclose(fpr);
	fpr=fopen("z.txt", "r");
	while(feof(fpr)==0)
	{
		fscanf(fpr, "%s %d", data[i].roll, &data[i].marks);
		i++;
	}
	fclose(fpr);
	fpr=fopen("n.txt", "r");
	while(feof(fpr)==0)
	{
		fscanf(fpr, "%s %d", data[i].roll, &data[i].marks);
		i++;
	}
	fclose(fpr);
	
	int size=i;
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1-i;j++)
		{
			if(data[j].marks<data[j+1].marks)
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
	}
	int marks=data[0].marks, rank=1, c=0;
	fpi=fopen("rank.txt", "w");
	for(int i=0;i<size;i++)
	{
		if(data[i].marks==marks)
		{
			fprintf(fpi, "%d %s %d\n", rank, data[i].roll, data[i].marks);
			++c;
		}
		else
		{
			rank=rank+c;
			c=1;
			marks=data[i].marks;
			fprintf(fpi, "%d %s %d\n", rank, data[i].roll, data[i].marks);
		}
	}
	fclose(fpi);
	return 0;
}
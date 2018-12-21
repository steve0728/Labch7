#include<stdio.h>
#include<stdlib.h>

typedef struct _student
{
	char name[5];
	int chinese;
	int english;
	int math;
	int sum;
	float avg;
}student;

int main(void)
{
	student data[5];
	FILE *stream1;
	FILE *stream2;
	int i, j ,k;
	j = fopen_s(&stream1,"D://gradedata.txt", "r");
	k = fopen_s(&stream2, "D://gradeoutput.txt", "w");
	/*stream1 = fopen_s("C://Users\User\Desktop\gradedata.txt","gradedata.txt", "r");
	stream2 = fopen_s("C://Users\User\Desktop\gradeoutput.txt","gradeoutput.txt", "w");*/

	if (stream1 == NULL || stream2 == NULL)
	{
		printf("unable to open the file\n");
	}
	else
	{
		fprintf(stream2, "Name\tChinese\tEnglish\tMath\tSum\tAvg\n");
		for (i = 0; i < 5; i++)
		{
			fscanf_s(stream1, "%s", &data[i].name, 6);
			fscanf_s(stream1, "%d", &data[i].chinese);
			fscanf_s(stream1, "%d", &data[i].english);
			fscanf_s(stream1, "%d", &data[i].math);
			
			data[i].sum = data[i].chinese + data[i].english + data[i].math;
			data[i].avg = data[i].sum / 3.0;
			fprintf(stream2, "%s\t%d\t%d\t%d\t%d\t%.2f\n", 
				data[i].name, data[i].chinese, data[i].english, 
				data[i].math, data[i].sum, data[i].avg);
		}
		fclose(stream1);
		fclose(stream2);
	}
	system("pause");
	return 0;
}
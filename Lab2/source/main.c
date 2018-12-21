#include<stdio.h>
#include<stdlib.h>

struct clientData
{
	int acctNum;
	char lastName[15];
	char firstName[10];
	double balance;
};
int main(void)
{
	FILE *pRead, *pWrite;
	FILE *cfPtr;
	int cnt = 0,i,j;
	struct clientData client = { 0,"","",0.0 };

	i = fopen_s(&pRead, "D://credit.txt", "r");
	if (NULL == pRead)
	{
		return 0;
	}
	j = fopen_s(&pWrite, "D://credit_bin.txt", "wb");
	if (NULL == pWrite)
	{
		fclose(pRead);
		return 0;
	}
	while (!feof(pRead))
	{
		fscanf_s(pRead, "%d", &client.acctNum);
		fscanf_s(pRead, "%s", client.lastName, 16);
		fscanf_s(pRead, "%s", client.firstName, 11);
		fscanf_s(pRead, "%lf", &client.balance);
		fwrite(&client, sizeof(struct clientData), 1, pWrite);
		printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
	}
	fclose(pRead);
	fclose(pWrite);
	printf("�wŪ����r�ɪ�ACSII��ơA����s���G�i�����ɮ�\n\n");
	system("pause");
	printf("\nŪ���G�i�����ɮסA�î榡�ƿ�X�p�U:\n");
	if ((cfPtr = fopen_s(&pWrite, "D://credit_bin.txt", "rb")) == NULL)
	{
		printf("File could not be open.\n");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s\n","Acct", "Last Name", "First Name", "Balance");

		cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		while (cnt > 0)
		{
			printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName, client.firstName, client.balance);
			cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
		}
		fclose(cfPtr);
	}
	system("pause");
	return 0;
	
}
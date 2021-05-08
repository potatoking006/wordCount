#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int Char(FILE* fp);

int Word(FILE* fp);

int main(int argc, char* argv[])
{
	//argv[1]控制参数          argv[2]文件地址

	printf("\n\n");//先换行便于观察


		if (argc <= 2)
		{
			printf("传入参数个数不够\n");
			return 0;
		}

		FILE *fp;
		if ((fopen_s(&fp, argv[2], "r") != 0))
		{
			printf("输入的文件地址不正确\n");
				return 0;
		};

			if (strcmp(argv[1], "-c") == 0)
			{
				printf("包含的字符数：%d\n", Char(fp));
			}
			else  if (strcmp(argv[1], "-w") == 0)
			{

				printf("包含的单词数：%d\n", Word(fp));
			}
			
			else
			{
				printf("程序执行出现错误\n");
			}
			fclose(fp);
	

		
	
	return 0;
}





//统计字符数
int Char(FILE* fp)
{
	fseek(fp, 0, SEEK_END);

	int sum = ftell(fp);


	return sum;
}


//统计单词数
int Word(FILE* fp) {
	char ch;

	int sum = 0;
	bool flag = true;

	while ((ch = fgetc(fp)) != EOF)
	{
		if (flag == true && (ch != ','&&ch != ' '))
		{
			sum++;
			flag = false;
		}
		else if (ch == ',' || ch == ' ')
		{
			flag = true;
		}

	}



	return sum;
}
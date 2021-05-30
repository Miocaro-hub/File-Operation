#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<errno.h>
#include<string.h>

//6.文件的打开和关闭
//文件在读写之前应该先打开文件,在使用结束后应该关闭文件
//在编写程序的时候,在打开文件的同时,都会返回一个FILE*的指针变量指向该文件,也相当于建立了指针和文件的关系

//ANSIC规定使用fopen函数来打开文件,fclose来关闭文件
//FILE* fopen(const char* filename , const char* mode);
//int fclose (FILE* stream);

int main()
{
	//打开文件
	//有绝对路径和相对路径的写法
	//..表示上一级路径
	//.表示当前路径
	//fopen("../test.txt","r");
	//fopen("test.txt","r");
	//fopen(C:\Users\15991\Desktop\文件操作2.c);  把全部的路径写出来就是绝对路径
	//vs右下角有例子
	FILE* pf = fopen("test.txt", "r"); //只读,会打开一个已经存在的文本文件
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));//打印错误原因
		return 0;
	}
	//打开成功
	//读文件
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}


//7.文件的顺序读写

//字符输出函数
int main()
{
	FILE* pfWrite = fopen("test.txt", "w");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//写文件
	fputc('b', pfWrite);
	fputc('i', pfWrite);
	fputc('t', pfWrite);

	//关闭文件
	fclose(pfWrite);
	pfWrite = NULL;
	return 0;
}

//字符输入函数
int main()
{
	FILE* pfRead = fopen("test.txt", "r");
	if (pfRead == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//读文件
	//printf("%c", fgetc(pfRead));
	//printf("%c", fgetc(pfRead));
	//printf("%c", fgetc(pfRead));
	int ch = fgetc(pfRead);
	printf("%c", ch);
	ch = fgetc(pfRead);
	printf("%c", ch);
	ch = fgetc(pfRead);
	printf("%c", ch);
	//关闭文件
	fclose(pfRead);
	pfRead = NULL;
	return 0;
}

//键盘和屏幕都是外部设备
//一个程序默认打开两个流的设备
//键盘 - 标准输入设备 - stdin
//屏幕 - 标准输出设备 - stdout
int main()
{
	int ch = fgetc(stdin);
	fput(ch, stdout);
	return 0;
}


//文本行输入函数
int main()
{
	char buf[1024] = { 0 };
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	//读文件
	fgets(buf, 1024, pf);  //文本行输入函数(读取一行的数据)
	printf("%s", buf);

	//关闭文件
	fclose(pf);
	pf == NULL;
	return 0;
}


//文本行输出函数
int main()
{
	char buf[1024] = { 0 };
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		return 0;
	}
	//写文件
	fputs("hello\n", pf);  //文本行输出函数
	fputs("world\n", pf);

	//关闭文件
	fclose(pf);
	pf == NULL;
	return 0;
}


int main()
{
	//从键盘读出一行文本信息
	char buf[1024] = { 0 };
	fgets(buf, 1024, stdin);  //从标准输入流读取
	fputs(buf, stdout);  //输出到标准输出流
	//从键盘读,写入到屏幕

	//gets(buf);
	//puts(buf);
	return 0;
}


//格式化输出函数
struct S
{
	int n;
	float score;
	char arr[10];
};
int main()
{
	struct S s = { 100,3.14f,"bit" };
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		return 0;
	}
	//格式化的形式写文件
	fprintf(pf, "%d %f %s", s.n, s.core, s.arr);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}


//格式化输入函数
struct S
{
	int n;
	float score;
	char arr[10];
};
int main()
{
	struct S s = { 0 };
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	//格式化的形式读文件
	fscanf(pf, "%d %f %s", &(s.n), &(s.core), s.arr);
	printf("%d %f %s\n", s.n, s.score.s.arr);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}

//这种形式也是可以的
int mian()
{
	struct S s = { 0 };
	fscanf(stdin, "%d %f %s", &(s.n), &(s.core), s.arr);
	fprintf(stdout, "%d %f %s", s.n, s.core, s.arr);
	//从键盘读取,再写入到屏幕
	return 0;
}


//对比一组函数:
// scanf /fscanf /sscanf
// printf/fpritnf/sprintf

//scanf/printf 是针对标准输入流/标准输出流的格式化输出/输入语句
//fscanf/fprintf 是针对所有输入流/所有输出流的格式化输出/输入语句


//sscanf/sprintf sscanf是从字符串中读取格式化的数据 , sprintf是把格式化的数输出(存储到)字符串
struct S
{
	int n;
	float score;
	char arr[10];
};
int main()
{
	struct S s = { 100,3.14,"abcdef" };
	struct S tmp = { 0 };
	char buf[1024] = { 0 };

	//把格式化的数据转换成字符串存储到buf
	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);

	//从buf中读取格式化的数据到tmp中
	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
	printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);
	return 0;
}

//二进制输出fwrite
struct S
{
	char name[20];
	int age;
	double score;
};
int main()
{
	struct S s = { "张三",20,55.6 };
	FILE* pf = fopen("test.txt", "wb");
	return 0;
	if (pf == NULL)
	{
		return 0;
	}
	//二进制的形式写文件
	fwrite(&s, sizeof(struct S), 1, pf);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}


//二进制输入fread
struct S
{
	char name[20];
	int age;
	double score;
};
int main()
{
	struct S tmp = { 0 };
	FILE* pf = fopen("test.txt", "rb");
	return 0;
	if (pf == NULL)
	{
		return 0;
	}
	//二进制的形式读文件
	fread(&tmp, sizeof(struct S), 1, pf);
	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}


//8.文件的随机读写

//fseek - 根据文件指针的位置和偏移量来定位文件指针
//int fseek(FILE* stream , long int offest , int origin)

int main()
{
	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}

	//1.定位文件指针
	fseek(pf, 2, SEEK_CUR);  //SEEK_CUR为指针的当前位置,还有SEEK_END以及SEEK_SET

	//2.读取文件
	int ch = fgetc(pf);
	printf("%c\n", ch);

	//3.关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}


//ftell - 返回指针相对于起始位置的偏移量
//long int ftell(FILE* stream);
int main()
{
	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}

	//1.定位文件指针
	fseek(pf, -2, SEEK_END);
	int pos = ftell(pf);

	//2.读取文件
	int ch = fgetc(pf);
	printf("%c\n", ch);

	//3.关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}


//rewind - 让文件指针的位置回到文件的起始位置
//void rewind(FILE* stream);
int main()
{
	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
    
	int ch = fgetc(pf);  //读取完一个字符,此时的指针指向了下一个字符
	printf("%c\n", ch);

	rewind(pf);
	printf("%c\n", ch);

	fclose(pf);
	pf = NULL;
	return 0;
}


//9.文件结束的判定
//在文件读取过程中,不能用feof函数的返回值直接用来判断文件的是否结束
//而是应用于当文件读取结束的时候,判断是读取失败结束,还是遇到文件尾结束(我们已经知道文件结束了,判断文件是如何结束的,而是不是用来判断文件是否结束)

int main()
{
	//feof();  //EOF - end of file - 文件结束的标志
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	int ch = fgetc(pf);
	printf("%d\n", ch);

	fclose(pf);
	pf = NULL;
	return 0;
}

//还有一种报错函数
/* perror example */
int main()
{
	FILE * pFile;
	pFile = fopen("unexist.ent", "rb");
	if (pFile == NULL)
		perror("The following error occurred");
	else
		fclose(pFile);
	return 0;
}
//实际的打印结果为The following error occurred: No such file or directory


//例子:
int main()
{
	int c;  //注意:int , 非char, 要求处理EOF
	FILE* fp = fopen("test.txt", "r");
	if (!fp)
	{
		perror("File open failed");
		return EXIT_FAILURE;
	}

	//fgetc当读取失败的时候或者遇到文件结束的时候,都会返回EOF
	while ((c = fgetc(fp)) != EOF)  //标准C I/O读取文件循环
	{
		putchar(c);
	}
	printf("\n");

	//判断是什么原因结束的
	if (ferror(fp))
	{
		puts("I/O error when reading\n");
	}
	else if(feof(fp))
	{
		puts("End of file reached successfully\n");
	}

	fclose(fp);
	fp = NULL;
	return 0;
}

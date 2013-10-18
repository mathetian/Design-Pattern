#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define length 3
#define SX 16
#define SXO 17

typedef unsigned long long int GF2n[length];
typedef unsigned long long u64_int;

typedef struct{
	GF2n*f;
	int num;
}FUNCTION;

int getFlagPos(const char*str,char flag)
{
	int len=strlen(str);
	for(int i=0;i<len;i++) 
		if(str[i]==flag) 
			return i;
	return -1;
}

char *trimwhitespace(char *str)
{
  char *end;
  while(isspace(*str)) str++;
  if(*str == 0) 
    return str;
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;
  *(end+1) = 0;
  return str;
}

char** str_split(char* a_str,int &count)
{
    char** result    = 0;
    char* tmp        = a_str;
    char* last_comma = 0;

    while (*tmp)
    {
        if (',' == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);

    count++;

    result = (char**)malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, ",");

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, ",");
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    count--;
    return result;
}

u64_int convertHexToDecLen8(const char*str)
{
	int len=strlen(str);
	u64_int a1=0,a2=0;
	if(len<=4) 
		a1=strtol(str,NULL,16);
	else
	{
		char tmp1[1000];memset(tmp1,0,1000);
		strncpy(tmp1,str,len-4);
		a2=strtol(tmp1,NULL,16);
		a1=strtol(str+len-4,NULL,16);
	}		
	u64_int tmp2=1;tmp2<<=16;
	a1=a2*tmp2+a1;
	return a1;
}

u64_int convertHexToDecLen16(const char*str)
{
	int len=strlen(str);
	u64_int a1=0,a2=0;
	if(len<=8) 
		a1=atoll(str);
	else
	{
		char tmp1[1000];memset(tmp1,0,1000);
		strncpy(tmp1,str,len-8);
		a2=convertHexToDecLen8(tmp1);
		a1=convertHexToDecLen8(str+len-8);
	}		
	u64_int tmp2=1;tmp2<<=32;
	a1=a2*tmp2+a1;
	return a1;
}

void getFromStrConvertHexToDec(const char*str,GF2n&value)
{
	memset(value,0,sizeof(value));
	int len=strlen(str);char strTmp[SXO];
	if(len<=SX)
	{
		memset(strTmp,0,SXO);
		strncpy(strTmp,str,len);
		value[0]=convertHexToDecLen16(strTmp);
	}
	else if(len<=SX*2)
	{
		memset(strTmp,0,SXO);
		strncpy(strTmp,str,len-SX);
		value[1]=convertHexToDecLen16(strTmp);
		memset(strTmp,0,SXO);
		strncpy(strTmp,str+len-SX,SX);
		value[0]=convertHexToDecLen16(strTmp);
	}
	else
	{
		memset(strTmp,0,SXO);
		strncpy(strTmp,str,len-SX*2);
		value[2]=convertHexToDecLen16(strTmp);
		memset(strTmp,0,SXO);
		strncpy(strTmp,str+len-SX*2,SX);
		value[1]=convertHexToDecLen16(strTmp);
		memset(strTmp,0,SXO);
		strncpy(strTmp,str+len-SX,SX);
		value[0]=convertHexToDecLen16(strTmp);
	}
}

void getFromStr(const char*str,GF2n&value)
{
	memset(value,0,sizeof(value));
	int len=strlen(str);char strTmp[SXO];
	value[0]=atoll(str);
}

void GFread(FILE *file,GF2n&m, FUNCTION&ff, GF2n&a,GF2n&b,GF2n&Px,GF2n&Py,GF2n&n,GF2n&Qx,GF2n&Qy)
{
	if(!file)
	{
		printf("error file status\n");
		return;
	}
	int i=0;
	char*input=new char[1000];
	char*left=new char[1000];
	char*right=new char[1000];char*tmp=new char[1000];
	size_t len = 1000;
	while(fgets(input,1000,file))
	{
		input=trimwhitespace(input);
		int pos=getFlagPos(input,'=');
		memset(left,0,1000);
		memset(right,0,1000);
		strncpy(left,input,pos);
		strncpy(right,input+pos+1,strlen(input)-pos-1);
		left=trimwhitespace(left);
		right=trimwhitespace(right);
		if(!strcmp(left,"m"))
			getFromStr(right,m);		
		else if(!strcmp(left,"f"))
		{
			memset(tmp,0,1000);
			strncpy(tmp,right+1,strlen(right)-2);
			int len=0;
			char**result=str_split(tmp,len);
			ff.f=(GF2n*)malloc(sizeof(GF2n)*len);ff.num=len;
			for(int i=0;i<len;i++)
				getFromStr(trimwhitespace(result[i]),ff.f[i]);
		}
		else if(!strcmp(left,"a"))
			getFromStrConvertHexToDec(right,a);
		else if(!strcmp(left,"b"))
			getFromStrConvertHexToDec(right,b);
		else if(!strcmp(left,"P_x"))
			getFromStrConvertHexToDec(right,Px);
		else if(!strcmp(left,"P_y"))
			getFromStrConvertHexToDec(right,Py);
		else if(!strcmp(left,"n"))
			getFromStrConvertHexToDec(right,n);
		else if(!strcmp(left,"Q_x"))
			getFromStrConvertHexToDec(right,Qx);
		else if(!strcmp(left,"Q_y"))
			getFromStrConvertHexToDec(right,Qy);
	}
}

void print(GF2n value)
{
	printf("%llu,%llu,%llu\n",value[2],value[1],value[0]);
}

void printFunction(FUNCTION ff)
{
	printf("Function:\n");
	for(int i=0;i<ff.num;i++)
	{
		printf("\t");
		print(ff.f[i]);
	}
}

void printValue(GF2n value,const char*str)
{
	printf("%s\n\t",str);
	print(value);
}

int main()
{
	FILE*file=fopen("input.txt","r");
	if(!file)
	{
		printf("can't open file\n");
		return 1;
	}
	GF2n m, a, b, Px, Py, n, Qx, Qy;
	FUNCTION ff;
	GFread(file,m,ff,a,b,Px,Py,n,Qx,Qy);
	printValue(m,"m");printValue(a,"a");
	printValue(b,"b");printValue(Px,"Px");printValue(Py,"Py");
	printValue(n,"n");printValue(Qx,"Qx");printValue(Qy,"Qy");

	printFunction(ff);
	return 0;
}
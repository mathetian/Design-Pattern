#include <stdio.h>

typedef unsigned long long u64_int;

u64_int o=1;

void insert(u64_int a,u64_int &b,u64_int &c)
{
	u64_int d=(o<<32)-1;
	b=a>>32;c=a&d;d=o<<31;
	unsigned int i=32;
	while(i!=0)
	{	
		i=i-1;
		if((b&d)==(o<<i))
		{
			u64_int r=o<<(2*i+1);
			b|=r;
		}
		b=b&(~d);

		if((c&d)==(o<<i))
		{
			u64_int r=o<<(2*i+1);
			c|=r;
		}
		c=c&(~d);

		d>>=1;
	}
}

int main()
{
	u64_int b=0,c=0;
	insert(171798724608,b,c);
	printf("%llu,%llu\n",b,c);
	return 0;
}

//some test sample
//10: 1010->10001000->0,136
//15: 1111->10101010->0,170
//171798724608(2^15+2^35+2^37): 10100000000000000000001000000000000000->
//->1000100000000000000000000000000000000000000010000000000000000000000000000000->2176,2147483648
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int main()
{
	char*str="0xCB7EEC";
	printf("%lld\n",atoll(str));
}
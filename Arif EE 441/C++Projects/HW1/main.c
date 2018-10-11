#include <stdio.h>


int main(int argc, char **argv)
{
 int bytes = GetModuleFileName(NULL, pBuf, len);
if(bytes == 0)
	return -1;
else
	return bytes;
	return 0;
	
}


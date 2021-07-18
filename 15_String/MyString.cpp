#include "MyString.h"

char* MyStrcat(char* dest, char* sour)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest == '\0' && *sour != '\0')
	{
		*dest = *sour;
		dest++;
		sour++;
	}
	return dest;
}

char* MyStrncat(char* dest, char* sour, size_t n)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest == '\0' && *sour != '\0' && n != 0)
	{
		*dest = *sour;
		dest++;
		sour++;
		n--;
	}
	return dest;
}

int MyStrcmp(char* dest, char* sour)
{
	int result = 0;
	while (!(*(unsigned char*)dest - *(unsigned char*)sour) && *dest)
	{
		dest++;
		sour++;
	}
	return *(unsigned char*)dest - *(unsigned char*)sour;
}

int MyStrncmp(char* dest, char* sour, size_t n)
{
	int result = 0;
	while (!(*(unsigned char*)dest - *(unsigned char*)sour) && n != 0)
	{
		dest++;
		sour++;
		n--;
	}
	if (n == 0)
	{
		return 0;
	}
	return *(unsigned char*)dest - *(unsigned char*)sour;
}

char* MyStrcpy(char* dest, char* sour)
{
	while (*sour != '\0')
	{
		*dest = *sour;
		dest++;
		sour++;
	}
	return dest;
}

char* MyStrncpy(char* dest, char* sour, size_t n)
{
	while (*sour != '\0' && n != 0)
	{
		*dest = *sour;
		dest++;
		sour++;
		n--;
	}
	return dest;
}

char* MyStrlwr(char* str)
{
	while (*str != '\0')
	{
		if ('A' <= *str && *str <= 'Z')
		{
			*str = *str + ('a' - 'A');
		}
		str++;
	}
	return str;
}

char* MyStrupr(char* str)
{
	while (*str != '\0')
	{
		if ('a' <= *str && *str <= 'z')
		{
			*str = *str - ('a' - 'A');
		}
		str++;
	}
	return str;
}

char* MyStrstr(char* dest, char* sour)
{
	char* pStart = NULL;
	while (*dest != '\0' && *sour != '\0')
	{
		pStart = dest;
		while (*pStart == *sour && *sour != '\0')
		{
			pStart++;
			sour++;
		}
		if (*sour == '\0')
		{
			return dest;
		}
		dest++;
	}
	return NULL;
}

size_t MyStrlen(char* str)
{
	int n = 0;
	while (*str != '\0')
	{
		str++;
		n++;
	}
	return n;
}


#include <iostream>

int main(int argc, char* argv[])
{
	printf("called parameter:\n");
	for (int i = argc - 1; i >= 0; i--)
	{
		puts(argv[i]);
	}

	system("pause");
	return 0;
}


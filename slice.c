#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *__slice__(char* str, int start, int end)
{
	int len = end - start + 1;

	char *res = malloc(sizeof(char) * len + 1);
	res[len] = '\0';

	memcpy(res, str+start, len);

	return res;
}

void assert_eq(char *a, char *b)
{
	assert(strcmp(a, b) == 0);
}


int main(void)
{
	char *string = "0123456789";
	char *slice = __slice__(string, 0, 9);

	printf("%s\n", slice);
	assert_eq(slice, string);
	free(slice);

	slice = __slice__(string, 1, 8);
	printf("%s\n", slice);
	assert_eq(slice, "12345678");
  free(slice);

	slice = __slice__(string, 5, 5);
	printf("%s\n", slice);
	assert_eq(slice, "5");
  free(slice);
}

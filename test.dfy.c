#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef char* string;
typedef uint64_t nat;

char *__slice__(char* str, int start, int end)
{
	int len = end - start + 1;

	char *res = malloc(sizeof(char) * len + 1);
	res[len] = '\0';

	memcpy(res, str+start, len);

	return res;
}

bool test(nat a, string b)
// TODO declare bool res
// ensures res ==> a == 2
{
    return a == 2;
}

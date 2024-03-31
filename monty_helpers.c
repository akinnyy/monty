
#include "monty.h"

/**
 * verify_args - verify the args
 * @argc: arguments
 * Return: 0 in succes -1 in fail
 */

void verify_args(int argc)
{
	if (argc > 2 || argc < 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * open_and_read - open the monty file and read his content
 * @f: the file to open
 * Return: Void no return
 */
void open_and_read(char *f)
{
	size_t l = 0;
	ssize_t r;
	unsigned int ln = 1;
	int value;
	char *op, *val, *opcode;

	settings.file = fopen(f, "r");
	if (settings.file == NULL)
		error_handler(f, -96, ln);
	while ((r = getline(&settings.line, &l, settings.file)) != -1)
	{
		op = strtok(settings.line, " ");
		if (*op == '#' || *op == '\n')
		{
			ln++;
			continue;
		}


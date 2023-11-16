#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (pass.arg)
	{
		if (pass.arg[0] == '-')
			j++;
		for (; pass.arg[j] != '\0'; j++)
		{
			if (pass.arg[j] > 57 || pass.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(pass.file);
			free(pass.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(pass.file);
		free(pass.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(pass.arg);
	if (pass.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
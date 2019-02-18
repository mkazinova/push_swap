# push_swap
Push_swap project is a very simple and highly effective algorithm project: data
needs to be sorted. We have at our disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks.
We create 2 programs in C:
• The first, named checker which takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays OK if integers
are sorted. Otherwise, it will display KO.
• The second one called push_swap which calculates and displays on the standard
output the smallest progam using Push_swap instruction language that sorts integer
arguments received.

We have the following operations at our disposal:
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
Push_swap Because Swap_push isn’t as natural
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
rrr : rra and rrb at the same time.

USAGE:
ARG="numbers"; ./push_swap $ARG				- to get sorting instructions
ARG="numbers"; ./checker $ARG				- to check sorting instructions for correctness
ARG="numbers"; ./checker $ARG -v			- to visualize stacks being sorted
ARG="numbers"; ./checker $ARG -vc			- to visualize stacks being sorted with color

ARG="numbers"; ./push_swap $ARG | ./checker $ARG -vc	- to get instructions and visualize sorting

There are two sorting algorithms involved:
	- quick quicksort for big stacks (over 10 elements)
	- slower but more precise kinda selection sort (for a smaller stack)

Note:
	We are not allowed to use any functions apart from Read, Malloc, Free and Write, so
	my recoding of standart C library and some other basic useful functions is attached.

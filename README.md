This project has been created at part of the 42 curriculum by cvillene[, ejulien].

Description:
	This project aims to sort a stack using two bases stacks (a and b) and a specific list of allowed operations. There are three differents algorithms with each their own time order : Simple (O(n²)), Medium (O(nsqrt(n))) and Complex (O(nlog(n))).
	There also is the possibility to let the program finds the adequate algorithm according to the disorder of the stack to sort.
	The push_swap program output all the operations using to sort the stack, then a benchmark (only if specified) including : disorder of the stack, strategy and time order, total count of the operations, count of each operations.

Instructions:
	- Utilisation of the push_swap (* for mandatory arguments):
		make
		./push_swap --strategy --bench [*nbrs]
	- Specified parameters is optionnal but can include:
		--adaptative (default strategy) : chose the algorithme according to the disorder of the stack.
		--simple  : use O(n²) algorithm
		--medium  : use O(nsqrt(n)) algorithm
		--complex : use O(nlog(n)) algorithm
		--bench   : print the benchmark of the program after sorting
	The numbers must contain no duplicates and must be in the range INT_MIN - INT_MAX.
	The arguments cannot contains anything other than the strategy, bench and numbers. If that is not the case, 'Error' will be returned. If there are no arguments, nothing will be returned.

Usage Examples:
	- Allowed commands:
		./push_swap 1 2 3 4 6 5
		./push_swap --simple "1 2 3 4 6 5"
		./push_swap --bench 1 "2 3 4" 6 5
		./push_swap --simple --bench -1 "+2 3 4" 6 5
	- Not allowed commands:
		./push_swap
		./push_swap --simple
		./push_swap 1 2 3 4 6 5 --simple
		./push_swap 1 2 3 --simple 4 6 5
		./push_swap 1 2 3 a 4 5 6

Algorithms:
	
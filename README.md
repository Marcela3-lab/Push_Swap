*This project has been created as part of the 42 curriculum by marcebar and fdos-rei.*

# Push_Swap
## Description

push_swap is a sorting algorithm project from the 42 curriculum that focuses on sorting data using a limited set of operations on two stacks.

The goal is to sort a stack of integers with the smallest possible number of moves, using only specific stack instructions and an auxiliary stack.

# This project helps develop skills in:

- Algorithm design and optimization
- Data structures (stacks / linked lists)
- Complexity analysis
- Memory management in C
- Problem-solving under constraints

# The allowed operations include:

- sa, sb, ss (swap)
- pa, pb (push)
- ra, rb, rr (rotate)
- rra, rrb, rrr (reverse rotate)

# Objective

Sort a stack of integers in ascending order using the minimum number of operations, following the constraints of the allowed moves between stack A and stack B.

# Algorithm Selection and Justification

In this project, we implemented different sorting strategies depending on the size of the input. The goal was to reduce the number of operations while respecting the strict constraints of the push_swap rules. We designed three approaches based on input complexity.

## Sort Small Algorithm (O(1))

For inputs of 2 or 3 elements, a dedicated hardcoded sorting routine is used.
These cases can always be solved in at most 2–3 operations regardless of the
values provided, so no dynamic algorithm selection is needed.

This routine runs only if no algorithm flag is passed in the arguments and is the most efficient possible solution for these edge cases, since every operation can be done without using a second stack.

## Simple Algorithm (O(n²))

For small inputs, we use a simple sorting strategy based on minimum and maximum extraction methods.

We repeatedly locate the smallest (or next correct) element in stack A and move it to its correct position using basic operations such as swaps and rotations.

This method is efficient for small datasets because:

The overhead of more complex algorithms is unnecessary
The implementation remains simple and reliable
The constant factor is very low in practice

Even though its time complexity is O(n²), it performs well for very small inputs (typically 2–5 elements), which is the intended scope of this approach.

## Medium Algorithm (O(n√n))

For medium-sized inputs, we use a chunk-based partitioning strategy, where the stack is divided into approximately √n chunks.

Each chunk is processed separately by pushing elements from stack A to stack B based on value ranges, then reinserting them in the correct order.

This approach improves performance by:

Reducing full-stack scans
Splitting the problem into smaller, manageable segments
Optimizing the number of rotations and push operations

This results in a significant improvement compared to the simple method, achieving approximately O(n√n) complexity.

## Complex Algorithm (O(n log n))

For large inputs, we use a Radix Sort-based algorithm that processes numbers using their binary representation.

We iterate through each bit position and distribute elements between stack A and stack B depending on the current bit value.

This algorithm was chosen because:

It guarantees stable and predictable performance
It scales efficiently for large datasets
It avoids comparisons by using bitwise operations

Its complexity is O(n log n), making it the most efficient solution for large inputs within the constraints of the project.

## Adaptive Algorithm Selection (Default Behaviour)

By default, when no flags are provided, push_swap uses an adaptive strategy 
that automatically selects the appropriate sorting algorithm based on two 
factors: the size of the input and its disorder level.

The disorder level is computed as a percentage that measures how far the 
current stack is from being sorted. Based on this metric, the program 
dynamically chooses between the simple, medium, or complex algorithm — 
ensuring that small or nearly-sorted inputs are handled efficiently without 
unnecessary overhead.

This adaptive selection is the default behaviour of the program unless a 
specific flag is passed to override it.

## Contributions

This project was developed collaboratively by *marcebar* and *fdos-rei*.

**fdos-rei** was responsible for:
- Stack data structure implementation and initialisation (nodes, stack operations)
- All 11 sorting operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)
- Sorting algorithms (sort small, simple, complex)
- Adaptive algorithm selection based on disorder metric
- Benchmark mode (--bench flag)

**marcebar** was responsible for:
- Argument parsing (flags initialization, handling integers)
- Error management (duplicates, overflow, and invalid characters)
- Memory management and leak-free cleanup across all execution paths
- Sorting algorithms (medium)
- Integration testing and edge case validation

## Resources

Stack Overflow, GitHub repositories, and algorithm visualizations were used for debugging, testing strategies, and understanding sorting approaches (such as radix sort and small-stack sorting techniques).

## HOW AI WAS USED:

AI was used as a complementary tool to help understand sorting strategies, debug edge cases, and improve code structure. However, all implementations were independently developed and validated through personal testing and research.

## Instructions

To compile the project:

make
How to test the executable

The program push_swap receives a list of integers as arguments and outputs the sequence of operations needed to sort them.

▶ Basic usage
./push_swap 3 2 1

▶ Another example
./push_swap 42 -1 0 7 3
Rules for input
Each number must be passed as a separate argument
No letters or invalid characters are allowed
Duplicate numbers are not allowed

❌ Invalid examples:
./push_swap 3 a 2
./push_swap 1 2 2 3
Useful tests
Count number of operations

You can check how efficient your algorithm is by counting the output lines:

./push_swap 3 2 1 | wc -l
Test with a random set of numbers
./push_swap 5 1 4 2 3
If you have the checker (bonus or external tool)
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
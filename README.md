# Banker-s-Algorithm
Example:
g++ banker.cpp -o banker
./banker

The program is separated into four different functions.
1. Main - calls the following functions
2. populateArrays - populates the allocation matrix, max matrix, and available resource arrays from the data file
3. banker - executes the banker algorithm with the given data
4. output - outputs the results of the algorithm

The algorithm follows these steps:
1. Initially set all sequences as safe
2. Calculate the need matrix by finding the difference between the max matrix and the allocation matrix
3. Execute a triple nested for loop

This is how the triple nested for loop works:
1. The outermost loop serves to allow multiple passes over the entire set of processes
2. The next loop iterates up to 5 times, checking each if each process has each of the necessary resources. If resources available for a process, it is added to the sequence
3. The innermost loop checks if there is enough of each resource for the given process
4. The 4th loop, within the if statement of the middle loop, releases each resource.
















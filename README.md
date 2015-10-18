# mpi-ring-distsys15_ashwini_prabhu

## MPI Ring (HW6)

###### How to run:

It is implemented in C. To compile this program, 
```
$ mpicc ring.c -o ring
```
To run,
```
$ mpirun -n <number of processes> ./ring <count>
```
where,
number of processes: is the total number of process instances that we want tot run.
count: is the number of times the control should pass through all the processes.
For example,
```
$ mpirun -n 10 ./ring 100
```
The output will be something like following

Message: 1
Sending from processor ashwinipra, rank 1 out of 10 processors

Message: 2
Sending from processor ashwinipra, rank 2 out of 10 processors

Message: 3
Sending from processor ashwinipra, rank 3 out of 10 processors

Message: 4
Sending from processor ashwinipra, rank 4 out of 10 processors
.
.
.
Count is: 100
All processes finished in 0.147916 secs.
Sending from processor ashwinipra, rank 0 out of 10 processors
0 processor is out 







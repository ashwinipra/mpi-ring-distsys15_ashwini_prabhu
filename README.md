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
The output will be something like following,
```
$ mpirun -n 10 ./hello 100

Message: 10
Message: 20
Message: 30
Message: 40
Message: 50
Message: 60
.
.
.
Message: 980
Message: 990
Message: 1000
Count is: 1000
All processes finished in 0.195992 seconds.
Sending from processor ashwinipra, rank 0 out of 10 processors
```






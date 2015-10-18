#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);
    if(argc != 2)
    {
        printf("\nUsage: mpirun -n <number of processes> ./hello <count>");
    }
    else
    {
        // Get the number of processes
        int world_size;
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);
        // Get the rank of the process
        int world_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
        
        // Get the name of the processor
        char processor_name[MPI_MAX_PROCESSOR_NAME];
        int name_len;
        MPI_Get_processor_name(processor_name, &name_len);
        int printCount = atoi(argv[1]), num = 1, num1 = 1;
        double startTime = 0.0, endTime = 0.0;
        if(printCount != 0 && (printCount % world_size) ==0 )
        {
            do {
                if(world_rank == 0)
                {
                    MPI_Status stat;
                    
                    startTime = MPI_Wtime();                // Start with the time calculation
                    if(num == 1)
                        MPI_Send((void*) &num, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);  // Send from 0th process
                    MPI_Recv((void*) &num, 1, MPI_INT, world_size - 1, 1, MPI_COMM_WORLD, &stat);  // Receive at 0th process
                    printf("\nMessage: %d",num);
                    num ++;
                    if(num1 == printCount)         // When count is equal to given count print it and the total time taken.
                    {
                        endTime = MPI_Wtime() - startTime;
                        printf("\nCount is: %d",--num);
                        printf("\nAll processes finished in %f secs.", endTime);
                    }
                    else
                        MPI_Send((void*) &num, 1, MPI_INT, world_rank + 1, 1, MPI_COMM_WORLD);
                    
                }
                else if(world_rank == world_size - 1)        // For processes between 0 to n
                {
                    MPI_Status stat;
                    MPI_Recv((void*) &num, 1, MPI_INT, world_rank - 1, 1, MPI_COMM_WORLD, &stat);
                    printf("\nMessage: %d",num);
                    num ++;
                    MPI_Send((void*) &num, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
                    
                }
                else            // For the last process
                {
                    MPI_Status stat;
                    MPI_Recv((void*) &num, 1, MPI_INT, world_rank - 1, 1, MPI_COMM_WORLD, &stat);
                    printf("\nMessage: %d",num);
                    num ++;
                    MPI_Send((void*) &num, 1, MPI_INT, world_rank + 1, 1, MPI_COMM_WORLD);
                }
                
                
                // Print off a hello world message
                printf("\nSending from processor %s, rank %d"
                       " out of %d processors\n",
                       processor_name, world_rank, world_size);   
                
                // Finalize the MPI environment.
                num1 ++;
            }while(num1 <= printCount);
            //printf("%d processor is out\n", world_rank);
        }
        else
        {
            printf("\nPlease give a nonzero count which is multiple of number of processes.");
        }
    }
    MPI_Finalize();
    return 0;
}


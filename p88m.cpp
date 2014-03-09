#include <iostream>
#include <mpi.h>

using namespace std;
int main(int argc, char** argv) {
	int proc_id, proc_cnt;
	int sum, startval, endval, accum;

	MPI_Status status;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &proc_cnt);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc_id);

	
	sum = 0;
	startval = 1000 * proc_id / proc_cnt + 1;
	endval = 1000 * (proc_id + 1) / proc_cnt;
	
	for (int i = startval; i <= endval; i++)
		sum += i;

	if (proc_id != 0)
		MPI_Send(&sum, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
	else
		for (int j = 1; j < proc_cnt; j++){ 
			MPI_Recv(&accum, 1, MPI_INT, j, 1, MPI_COMM_WORLD, &status);
			sum += accum;
		}
	
	if (proc_id == 0)
		cout << "The sum from 1 to 1000 is: " << sum << endl;

	MPI_Finalize();

	return 0;
}

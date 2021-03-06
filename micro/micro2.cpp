#include "pstl/execution"
#include "pstl/algorithm"
#include "pstl/numeric"

#include <mutex>
#include <vector>
#include <numeric>
#include <tbb/task_scheduler_init.h>
#include <thread>
#include <chrono>

#include <iostream>

/* parameters */
#define	N		1000000000

void reset_vector(std::vector<double> &in) {
	
	/*std::generate(pstl::execution::par, in.begin(), in.end(), []() ->double{
		
		return rand() % 1000;
	});*/

	int g_seed = 343434;
	g_seed = (214013*g_seed+2531011);
	for(int i = 0; i < in.size(); i++) in[i] = (g_seed>>16) & 0x7FFF;
}

int main(int argc, char **argv) {
	
	double end_res = 0.0;
	int num_workers;
    if(const char * nw = std::getenv("TBB_NUM_THREADS")) {
        num_workers = atoi(nw);
    } else {
        num_workers = 1;
    }
	
	//int n = tbb::task_scheduler_init::default_num_threads();
	
	tbb::task_scheduler_init init(num_workers);
	
	printf("\n");
	printf(" Microbenchmark Parallel STL\n");
	printf(" Hardware Threads: %d\n", std::thread::hardware_concurrency());
	printf(" TBB Threads:      %d\n", num_workers);
	printf(" Test Size:        %ld\n", N);
	printf("\n\n");
	
	std::vector<double> v(N);
	
	srand (time(NULL));
	
	reset_vector(v);
	/*
	
	
	
	auto begin = std::chrono::high_resolution_clock::now();
	
	std::sort(pstl::execution::seq, v.begin(), v.end());
	
	auto end = std::chrono::high_resolution_clock::now();

	printf(" std::sort() in serial:                 %llu.%06llu seconds\n",
	std::chrono::duration_cast<std::chrono::seconds>(end - begin).count(), 
	std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() % 1000000);
	
	end_res = std::reduce(pstl::execution::par, v.begin(), v.end(), end_res);
	reset_vector(v);
	
	
	//////////////SORT
	
	for(int i = 2; i <= n; i+=2) {
		
		tbb::task_scheduler_init init(i);
		*/
		auto begin = std::chrono::high_resolution_clock::now();
	
		std::sort(pstl::execution::par, v.begin(), v.end());
	
		auto end = std::chrono::high_resolution_clock::now();

		printf(" std::sort():     %llu.%06llu seconds\n",
		std::chrono::duration_cast<std::chrono::seconds>(end - begin).count(), 
		std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() % 1000000);
	
		end_res = std::reduce(pstl::execution::par, v.begin(), v.end(), end_res);
		reset_vector(v);
	
	//}
	
	
	
	
	printf("\n\n Final output: %f\n\n", end_res);
	
    return 0;
}

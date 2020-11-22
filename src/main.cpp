#include <iostream>
#include <cstdlib>
#include <thread>
#include <iostream>
#include <functional>
#include <chrono>  
#include <vector>
#include <iomanip>
#include <ctime>
#include "../include/Timer.h"
#include "../include/debug.h"

void print_time(){
	auto time = std::time(nullptr);
	std::cout << GRN << "Current time/date (undef zone): " << MAG << std::put_time(std::gmtime(&time), "%c") << std::endl << RST;
	debug("This is a dummy error");
}

int main() {
	Timer timer2("Outer");
    std::cout << GRN << "Hello, world!" <<std::endl<< RST;
	{		
		Timer timer("Inner");
		 		print_time();		 
	}
	std::vector<uint64_t> fib_vec = { 0, 1 };
	Timer timer("Fibenaci");
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	std::cout << YEL << "Destructor called!" <<std::endl<< RST;
    return 0;
}
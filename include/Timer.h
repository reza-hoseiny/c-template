#ifndef __TIMER_H__
#define __TIMER_H__
#include <iostream>
#include <string>
#include <chrono>
#include "./colors.h"

class Timer{
    
public:
    
Timer(std::string _name){
		startTimePoint = std::chrono::high_resolution_clock::now();
		this->name = _name;
    }
    
~Timer(){
        Stop();
    }
    
void Stop(){
        auto endTimePoint= std::chrono::high_resolution_clock::now();
        auto diff_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endTimePoint-startTimePoint).count(); 
        auto diff_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(endTimePoint-startTimePoint).count(); 
        auto diff_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTimePoint-startTimePoint).count(); 
		std::cout << BLU << this->name << " Timer	" << diff_milliseconds;
		std::cout << " miliSec	[" << diff_microseconds << " MicroSec]	(";
		std::cout << diff_nanoseconds << " ns)" <<std::endl << RST;
    }
    
private:
		std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint;
		std::string name;
};
#endif // __TIMER_H__

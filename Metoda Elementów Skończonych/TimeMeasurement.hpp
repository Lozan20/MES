#ifndef TIMEMEASUREMENT_HPP
#define TIMEMEASUREMENT_HPP
#include <chrono>
#include <iostream>

using namespace std::chrono;
class TimeMeasurement
{
	steady_clock::time_point begin;
	steady_clock::time_point end;
	double elapsed_time;
public:
	TimeMeasurement() = default;
	void start()
	{
		begin = high_resolution_clock::now();
	}
	void stop()
	{
		end = high_resolution_clock::now();
		calculateElapsedTimeAndPrint();
	}
	void calculateElapsedTimeAndPrint()
	{
		elapsed_time = duration_cast<nanoseconds>(end - begin).count();
		std::cout << "Program executed in: " << elapsed_time * 1e-9 << " s";
	}
};
#endif // TIMEMEASUREMENT_HPP

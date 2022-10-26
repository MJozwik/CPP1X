//============================================================================
// Name        : Threading.cpp
// Author      : Mariusz Jóźwik, mariusz.jozwik.78@gmail.com
// Version     :
// Copyright   :
// Description : My concurrency workshop
//============================================================================

#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

#define RUN_LOOP (true)

// General purpose debugging thread function
void thread_function(const char* name, int delay_ms);

// Use a type definition to easily switch between types of delays
using delay_function = std::chrono::milliseconds;

void thread_function(const char* name, int delay_ms)
{
	static double counter=0;
	do {
		std::cout << "Thread name: "<< name << " counter: "<< counter << std::endl;
		std::this_thread::sleep_for(delay_function(delay_ms));
		counter++;
	} while(RUN_LOOP);
}

int main() {
	std::cout << "Concurrency Workshop" << std::endl;
	std::thread first_thread(thread_function, "First thread", 200);
	std::thread second_thread(thread_function, "Second thread", 500);
	std::thread third_thread(thread_function, "Third thread", 1000);

	first_thread.join();
	second_thread.join();
	third_thread.join();

	return 0;
}

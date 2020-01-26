// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "pch.h"

// In general, ignore this file, but keep it around if you are using pre-compiled headers.
//	PID NODE
PID::PID(int processID, int startTime) {
	this->processID = processID;
	this->startTime = startTime;
	this->next = 0;
}
int PID::get_start_time() {
	return this->startTime;
}
int PID::get_process_id() {
	return this->processID;
}
void PID::set_next(PID* newPID) {
	this->next = newPID;
}
PID* PID::get_next() {
	return this->next;
}



//	PID_QUEUE	
PID_Queue::PID_Queue() {
	this->numEl = 0;
	first = last = 0;
}
void PID_Queue::insert(int processID, int startTime) {
	PID* newPID = new PID(processID, startTime);
	if (numEl == 0) {
		first = last = newPID;
	}
	else if (numEl == 1) {
		if (newPID->get_start_time() < first->get_start_time()) {
			newPID->set_next(first);
			first = newPID;
		}
		else {
			first->set_next(newPID);
			last = newPID;
		}
	}
	else if(numEl >=2) {
		PID* temp;
		temp = first;
		//newPID->get_start_time() < temp->get_start_time() && 
		while (temp!= 0) {
			if (temp->get_next() != 0 && newPID->get_start_time() < temp->get_next()->get_start_time()) {
				newPID->set_next(temp->get_next());
				temp->set_next(newPID);
				break;
			}
			//newPID->get_start_time() >= temp->get_start_time() && newPID->get_start_time() < temp->get_next()->get_start_time()
			else if (temp->get_next() == 0){
				temp->set_next(newPID);
				last = newPID;
				break;
			}
			temp = temp->get_next();
		}
	}
	numEl++;
}
PID* PID_Queue::DeQueue() {
	PID* pointToReturnPID;
	if (first->get_next() == 0) {
		pointToReturnPID = first;
	}
	else {
		pointToReturnPID = first;
		first = first->get_next();
		pointToReturnPID->set_next(0);
	}
	numEl--;
	std::cout << pointToReturnPID->get_process_id() << std::endl;
	std::cout << pointToReturnPID->get_start_time() << std::endl;
	return pointToReturnPID;
}


#include <iostream>

class PID {
	int processID;
	int startTime;
	PID* request;
	PID* next;
public:
	PID(int,int);
	int get_start_time();
	int get_process_id();
	void set_next(PID*);
	PID* get_next();
	//CORE* request_CORE();
};
class PID_Queue {
	int numEl;
	PID* first, *last;
public:
	PID_Queue();
	void insert(int ,int );
	PID* DeQueue();
	
};
class CORE {
	int corePeriod;
public:
	
};

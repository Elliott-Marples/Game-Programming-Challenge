// Define Guard
#ifndef PROJECT_TIMER_H



// Declarations
class Timer {
private:
	int start;

public:
	Timer();

	void Reset();
	int Get();
};

#endif // !PROJECT_TIMER_H
#ifndef DATA
#define DATA

typedef enum bool bool;
enum bool {false=0, true=1};

typedef struct Data Data;
struct Data{
	bool stopped;
};

#endif

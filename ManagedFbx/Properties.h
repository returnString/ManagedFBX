
#define property_r(type, name)\
	property type name\
	{\
	type get();\
	}

#define property_rw(type, name)\
	property type name\
	{\
	type get();\
	void set(type value);\
	}
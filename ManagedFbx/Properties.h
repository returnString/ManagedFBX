#pragma once

// Defines a read-only property.
#define property_r(type, name)\
	property type name\
	{\
	type get();\
	}

// Defines a property that is only writable internally.
#define property_ri(type, name)\
	property type name\
	{\
	type get();\
	internal: void set(type value);\
	}

// Defines a readable and writable property.
#define property_rw(type, name)\
	property type name\
	{\
	type get();\
	void set(type value);\
	}
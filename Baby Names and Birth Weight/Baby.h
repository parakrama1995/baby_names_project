#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
public:
	Baby() { // default constructor
	}

	Baby(string s, int w, string w) { // constructor
		name.assign(s);
		weight = w;
	}

	// a "getter" method
	int getWeight() {
		return weight;
	}

	// a "getter" method
	string getName() {
		return name;
	}

private:
	string name;
	int weight;
};

class client {
public:
	() { // default constructor
	}

	(string s, int w, string w) { // constructor
		name.assign(s);
		weight = w;
	}

	// a "getter" method
	int getWeight() {
		return weight;
	}

	// a "getter" method
	string getName() {
		return name;
	}

private:
	string name;
	int weight;
};
bool jw_search ( int *list, int size, int key, int*& rec, int rec1 )
{
  // Basic sequential search
  bool found = false;
  int i;

  for ( i = 0; i < size; i++ ) {
    if ( key == list[i] )
      break;
  }
  if ( i < size ) {
    found = true;
    rec = &list[i];
  }

  return found;
}

#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"
#define ARR_SIZE 200000

using namespace std;

class MedicalRecord {
public:
	// default constructor
	MedicalRecord() {
		size = 0;
	}

	// destructor
	~MedicalRecord() {
		delete[]bB;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename.c_str());

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				// cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName() {

		int count = 0, tmpcount = 0;
		string mpName, tmpName;

		for (int i = 0; i<size; i++) {
			tmpName = bB[i].getName();
			tmpcount = 0;
			for (int j = 0; j<size; j++)
			{
				if (tmpName.compare(bB[j].getName()) == 0)
					tmpcount++;
			}

			if (count == 0) {
				count = tmpcount;
				mpName.assign(tmpName);
			}
			else if (count<tmpcount) {
				count = tmpcount;
				mpName.assign(tmpName);
			}
		}
		return mpName; // TO BE COMPLETED
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
		return size;
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
		int count = 0;
		for (int i = 0; i<size; i++)
			if (bB[i].getWeight() <2500)
				count++;
		return count; // TO BE COMPLETED
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
		int count = 0;
		for (int i = 0; i<size; i++)
			if (bB[i].getName().compare(s) == 0)
				count++;
		return count;
	}

private:
	// update the data structure with information contained in Baby object
	void addEntry(Baby b) {
		if (size == 0)
		{
			bB = new Baby[ARR_SIZE];
			bB[size++] = b;
		}
		else if (size<ARR_SIZE)
			bB[size++] = b;
		else
			cout << "No space in the array to add" << endl;
	}

	// Add private member variables for your data structure along with any
	// other variables required to implement the public member functions

	int size;
	Baby *bB;

};
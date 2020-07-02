#include <iostream>
#include <cstring>
#include "headers/DBClient.h"

using namespace std;

/**
 * This method creates a value with a size of 6K bytes
 *
 * @return a pointer to a char array with a size of 6K bytes
 **/
char* DBClient::getEntryVal(char startingChar)
{
    char* val = new char[ENTRY_SIZE];
    strncpy(val, "", 1);

    int letter = int(startingChar);

    for (int i = 0; i < ENTRY_SIZE; i++)
    {
	if (i != 0 && i % 1200 == 0)
	{
	    letter++;
	}

	char c = char(letter);
	const char* str_letter = &c;
	strncat(val, str_letter, 1);
    }

    return val;
}

/**
 * This method calculates the elapsed time based on the given start and end time values 
 *
 * @param start - the starting timestamp
 * @param end - the ending timestamp
 *
 * @return a double value of the elapsed time
 **/
double DBClient::calculateTime(chrono::time_point<std::chrono::high_resolution_clock> start, chrono::time_point<std::chrono::high_resolution_clock> end)
{
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start);

    double time = elapsed.count() * 1e-6;

    return time;
}


/**
 * This method generates n random numbers within the lower to upper range
 * and none of those random numbers are repeated
 *
 * @param n - the number of random numbers to generate
 * @param min - the minimum number that the random number can be
 * @param max - the maximum number that the random number can be
 *
 * @return - returns a set of n random numbers
 **/
set<int> DBClient::getRandomKeys(int n, int lower, int upper)
{
    srand(time(0));
    set<int> keySet;
    int count = 0;

    while (count != n)
    {
	// get a random num from 1 to 1 million
	int randomNum = (rand() % (upper + 1 - lower)) + lower;

	auto it = keySet.find(randomNum);

	// if key is not already in the set
	if (it == keySet.end() && randomNum <= 1000000)
	{
	    keySet.insert(randomNum);
	    count++;
	}
    }

    return keySet;
}

void DBClient::connect()
{
    cout << "Method is ran from the DBClient...." << endl;
    exit(1);
}


void DBClient::disconnect() 
{
    cout << "DB disconnected" << endl;
}

/**
 * Initializes the DB by inserting 1 million entries with each having a data 
 * of 6K bytes and a key of 64 bits
 *
 * @return the double value of the time it took to initialize the DB
 **/
double DBClient::initializeDB()
{
    cout << "Method is ran from the DBClient...." << endl;
    return -1;
}


/**
 * Does a simple read on an entry in the DB
 *
 * @param key - the key of the entry to be read
 *
 * @return the double value of the time it took to complete a read
 **/
double DBClient::readEntry(string key) 
{
    cout << "Method is ran from the DBClient...." << endl;
    return -1;
}


/**
 * Does an insertion of an entry into the DB
 *
 * @param key - the key of the entry to be inserted into the DB
 *
 * @return the double value of the time it took to complete the insertion
 **/
double DBClient::insertEntry(string key)
{
    cout << "Method is ran from the DBClient...." << endl;
    return -1;
}


/**
 * Makes an update on an existing entry in the DB
 *
 * @param key - the key of the entry to update
 * @param newVal - the value to update the provided key
 *
 * @return a double value of the time it took to complete an update
 **/
double DBClient::updateEntry(string key) 
{
    cout << "Method is ran from the DBClient...." << endl; 
    return -1;
}


/**
 * Deletes an entry within the DB
 *
 * @param key - the key of the entry to be deleted
 *
 * @return a double value of the time it took to complete a deletion
 **/
double DBClient::deleteEntry(string key)
{
    cout << "Method is ran from the DBClient...." << endl;
    return -1;
}


/**
 * Simulates having multiple of readers reading on the same
 * key at the same time
 *
 * @param n - the number of readers 
 * @param key - the key of the entry to have all the readers read
 *
 * @return a double value of the time it took for all the 
 * simultaneous readers to read the key
 **/
double DBClient::simultaneousReaders(int n, string key)
{
    cout << "Method is ran from the DBClient...." << endl;
    return -1;
}


/**
 * Simulates having multiple of tasks happening at the same time.
 * The tasks done are either reading or doing an update on an entry. 
 * The reading/modifying is split 5-1:5-1 and is based on the number 
 * of simultaneous tasks going on.
 *
 * @param n - the number of simultaneous tasks
 *
 * @return a double value of the time it took for all the 
 * simultaneous tasks to finish
 **/
double DBClient::simultaneousTasks(int n)
{
    cout << "Method is ran from the DBClient...." << endl;
    return -1;
}



double DBClient::performTransactions(int n, double p)
{
    cout << "Method is ran from the DBClient...." << endl;
    return -1;
}

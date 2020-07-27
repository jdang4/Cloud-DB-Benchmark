#ifndef BENCHMARKMANAGER_H
#define BENCHMARKMANAGER_H

#include <fstream>
#include <iostream>
#include "RedisClient.h"
#include "PostgresClient.h"


class DBClient;

class BenchmarkManager 
{
    public:
	BenchmarkManager(int n, bool option);
	~BenchmarkManager();

	void selectDB(int db, std::string host);
	void setThreads_and_Runs(int threads, int runs);
	void performRandomization();
	void initializeDB();
	void connect();
	void disconnect();
	void openCSV(int n);
	void closeCSV();
	double getReadOutput(int threads, bool csvOption, bool random);
	double getInsertOutput(int threads, int start, bool csvOption);
	double getUpdateOutput(int threads, int start, bool csvOption, bool random);
	double getDeleteOutput(int threads, int start, bool csvOption, bool random);
	double getSimultaneousTasksOutput(int threads, bool csvOption, bool random, int num = 0);
	double getTransactionsOutput(int threads, int start, bool csvOption, int num = 0);
	
    private:
	DBClient* client;
	int trials;
	int dbClient;
	bool showOutputs;
	bool randomOption;
	std::ofstream* csv;
};


#endif

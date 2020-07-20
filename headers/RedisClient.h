#ifndef REDISCLIENT_H
#define REDISCLIENT_H

#include "DBClient.h"
#include "../include/redis-plus-plus/src/sw/redis++/redis++.h"
#include <set>
#include <chrono>

class DBClient;

class RedisClient : public DBClient
{
    public:
	RedisClient(int n);
	~RedisClient();
	void connect() override;
	double initializeDB() override;
	double readEntry(std::string key) override;
	double insertEntry(std::string key) override;
	double updateEntry(std::string key) override;
	double deleteEntry(std::string key) override;
	double simultaneousReaders(int n, std::string key) override;
	double simultaneousTasks(int n) override;
	double performTransactions(int n, double p) override;
	 
    private:
	sw::redis::Redis* redis;
	char* entryVal;
	char* newVal;
	int numOfRuns;
	
	template<typename Lambda>	
	double run_threads(Lambda f, int begin);
	
	//void* read(void* arg);
	//void updateOne(string key);
};

#endif

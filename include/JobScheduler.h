/*
 **************************************************************************
 * Author: Giannis Kotsias		                                          *
 * URL: http://github.com/gianniskts                                      *
 *                                                                        *
 * Copyright notice:   							  						  *
 * Free use this code is permitted under the guidelines 		  		  *
 * and in accordance with the MIT License. 				  				  * 
 *                                                                        *
 **************************************************************************
*/
#pragma once

#include <pthread.h>
#include <unistd.h>
#define perror2(s,e) fprintf(stderr, "%s: %s\n",s,strerror(e));
#define true 1
#define false 0


#include "./Queue.h"

typedef void* Pointer;
typedef const void* ConstPointer;

typedef struct JobScheduler {

	size_t pool_size;   // number of execution threads
	pthread_t * threads;
	Queue * jobsQueue;
	int jobScheduler_shutDown;
	int numOfJobs;

	pthread_mutex_t queue_mtx;
	pthread_cond_t queue_not_empty;
	pthread_cond_t queue_empty;
	pthread_cond_t cond_barrier;
	
} JobScheduler;


typedef struct Job {

	Pointer args;
	void (*routine)(Pointer);

} Job;

Pointer thread_function(Pointer);


JobScheduler * initialize_scheduler(int execution_threads);
Job * new_job(Pointer args,void (*routine)(Pointer));
void destroy_job(Job* job);
void submit_job(JobScheduler* scheduler,void (*routine)(Pointer),Pointer args);
void execute_job(JobScheduler * scheduler);
void wait_activeJobs_finish(JobScheduler* scheduler);
void shutdown_JobScheduler(JobScheduler* scheduler);
void destroy_scheduler(JobScheduler* scheduler);


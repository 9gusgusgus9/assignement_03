#include "Scheduler.h"
#include "Mcd.h"

void Scheduler::init(){
    this -> fixPeriod = false;
    nTask = 0;
}

void Scheduler::init(int basePeriod){
    this -> basePeriod = basePeriod;
    this -> fixPeriod = true;
    timer.setupPeriod(basePeriod);
    nTask = 0;
}

bool Scheduler::addTask(Task* task){
    if(nTask < MAX_TASK-1){
        tasks[nTask] = task;
        nTask++;
        if(!fixPeriod){
            if(nTask == 1){
                this -> basePeriod = task -> getBasePeriod();
            } else {
                this -> basePeriod = mcd( this -> basePeriod, task -> getBasePeriod());
            }
            timer.setupPeriod(this -> basePeriod);
        }
        return true;
    } else {
        return false;
    }
}

void Scheduler::schedule(){
    timer.waitForNextTick();
    for(int i = 0; i < nTask; i++){
        if(tasks[i] -> updateAndCheckTime( this -> basePeriod)){
            tasks[i] -> tick();
        }
    }
}
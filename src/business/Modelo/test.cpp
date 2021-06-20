#include "business/Modelo/test.hpp"
#include <chrono>
#include <ctime>

Test::Test(){
    this->startDate=0;
    this->endDate=0;
    this->questionList=new list<Question>;
}

Test::Test(int startDate,int endDate){
    this->startDate=startDate;
    this->endDate=endDate;
    this->questionList=new list<Question>;
}

Test::Test(int startDate,int endDate,list<Question>* questionList){
    this->startDate=startDate;
    this->endDate=endDate;
    this->questionList=questionList;
}

Test::~Test(){
    delete this->questionList;
}
#include "business/Modelo/test.hpp"
#include <chrono>
#include <ctime>

namespace GUI{
Test::Test(string name){
    this->name=name;
    this->startDate=0;
    this->endDate=0;
    this->questionList=new list<Question>;
}

Test::Test(int startDate,int endDate,string name){
    this->name=name;
    this->startDate=startDate;
    this->endDate=endDate;
    this->questionList=new list<Question>;
}

Test::Test(int startDate,int endDate,list<Question>* questionList,string name){
    this->name=name;
    this->startDate=startDate;
    this->endDate=endDate;
    this->questionList=questionList;
}

Test::~Test(){
    delete this->questionList;
}

void Test::InsertQuestion(Question q){
    this->questionList->push_back(q);
}
}
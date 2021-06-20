#ifndef TEST_H
#define TEST_H

//isso precisa ser movido pra outro arquivo depois
enum Status
{
        PENDING,
        OPEN,
        FINISHED
};

#include "business/Modelo/question.hpp"
#include <list>
#include <iterator>

using namespace std;

//por enquanto, estou pensando apenas no professor
class Test {
    private:
        list<Question>* questionList;
        int startDate;
        int endDate;
    public:
        Test(); //prova sem data definida
        Test(int,int); //prova com data definida
        Test(int,int,list<Question>*); //reutilizar questões
        ~Test();

        list<Question>* getQuestion();
        void RemoveQuestion(Question);
        void setQuestion(Question,Question);
        auto getStartDate();
        void setStartDate(int);
        auto getEndDate();
        void setEndDate(int);
        Status getStatus();
};


#endif
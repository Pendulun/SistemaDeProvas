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
#include <string>
#include <list>
#include <iterator>

using namespace std;

//por enquanto, estou pensando apenas no professor
namespace GUI{
class Test {
    private:
        list<Question>* questionList;
        int startDate;
        int endDate;
        string name;

    public:
        Test(string); //prova sem data definida
        Test(int,int,string); //prova com data definida
        Test(int,int,list<Question>*,string); //reutilizar questões
        ~Test();

        list<Question>* getQuestions();
        void setQuestion(Question,Question);
        void RemoveQuestion(Question);
        void InsertQuestion(Question);
        int getStartDate();
        void setStartDate(int);
        int getEndDate();
        void setEndDate(int);
        Status getStatus();
        string getName();
        string setName(string);
};
}

#endif
#ifndef __PROFESSORNOTFOUNDEXCEPTION_H__
#define  __PROFESSORNOTFOUNDEXCEPTION_H__
#include <exception>
#include <string>
namespace Business{
    class ProfessorNotFoundException : public std::exception{
        public:
            ProfessorNotFoundException(const std::string&);
            ProfessorNotFoundException();

            const char* what() const throw();

            virtual ~ProfessorNotFoundException();

        private:
            std::string msg;
    };
}
#endif
#ifndef __TURMANOTFOUNDEXCEPTION_H__
#define  __TURMANOTFOUNDEXCEPTION_H__
#include <exception>
#include <string>
namespace Business{
    class TurmaNotFoundException : public std::exception{
        public:
            TurmaNotFoundException(const std::string&);
            TurmaNotFoundException();

            const char* what() const throw();

            virtual ~TurmaNotFoundException();

        private:
            std::string msg;
    };
}
#endif
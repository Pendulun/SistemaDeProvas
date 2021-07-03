#ifndef __ALUNONOTFOUNDEXCEPTION_H__
#define  __ALUNONOTFOUNDEXCEPTION_H__
#include <exception>
#include <string>
namespace Business{
    class AlunoNotFoundException : public std::exception{
        public:
            AlunoNotFoundException(const std::string&);
            AlunoNotFoundException();

            const char* what() const throw();

            virtual ~AlunoNotFoundException();

        private:
            std::string msg;
    };
}
#endif
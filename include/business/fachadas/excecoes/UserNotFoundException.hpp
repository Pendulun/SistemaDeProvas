#ifndef __USERNOTFOUNDEXCEPTION_H__
#define  __USERNOTFOUNDEXCEPTION_H__
#include <exception>
#include <string>
namespace Business{
    class UserNotFoundException : public std::exception{
        public:
            UserNotFoundException(const std::string&);
            UserNotFoundException();

            const char* what() const throw();

            virtual ~UserNotFoundException();

        private:
            std::string msg;
    };
}
#endif
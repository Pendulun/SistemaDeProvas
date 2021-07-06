#ifndef __ALTERNATIVA_H_
#define __ALTERNATIVA_H_
#include <string>
namespace Modelo{
    class Alternativa{
        protected:
            std::string texto;
            int numeroAlternativa;
        public:
            Alternativa();
            Alternativa(std::string);
            Alternativa(std::string, int);
            const int getNumeroAlternativa();
            void setNumeroAlternativa(int);
            const std::string getTexto();
            void setTexto(std::string);
    };
}
#endif
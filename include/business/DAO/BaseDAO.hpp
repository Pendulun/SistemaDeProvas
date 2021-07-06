#ifndef __BASEDAO_H__
#define __BASEDAO_H__
#include <string>
#include <list>
namespace Business{
    template <typename T> class BaseDAO{
        public:
            virtual int cadastrar(T) = 0;
            virtual T* pesquisar(int) = 0;
            virtual std::list<T> pesquisar(const std::list<int>) = 0;
            virtual bool remover(T) = 0;
            virtual bool atualizar(T) = 0;
    };
}
#endif
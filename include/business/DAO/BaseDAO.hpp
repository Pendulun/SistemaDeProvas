#ifndef __BASEDAO_H__
#define __BASEDAO_H__
#include <string>
namespace Business{
    template <typename T> class BaseDAO{
        public:
            virtual bool cadastrar(T) = 0;
            virtual T* pesquisar(int) = 0;
            virtual bool remover(T) = 0;
    };
}
#endif
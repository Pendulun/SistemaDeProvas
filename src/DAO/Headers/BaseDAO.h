#ifndef __BaseDAO_H__
#define __BaseDAO_H__

template <class T>
class BaseDAO
{
    public:
        void cadastrar(T);
        T pesquisar(int);
        void alterar(T);
        void remover(T);
};

#endif
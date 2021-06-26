#ifndef __USUARIODAO_H__
#define __USUARIODAO_H__
namespace Business{
    class UsuarioDAO{
        public:
            virtual bool cadastrar() = 0;
            virtual bool login() = 0;
            virtual ~UsuarioDAO() = 0;
    };
}
#endif
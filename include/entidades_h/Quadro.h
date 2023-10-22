#ifndef QUADRO_H_INCLUDED
#define QUADRO_H_INCLUDED

#include "../dominios_h/Codigo.h"
#include "../dominios_h/Texto.h"
#include "../dominios_h/Limite.h"
#include <string>

using namespace std;

class Quadro {
    private:
        Codigo codigo;
        Texto nome;
        Texto descricao;
        Limite limite;
    
    public:
        void setCodigo(const Codigo&);
        void setNome(const Texto&);
        void setDescricao(const Texto&);
        void setLimite(const Limite&); 
        Codigo getCodigo() const;    
        Texto getNome() const;         
        Texto getDescricao() const;         
        Limite getLimite() const;        
}; 

inline void Quadro::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}
inline void Quadro::setNome(const Texto &nome){
    this->nome = nome;
}
inline void Quadro::setDescricao(const Texto &descricao){
    this->descricao = descricao;
}
inline void Quadro::setLimite(const Limite &limite){
    this->limite = limite;
}
inline Codigo Quadro::getCodigo() const{
    return codigo;
}
inline Texto Quadro::getNome() const{
    return nome;
}
inline Texto Quadro::getDescricao() const{
    return descricao;
}
inline Coluna Quadro::getLimite() const{
    return limite;
}

#endif // QUADRO_H_INCLUDED

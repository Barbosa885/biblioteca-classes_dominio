#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
#include "../dominios_h/Texto.h"
#include "../dominios_h/Senha.h"
#include "../dominios_h/Email.h"

class Conta 
{
  private:
    Texto nome;
    Senha senha;
    Email email;

  public:
    Conta();
    Conta(Texto, Senha, Email);
    ~Conta();

    Texto getNome();
    Senha getSenha();
    Email getEmail();

    void setNome(Texto);
    void setSenha(Senha);
    void setEmail(Email);
};

inline void Conta::setNome(Texto nome) {
  this->nome = nome;
}

#endif // CONTA_H

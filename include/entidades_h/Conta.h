// #ifndef CONTA_H
// #define CONTA_H
// 
// #include <iostream>
// #include <string>
// #include "../dominios_h/Texto.h"
// #include "../dominios_h/Senha.h"
// #include "../dominios_h/Email.h"
// 
// class Conta 
// {
//   private:
//     Texto nome;
//     Senha senha;
//     Email email;
// 
//   public:
//     Conta();
//     Conta(Texto, Senha, Email);
//     ~Conta();
// 
//     Texto getNome();
//     Senha getSenha();
//     Email getEmail();
// 
//     void setNome(Texto);
//     void setSenha(Senha);
//     void setEmail(Email);
// };
// 
// inline void Conta::setNome(Texto nome) {
//   this->nome = nome;
// }
// 
// inline void Conta::setSenha(Senha senha) {
//   this->senha = senha;
// }
// 
// inline void Conta::setEmail(Email email) {
//   this->email = email;
// }
// 
// inline Texto Conta::getNome() {
//   return nome;
// }
// 
// inline Senha Conta::getSenha() {
//   return senha;
// }
// 
// inline Email Conta::getEmail() {
//   return email;
// }
// 
// #endif // CONTA_H

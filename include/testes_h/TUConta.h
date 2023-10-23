// /**
//  * @file TUConta.h
//  * @brief Definição da classe de teste TUEmail.
//  *
//  * Esta classe de teste verifica a validade do domínio Email, seguindo critérios de formato definidos.
//  *
//  * Autor: Gustavo Barbosa (202037589)
//  */
// 
// #ifndef TESTE_EMAIL_H
// #define TESTE_EMAIL_H
// 
// #include "../entidades_h/Conta.h"
// #include <string>
// #include <iostream>
// 
// using namespace std;
// 
// class TUConta
// {
//   private:
//     string NOME_VALIDO = "Gustavo";
//     string SENHA_VALIDA = "Abc1.";
//     string EMAIL_VALIDO = "user@domain.com";
//     int estado;                             /**< Estado do teste. */
//     TUConta *conta;                           /**< Referência para o objeto a ser testado. */
//     void setUp();                           /**< Método para criar unidade em teste. */
//     void tearDown();                        /**< Método para destruir unidade em teste. */
//     void testarCenarioSucesso();            /**< Cenário de teste. */
//     void testarCenarioFalha();              /**< Cenário de falha. */
// 
//   public:
//     TUConta();                              /**< Construtor padrão. */
//     virtual ~TUConta();                     /**< Destrutor padrão. */
//     const static int SUCESSO =  0;          /**< Definição de constante para reportar resultado de teste. */
//     const static int FALHA = -1;            /**< Definição de constante para reportar resultado de teste. */
//     void run();                             /**< Executa teste. */
// };
// 
// #endif // TESTE_EMAIL_H

#include "../../include/dominios_h/Coluna.h"
#include <string>
#include <iostream>


void COLUNA::isValid(string coluna){
/** 
* @brief
* verifica se a coluna atende a um critério específico:
* Se é "SOLICITADO" ou "EM EXECUCAO" ou "CONCLUIDO".
* @param coluna a ser verificada.
* @throw exception type: "argumento invalido" caso a coluna não atenda ao critério estabelecido.
*/
    if (coluna == "SOLICITADO" || coluna == "EM EXECUCAO" ||coluna == "CONCLUIDO") return; /**< verifica se a coluna é uma das seguintes opções: "SOLICITADO", "EM EXECUÇÃO" ou "CONCLUIDO". */
    throw invalid_argument("Argumento invalido");
}

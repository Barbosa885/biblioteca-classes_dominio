#ifndef LIMITE_H
#define LIMITE_H

#include <string>
#include <stdexcept>

using namespace std;

class LIMITE{
    private:
        int limite;
        void verifica(int);
        /**
        * verifica se o limite atende a alguns critérios específicos.
        * @param limite verificado.
        * saída: "argumento inválido" caso o limite não atenda a um dos críterios estabelecidos.
        */
        
    public:
        int GetLimite();
        /**
        * obtem o limite;
        * retorna esse limite.
        */
        void SetLimite(int);
        /**
        * define o limite.
        */
};

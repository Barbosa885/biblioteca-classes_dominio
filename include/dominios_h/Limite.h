#ifndef LIMITE_H
#define LIMITE_H

#include <string>
#include <stdexcept>

using namespace std;

class LIMITE{
    private:
        int limite;
        void isValid(int);
        /**
        * verifica se o limite atende a alguns critérios específicos.
        * @param limite verificado.
        * saída: "argumento inválido" caso o limite não atenda a um dos críterios estabelecidos.
        */
        
    public:
        /**
        * obtem o limite;
        * retorna esse limite.
        */
        int GetLimite();
};

inline int LIMITE::GetLimite(){
    return limite;
}

#endif // LIMITE_H

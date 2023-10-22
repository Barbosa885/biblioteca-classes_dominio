#ifndef COLUNA_H
#define COLUNA_H

#include <string>
#include <stdexcept>

using namespace std;

class COLUNA{
    private:
        string coluna;
        void verifica(string);
        /** 
        * verifica se a coluna atende a critérios específicos.
        * @param a coluna verificada.
        * saída: "argumento inválido" caso a coluna não atenda a um dos críterios estabelecidos.
        */
        
    public:
        string GetColuna();
        /**
        * obtem a coluna;
        * retorna essa coluna.
        */
        void SetColuna(string);
        /**
        * define a coluna.
        */
};

inline void COLUNA::SetColuna(string coluna){
    verifica(coluna);
    this -> coluna = coluna;
}

inline string COLUNA::GetColuna(){
    return coluna;
}

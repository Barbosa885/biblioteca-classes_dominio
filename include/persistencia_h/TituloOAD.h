#ifndef TITULOOAD_H
#define TITULOOAD_H

#include <vector>
#include <string>
#include "Conexaobanco.h"
#include "../entidades_h/Titulo.h"

class TituloOAD {
public:
    TituloOAD(const std::string& dbPath);
    ~TituloOAD();

    void criarTitulo(const Titulo& titulo);
    Titulo obterTitulo(const std::string& codigo);
    std::vector<Titulo> listarTitulos();
    void atualizarTitulo(const Titulo& titulo);
    void excluirTitulo(const std::string& codigo);

private:
    Conexaobanco dbConnection;

};

#endif // TITULOOAD_H

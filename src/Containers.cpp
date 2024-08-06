#include "../include/Containers.h"
#include "../include/dominios_h/CodigoTitulo.h"

ContainerConta* ContainerConta::instancia = nullptr;

ContainerConta* ContainerConta::getInstancia() {
    if (instancia == 0)
        instancia = new ContainerConta();
    return instancia;
}

bool ContainerConta::criar(Conta conta){
    return container.insert(make_pair(conta.getCpf().getCpf(), conta)).second;
}

bool ContainerConta::excluir(Cpf cpf) {
    // Primeiro, verificar se a conta existe
    auto itConta = container.find(cpf.getCpf());
    if (itConta == container.end()) {
        return false; // Conta n�o encontrada
    }

    // Obter os t�tulos associados � conta
    vector<Titulo> titulos = ContainerTitulos::getInstancia()->visualizarTitulos(cpf);

    // Excluir todos os t�tulos associados � conta
    for (const auto& titulo : titulos) {
        CodigoTitulo codigoTitulo = titulo.getCodigoTitulo();
        ContainerTitulos::getInstancia()->excluirTitulo(cpf, codigoTitulo);

        // Excluir todos os pagamentos associados ao t�tulo
        ContainerPagamentos::getInstancia()->excluirPagamentosPorTitulo(codigoTitulo);
    }

    // Excluir a conta
    container.erase(itConta);
    return true; // Conta exclu�da com sucesso
}

Conta ContainerConta::visualizar(Conta* conta){
    map<string, Conta>::iterator it = container.find(conta->getCpf().getCpf());
    if(it != container.end()){
        *conta = it->second;
        return it->second;
    }
    else{
        throw runtime_error("");
    }
}

bool ContainerConta::existe(Conta* conta){
    map<string, Conta>::iterator it = container.find(conta->getCpf().getCpf());
    if(it != container.end()){
        *conta = it->second;
        return true;
    }
    return false;
}

bool ContainerConta::editar(Conta conta){
    map<string, Conta>::iterator it = container.find(conta.getCpf().getCpf());
    if(it != container.end()){
        it->second = conta;
        return true;
    }
    return false;
}


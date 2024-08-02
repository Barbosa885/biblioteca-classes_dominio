#include "../../include/dominios_h/Setor.h"

Setor::Setor()
{
  //ctor
}

Setor::~Setor()
{
  //dtor
}

// Lista de setores válidos
const vector<string> Setor::SETORES = {
  "Agricultura",
  "Construção civil",
  "Energia",
  "Finanças",
  "Imobiliário",
  "Papel e celulose",
  "Pecuária",
  "Química e petroquímica",
  "Metalurgia e siderurgia",
  "Mineração",
};

// Método que verifica se o setor está presente na lista de setores válidos
bool Setor::encontrarSetor(const string& setor){
  // Verifica se o setor está presente na lista de setores válidos
  for (int i = 0; i < SETORES.size(); i++){
    // Se o setor estiver presente, retorna verdadeiro
    if (setor == SETORES[i]) {
      return true;
    }
  }
  return false;
}

// Método que valida o setor fornecido
void Setor::validar(const string& setor){
  // Verifica a resposta da função encontrarSetor
  if (!encontrarSetor(setor)) {
    throw invalid_argument("Setor invalido");
  } 
  return;
}

// Método que define o setor
void Setor::setSetor(const string& setor){
  validar(setor);
  this->setor = setor;
}

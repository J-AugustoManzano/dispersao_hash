// ============================================================================
// PROGRAMA   : colisao2.cpp
// DESCRIÇÃO  : Script de análise empírica e validação estatística.
//              Mapeia o comportamento da função de hash multiplicativa de 
//              constante sucessiva (DJB2), demonstrando visualmente a eficácia 
//              da dispersão não linear e a redução drástica de colisões.
// AUTOR      : Prof. Me. José Augusto Navarro Garcia Manzano
// VERSÃO     : 2.0
// DATA       : Maio / 2026
// DIRETRIZES : ISO/IEC - Rigor lógico e estrutural para ensino de programação.
// ============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <vector>

using namespace std;

// A função com multiplicativa de constante prima 
static std::string myHash(std::string mensagem) {
  unsigned long hashCalculado = 5381;

  for (char c : mensagem)
    hashCalculado = ((hashCalculado << 5) + hashCalculado) + static_cast<unsigned long>(c);

  std::stringstream hash;
  hash << std::setfill('0') << std::setw(10) << hashCalculado;
  return hash.str();
}

int main(void) {
  // Mapa que associa o Hash gerado com as strings que o produziram
  unordered_map<string, vector<string>> mapaDeHashes;
  
  // Gerador simples de strings para teste (combinações de 3 caracteres imprimíveis)
  // Escopo de caracteres ASCII visíveis: do espaço (32) ao 'z' (122)
  
  unsigned long totalStringsTestadas = 0, totalColisoes = 0;
  double taxaColisao;

  for (char c1 = 'A'; c1 <= 'Z'; c1++) {
    for (char c2 = 'A'; c2 <= 'Z'; c2++) {
      for (char c3 = 'A'; c3 <= 'Z'; c3++) {
        for (char c4 = 'A'; c4 <= 'Z'; c4++) {
          string texto = "";
          texto += c1;
          texto += c2;
          texto += c3;
          texto += c4;
          
          totalStringsTestadas++;
          string h = myHash(texto);
          
          // Guarda a string no vetor correspondente àquele hash
          mapaDeHashes[h].push_back(texto);
        }
      }
    }
  }

  cout << "==================================================" << endl;
  cout << "RESULTADO DO TESTE DE COLISAO - VERSAO 2.0" << endl;
  cout << "==================================================" << endl;
  cout << "Total de strings testadas (tamanho 4): " << totalStringsTestadas << endl;

  // Varre o mapa procurando vetores com tamanho maior que 1 (indica colisão)
  for (auto const& [hash, strings] : mapaDeHashes) {
    if (strings.size() > 1) {
      totalColisoes += (strings.size() - 1);
      
      // Exibe as primeiras 5 colisões encontradas para não inundar a tela
      if (totalColisoes <= 5) {
        cout << "Hash: [" << hash << "] colidiu para as entradas: ";
        for (const string& s : strings) {
          cout << "\"" << s << "\" ";
        }
        cout << endl;
      }
    }
  }

  cout << "--------------------------------------------------" << endl;
  cout << "Total de colisoes detectadas: " << totalColisoes << endl;
  taxaColisao = (static_cast<double>(totalColisoes) / totalStringsTestadas) * 100.0;
  cout << "Taxa de colisao no escopo testado: " <<  taxaColisao << "%" << endl;
  cout << "==================================================" << endl;

  cout << endl << "Tecle <Enter> para encerrar... ";
  cin.get();

  return 0;
}

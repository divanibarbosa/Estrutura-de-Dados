#include <iostream>
using namespace std;
struct No {  double item;
             No *prox;
};
class ListaSE {
  private: No *primeiro; // referencia ao primeiro Nó da lista
           No *ultimo; // referencia ao ultimo Nó da lista
  public: ListaSE()   { primeiro=ultimo=NULL; } // Construtor
  bool vazio()        { return (primeiro==NULL); }
  double item_frente() { return primeiro->item;    }
  void adiciona(double valor) {
     No *lista = new No(); // Alocando memoria para o Nó
     lista->item = valor; 
     lista->prox = NULL;
     if (vazio()) primeiro = lista;
     else ultimo->prox = lista;
     ultimo = lista;
  }                                                          

  void insere(int pos, double valor) {
    if (pos < 0) return;

    No *lista = new No(); // Alocando memoria para o Nó
    lista->item = valor; 

    if(pos == 0) {
      lista->prox = primeiro;
      primeiro = lista;
    }
    else { 
          No *atual = primeiro;
          for(int i=1; i < pos && atual->prox != NULL; i++) 
             atual = atual->prox;
          lista->prox = atual->prox;
          atual->prox = lista;
          if (lista->prox == NULL) ultimo = lista;
    }
  }

  bool pesquisa(double chave) {
    No *atual = primeiro;
    while (atual != NULL) {  // caminhando para o fim da lista
      if(atual->item == chave) return true;
      atual = atual->prox;
    }
    return false;
  }
 

  void imprime() {
    No *atual = primeiro;
    while (atual != NULL) {   // caminhando para o fim da lista
      cout << "{" << atual->item << "} ";
      atual = atual->prox;
    }
    cout << endl;
  } 

  void apaga(double valor) {  
    No *atual, *anterior;
    atual = anterior = primeiro;
    while (atual != NULL) { // caminhando para o fim da lista
      if ( atual->item == valor) break;
      anterior = atual;
      atual = atual->prox;
    }
    if (atual == NULL) return;
    if (atual == primeiro) { primeiro = primeiro->prox;
                             anterior = NULL;
    }
    else if (atual == ultimo) { ultimo = anterior;
                                ultimo->prox = NULL;
         }
         else anterior->prox = atual->prox;
    atual = NULL; 
  }


}; // fim da classe ListaSE

int main() {
  ListaSE l;
  cout << ">>> Adicionando 2.4, 1.3, -7 no fim\n";
  l.adiciona(2.4); l.adiciona(1.3); 
  l.adiciona(-7);  
  cout << " Imprimindo Lista: "; l.imprime();
  cout << ">>> Inserindo -5.5 na posicao 1\n";
  l.insere(1,-5.5);
  cout << " Imprimindo Lista: "; l.imprime();
  cout << ">>> Inserindo 32 na posicao 3\n";
  l.insere(3,32);
  cout << " Imprimindo Lista: "; l.imprime();
  cout << ">>> Removendo 1.3\n";
  l.apaga(1.3);
  cout << ">>> Removendo todos itens do inicio ao fim:\n";
  while (!l.vazio()) { // Enquanto lista não estiver vazia
        cout << " Removido {" << l.item_frente() << "}\n";
        l.apaga(l.item_frente());
  }
  return 0;
 } // fim programa principal

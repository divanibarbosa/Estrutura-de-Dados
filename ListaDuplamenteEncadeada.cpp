#include <iostream>
using namespace std;
struct No {
   double item;
   No *prox, *ant;
};
class ListaDE {
  private: No *primeiro, *ultimo; // referencia aos Nó da lista
  public: ListaDE() { primeiro = ultimo = NULL; } // Construtor
  bool vazio()         { return (primeiro==NULL);  }
  double item_frente() { return primeiro->item;    }
  double item_fim()    { return ultimo->item;      } 
  void adiciona(double valor) {
     No *novo = new No(); // Alocando memoria para o Nó
     novo->item = valor;
     novo->prox = NULL;
     if (vazio()) {
         novo->ant = NULL;
         primeiro = novo;
     } else {
         novo->ant = ultimo;
         ultimo->prox = novo;
     }
     ultimo = novo;
  }
 void insere(int pos, double valor) {
    if (pos < 0) return; // pos = POSIÇÃO DE INSERÇÃO
    No *novo = new No(); // Alocando memoria para o Nó
    novo->item = valor;
    if (pos == 0) { // se na primeira posição
      novo->prox = primeiro;
      novo->ant = NULL;
      primeiro->ant = novo;
      primeiro = novo;
      return;
    }
    No *atual, *proximo;
    atual = primeiro;
    proximo = atual->prox;
    for(int i=1; i < pos && atual->prox != NULL; i++) {
         atual = atual->prox; // posicionando no Nó atual
         proximo = atual->prox;
    }
    novo->prox = atual->prox;
    novo->ant = atual;
    atual->prox = novo;
    if (novo->prox == NULL) ultimo = novo; // se ultima posição
    else proximo->ant = novo;
  } 
  bool pesquisa(double chave) {
    No *atual = primeiro;
    while (atual != NULL) {  // caminhando para o fim da lista
      if (atual->item == chave) return true;
      atual = atual->prox;
    }
    return false;
  }
 
  void imprime_inicio() {
    No *atual = primeiro;
    while (atual != NULL) {   // caminhando para o fim da lista
      cout << "{" << atual->item << "} ";
      atual = atual->prox;
    }
    cout << endl;
  } 
  
  void imprime_fim() {
    No *atual = ultimo;
    while (atual != NULL) {   // caminhando para o fim da lista
      cout << "{" << atual->item << "} ";
      atual = atual->ant;
    }
    cout << endl;
  }

  void apaga(double valor) {  
    No *atual, *anterior, *proximo;
    anterior = NULL; atual = primeiro; proximo = atual->prox; 
    while (atual != NULL) { 
      if (atual->item == valor) break;
      anterior = atual;
      atual = atual->prox;
      if (atual != NULL) proximo = atual->prox;
    }   
    if (atual == NULL) return; 
    if (atual == primeiro && atual == ultimo) primeiro = ultimo = NULL;
    else if (atual == primeiro) { primeiro = primeiro->prox;
                                  primeiro->ant = NULL;
         }
         else if (atual->prox == NULL) { ultimo =  anterior;
                                         ultimo->prox = NULL;
              }
              else { anterior->prox = proximo;
                     proximo->ant = anterior;
              }
  }

}; // fim classe ListaDE

int main() {

    ListaDE l;

    cout << " >>> Adicionando 8.99, 3.43, 8.56 e 5.5 no fim\n";
    l.adiciona(8.99); l.adiciona(3.43); l.adiciona(8.56); l.adiciona(5.5);

    cout << " Imprimindo Lista inicio ao fim: "; l.imprime_inicio();
    cout << " Imprimindo Lista fim ao inicio: "; l.imprime_fim();

    cout << " >>> Inserindo 0 na posicao 2\n";   l.insere(2,0);

    cout << " >>> Adicionando 15 no fim\n";      l.adiciona(15);

    cout << " Imprimindo Lista inicio ao fim: "; l.imprime_inicio();
    cout << " Imprimindo Lista fim ao inicio: "; l.imprime_fim();

    cout << " >>> Removendo todos os itens da lista do inicio ao fim:\n";
    while (!l.vazio()) {
       cout << " Apagado {" << l.item_frente() << "}\n";
       l.apaga(l.item_frente());
    } 

    return 0;
}


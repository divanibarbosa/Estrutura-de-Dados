#include <iostream>
#include <math.h>
using namespace std;

struct HASH {
	double item;
	bool ocupado;
};

class HashSemColisoes {
  private: HASH *tab;
  private: int tam_max;

  public: HashSemColisoes(int tam) {
    tab = new HASH[tam];
    tam_max = tam;
    for(int i=0; i<tam; i++)
        tab[i].ocupado = false;
  }
  
  private: int funcaohash(double chave) {
    int v = (int) chave;
    return ( abs(v) % tam_max );
  }                                                           
  
  public: void insere(double item) {
     int pos = funcaohash(item);
     if ( !tab[pos].ocupado ) { // se nao tiver ocupado
		tab[pos].item=item;
		tab[pos].ocupado = true;
		cout << "-> Inseriu na posicao " << pos;
	}
	else cout << "-> Ocorreu uma colisao na posicao " << pos << ", item " << item << " NAO inserido\n";
  }

  public: int busca(double chave) { 
     int pos = funcaohash(chave);
     if (tab[pos].ocupado && tab[pos].item == chave) return pos;
     return -1;
  }

 public: void imprime() {
    for (int i=0; i<tam_max; i++)
       if ( tab[i].ocupado )
          cout << "\nHash[" << i << "] = " << tab[i].item;
  }
  public: void apaga(double chave) {
    int pos = busca(chave);
    if (pos != -1) {
       tab[pos].ocupado = false;
       cout << "-> Dados da posicao " << pos << " apagados\n";
    }
    else cout << "Item nao encontrado\n";
  } 

};

main() {
  HashSemColisoes tab(7);
  double item;
  cout << "\n************************************************************\n";
  cout << "Tabela HASH sem tratamento de colisoes (7 itens reais - double)\n";
  cout << "************************************************************\n";
  for (int i=0; i<7; i++){
		cout << "\n\nInserindo elemento " << (i+1) << endl;
		cout << " - Forneca valor real: ";
		cin >> item;
		tab.insere(item);
  }                                                            

    cout <<  "\n\nBuscando campo\n>>> Forneca o item: ";
    cin >> item;
    if ( tab.busca(item) != -1 )
       cout << "Item encontrado na posicao " << tab.busca(item);
    else
       cout << "Item nao encontrado";
 
    cout << "\n\nApagando campo\n>>> Forneca o item: ";
    cin >> item;
    tab.apaga(item);
	
    cout << "\n\nImprimindo conteudo";
    tab.imprime();

    cout << endl;	
}

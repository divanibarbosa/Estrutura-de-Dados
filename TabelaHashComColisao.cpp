#include <iostream>
#include <math.h>
using namespace std;

struct HASH {
	double item;
	bool ocupado;
};

class HashLinear {
  private: HASH *tab;
  private: int tam_max, n;

  public: HashLinear(int tam) {
    tab = new HASH[tam];
    tam_max = tam;
    n=0;
    for(int i=0; i<tam; i++)   // inicializando
        tab[i].ocupado = false;
  }
  
  private: int funcaohash(double chave) {
    int v = (int) chave;
	return ( abs(v) % tam_max );
  }
  
  public: bool cheia() {
	return n == tam_max;
  }
  
  public: void insere(double chave) {
	 if (cheia()) { 
	   cout << "\n->ATENCAO Tabela cheia\n";
	   return; 
	 }	
	 int pos = funcaohash(chave);
	 // INICIO ROTINA TRATAMENTO DE COLISAO
	 if (tab[pos].ocupado) { 
	     cout << "-> Ocorreu uma colisao na posicao " << pos << endl;
	     while (true) {
	       if (chave == tab[pos].item) { 
		   cout << "\n->ATENCAO Item ja cadastrado";
		   return; 
	        }
		if (pos == tam_max-1 ) pos = -1; 
		pos++; 
		if ( !tab[pos].ocupado ) break; 
	     }
	 }
	 // FIM ROTINA TRATAMENTO DE COLISAO	                      
	    tab[pos].item = chave;
	    tab[pos].ocupado = true;
	    n++; // incrementa um item na tabela
	    cout << "-> Inserido HASH[" << pos << "]";
  }

  public: int busca(double chave) { // Recuperando um elemento
	 int pos = funcaohash(chave);
	 if (tab[pos].ocupado) { // se posicao ocupada 
	    if (tab[pos].item == chave) return pos;  
	    int iniciobusca = pos;
	    while (true) { 
	        if (pos == tam_max-1) pos = -1; 
	        pos++; 
	        if (tab[pos].ocupado && tab[pos].item == chave) return pos; 
		    if (pos == iniciobusca) return -1; 
	    }
	    
	  } // fim if tab[pos].ocupado (se posicao ocupada)
	  return -1;
  }

  public: void apaga(double chave) {
    int pos = busca(chave);
    if (pos != -1) {
       tab[pos].ocupado = false;
       n--;
       cout << "-> Dados da posicao " << pos << " apagados\n";
    }
    else cout << "Item nao encontrado\n";
  }

  public: void imprime() {
    for (int i=0; i<tam_max; i++)
       if ( tab[i].ocupado )
          cout << "\nHash[" << i << "] = " << tab[i].item;
  }	
};

main() {
    HashLinear tab(7);
    double item;
    cout << "\n************************************************************\n";
    cout << "Tabela HASH com tratamento de colisoes Lista (7 itens reais - double)\n";
    cout << "************************************************************\n";
    for (int i=0; i<7; i++){
		cout << "\n\nInserindo elemento " << (i+1) << endl;
		cout << " - Forneca valor real: ";
		cin >> item;
		tab.insere(item);
    }

    cout <<  "\n\nBuscando campo\n>> Forneca o item: ";
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

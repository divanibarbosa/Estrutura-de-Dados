#include <iostream>
using namespace std;

class Pilha {
  private: 
  	double *itens; 
  	int topo, tam_max;

  public:
  Pilha(int n) { // construtor
    itens = new double[n];
    tam_max = n;
    topo = 0;
  }
  bool empty() { // verifica se vazia
    return ( topo == 0 );
  }
  bool full() { // verifica se cheia
    return ( topo == tam_max );
  }
  int size() { // retorna tamanho
    return topo;
  }
  void push(double valor) { // insercao itens
    if ( full() ) {
    	cout << " - PILHA CHEIA - ITEM NAO ADICIONADO - \n";
    	return;
	}
    itens[ topo ] = valor;
    topo++;
  }
  void pop() { // remocao itens
    if ( empty() ) {
    	cout << "- ATENCAO PILHA VAZIA - \n";
    	return;
	}
    topo--;
  }
  double top() { // retorna item do topo
    if( !empty() ) return itens[ topo-1 ];
  } 
}; // fim classe Pilha

/////////////////////////////////////////////////////////////
main() { // programa principal
    Pilha p(10); // Criando uma fila de 10 itens no m�ximo
    
    double valor;
    cout << "Informe 10 valores double para empilhar:\n";
    for(int i=0; i<10; i++) {
    	cin >> valor;
    	p.push(valor); 
	}
    
    cout << "Desinpilhando: ";
    while (!p.empty()) { // Ate esvaziar
      cout << " " << p.top(); // Mostre na tela 
						             // o valor do 
                                 // inicio
      p.pop(); // retira um item da fila
    }

} // fim programa principal aplicativo Fila Circular

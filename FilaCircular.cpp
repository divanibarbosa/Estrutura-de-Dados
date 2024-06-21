#include <iostream>
using namespace std;

class FilaCircular {
  private: double *itens;
  int fim;
  int tam_max;
  int inicio;
  int nItens;

  public: FilaCircular (int tam) {
    itens = new double[tam];
    tam_max = tam;
    fim = -1;
    inicio = 0;
    nItens = 0;
  }
  
  bool empty() { return (nItens == 0 );       }
  bool full()  { return (nItens == tam_max ); }
  int size()      { return nItens;               }
  void enqueue(double valor) {
    if (full()) {
      cout << "\n >>> ATENCAO FILA CHEIA\n";
      return;
    }
    if (fim == tam_max-1) fim = -1;
    fim++;
    itens [ fim ] = valor;
    nItens++;
  }

  double front() {
    if (empty()) {
      cout << "\n >>> ATENCAO FILA VAZIA\n";
      return 0;
    }
    return itens[ inicio ];
  }
 void dequeue() {
    if (empty()) {
      cout << "\n >>> ATENCAO FILA VAZIA\n";
      return;
    }
    inicio++;
    if (inicio == tam_max) inicio = 0;
    nItens--;
  }

}; // fim Classe FilaCircular
/////////////////////////////////////////////////////////////
main() { // programa principal
    FilaCircular fc(10); // Criando uma fila de 10 itens no máximo
    
    double valor;
    cout << "Informe 10 valores double para enfileirar:\n";
    for(int i=0; i<10; i++) {
    	cin >> valor;
    	fc.enqueue(valor); 
	}
    
    cout << "Desinfileirando: ";
    while (!fc.empty()) { // Ate esvaziar
      cout << " " << fc.front(); // Mostre na tela 
						             // o valor do 
                                 // inicio
      fc.dequeue(); // retira um item da fila
    }

} // fim programa principal aplicativo Fila Circular

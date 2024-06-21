#include <iostream>
#include <queue>
using namespace std;

/* A Heap fornece insercao e remocao O(log n) 
   Acesso ao maior item de dados O(1)
*/

int main() {
	priority_queue <int> heap; // Iniciando Heap na memória
	int chave;
	cout << "Informe 10 valores numericos reais para enfileirar:\n";
	for(int i=0; i<10; i++) {
		cin >> chave;
		heap.push(chave);
	}
	cout << "Tamanho da Heap: " << heap.size() << endl;;
	cout << "Maior valor: " << heap.top() << endl;
	cout << "-> Removendo um item da Heap (maior valor)\n";
	heap.pop();
	cout << "Tamanho da Heap: " << heap.size() << endl;
	cout << "Maior valor: " << heap.top() << endl;
	cout << "A Heap esta vazia? " << heap.empty() << endl;
	cout << "-> Removendo todos os itens da Heap\n";
	while (!heap.empty()) {
		cout << "Removendo item " << heap.top() << endl;
		heap.pop();
	}
	cout << "A Heap esta vazia?  Resposta: " << heap.empty() << endl;
	
	system("pause");
	
	return 0;
}

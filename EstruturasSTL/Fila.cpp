#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue <float> fila; // Iniciando fila na memória
	float chave;
	cout << "Informe 5 valores numericos reais para enfileirar:\n";
	for(int i=0; i<5; i++) {
		cin >> chave;
		fila.push(chave);
	}
	cout << "Tamanho da fila: " << fila.size() << endl;;
	cout << "Valor que se encontra na frente da fila: " << fila.front() << endl;
	cout << "-> Removendo um item da fila\n";
	fila.pop();
	cout << "Tamanho da fila: " << fila.size() << endl;
	cout << "Valor que se encontra no frente da fila: " << fila.front() << endl;
	cout << "A fila esta vazia? " << fila.empty() << endl;
	cout << "-> Removendo todos os itens da fila\n";
	while (!fila.empty()) {
		cout << "Removendo item " << fila.front() << endl;
		fila.pop();
	}
	cout << "A fila esta vazia?  Resposta: " << fila.empty() << endl;
	
	//fila.clear();
	system("pause");
	
	return 0;
}

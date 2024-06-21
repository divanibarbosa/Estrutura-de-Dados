#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack <float> pilha; // Iniciando pilha na memória
	float chave;
	cout << "Informe 5 valores numericos reais para empilhar:\n";
	for(int i=0; i<5; i++) {
		cin >> chave;
		pilha.push(chave);
	}
	cout << "Tamanho da pilha: " << pilha.size() << endl;;
	cout << "Valor que se encontra no topo da pilha: " << pilha.top() << endl;
	cout << "-> Removendo um item da pilha\n";
	pilha.pop();
	cout << "Tamanho da pilha: " << pilha.size() << endl;;
	cout << "Valor que se encontra no topo da pilha: " << pilha.top() << endl;
	cout << "A pilha esta vazia? " << pilha.empty() << endl;
	cout << "-> Removendo todos os itens da pilha\n";
	while (!pilha.empty()) {
		cout << "Removendo item " << pilha.top() << endl;
		pilha.pop();
	}
	cout << "A pilha esta vazia?  Resposta: " << pilha.empty() << endl;
	system("pause");
	return 0;
}

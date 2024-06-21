#include <iostream>
#include <list>
using namespace std;

int main() {
	list <int> l; // Iniciando lista duplamente encadeada de int
	list <int>::iterator it; // Iterador para percorrer a lista
	int i, pos, chave;
	
	//INSERCAO
	cout << "Informe 10 valores inteiros:\n";
	for(i=0; i<10; i++) {
		cin >> chave;
		l.push_back(chave);
	}

	// CONTEUDO
	cout << "Conteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}	
	cout << "\nQuantidade de itens da lista: " << l.size() << endl;
	
	//INSERCAO POSICAO ESPECIFICA
	cout << "\nInforme o valor que deseja inserir: ";
	cin >> chave;
	cout << "Informe a posicao que deseja inserir esse valor: ";
	cin >> pos;
	it = l.begin();
	for(i=0; i<pos; i++) it++;
	l.insert(it, chave);
	
	cout << "Conteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}
	
	// BUSCA 
	cout << "\n\nInforme o valor deseja encontrar: ";
	cin >> chave;
	for(it=l.begin(); it!=l.end(); it++) {
		if (*it == chave) {
			cout << "Valor " << chave << " encontrado na lista\n";
			break;
		}
	}
	if (it == l.end()) cout << "Valor " << chave << " nao encontrado na lista\n";
	
	// REMOCAO 
	cout << "\nInforme o valor deseja remover: ";
	cin >> chave;
	for(it=l.begin(); it!=l.end(); it++) {
		if (*it == chave) {
			l.erase(it);
			break;
		}
	}
	if (it == l.end()) cout << "Valor " << chave << " nao encontrado na lista\n";
	
	cout << "Conteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}
	cout << "\nQuantidade de itens da lista: " << l.size() << endl;
	
	// FUNCIONALIDADES �TEIS
	cout << "\nOrdenando lista.";
	l.sort();
	
	cout << "\nConteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n\nInvertendo conteudo de posicao da lista.";
	l.reverse();
	
	cout << "\nConteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n\nRemovendo todos valores 1 que existem na lista: ";
	l.remove(1); // remove toda ocorrencia do caractere X na lista
	
	cout << "\nConteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}	

	cout << "\n\nRemovendo todos valores duplicados que existem na lista: ";	
	l.unique(); // remove todos elementos duplicados
	
	cout << "\nConteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}

	cout << endl << endl;
	system("pause");
	return 0;
}

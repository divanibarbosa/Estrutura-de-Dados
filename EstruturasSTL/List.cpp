#include <iostream>
#include <list>
using namespace std;

int main() {
	list <char> l; // Iniciando lista duplamente encadeada de char
	list <char>::iterator it; // Iterador para percorrer a lista
	int i, pos;
	char chave;
	char valor[] = {'G','B','D','E','A','F','J','H','C','I'};
	
	//INSERÇÃO
	cout << "Atribuindo 10 caracteres na lista.\n";
	for(i=0; i<10; i++) {
		l.push_back(valor[i]);
	}

	// CONTEÚDO
	cout << "Conteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}	
	cout << "\nQuantidade de itens da lista: " << l.size() << endl;
	
	//INSERÇÃO POSIÇÃO ESPECIFICA
	cout << "\nInforme o caractere deseja inserir: ";
	cin >> chave;
	cout << "Informe a posicao que deseja inserir: ";
	cin >> pos;
	it = l.begin();
	for(i=0; i<pos; i++) it++;
	l.insert(it, chave);
	cout << "Conteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}
	
	// BUSCA 
	cout << "\n\nInforme o caractere deseja encontrar: ";
	cin >> chave;
	for(it=l.begin(); it!=l.end(); it++) {
		if (*it == chave) {
			cout << "Caractere " << chave << " encontrado na lista\n";
			break;
		}
	}
	if (it == l.end()) cout << "Caractere " << chave << " nao encontrado na lista\n";
	
	// REMOÇÃO 
	cout << "\nInforme o caractere deseja remover: ";
	cin >> chave;
	for(it=l.begin(); it!=l.end(); it++) {
		if (*it == chave) {
			l.erase(it);
			break;
		}
	}
	if (it == l.end()) cout << "Caractere " << chave << " nao encontrado na lista\n";
	cout << "Conteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}
	cout << "\nQuantidade de itens da lista: " << l.size() << endl;
	
	// FUNCIONALIDADES ÚTEIS
	cout << "\nOrdenando lista.";
	l.sort();
	cout << "\nConteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}
	cout << "\nInvertendo conteudo de posicao da lista.";
	l.reverse();
	cout << "\nConteudo da lista: ";
	for(it=l.begin(); it!=l.end(); it++) {
		cout << *it << " ";
	}
	cout << "\nQuantos caracteres A existem na lista: ";
	l.remove('X'); // remove toda ocorrencia do caractere X na lista
	l.unique(); // remove todos elementos duplicados

	cout << endl << endl;
	system("pause");
	return 0;
}

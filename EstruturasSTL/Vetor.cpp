#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <char> v; // Iniciando vetor de caracteres
	char valor[] = {'B','C','D','E','F','G','H','I','J','K'};
	int i;
	// INSERÇÃO
	cout << "Atribuindo 10 caracteres ao vetor:\n";
	for(i=0; i<10; i++) {
		v.push_back(valor[i]); // Inserindo caracateres no final do vetor
	}
	cout << "Tamanho do vetor: " << v.size() << endl;
	cout << "Conteudo do vetor: ";
	for(i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}	
	cout << "\n-> Informe caractere para ser inserido no inicio do vetor: ";
	char chave;
	cin >> chave;
	v.insert( v.begin(), chave);	
	
	// IMPRESSÃO CONTEÚDO
	cout << "\nConteudo do vetor: ";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << endl;
	
	cout << "Elemento do inicio do vetor: " << v.front() << endl;
	cout << "Elemento do fim do vetor: " << v.back() << endl;
	cout << "Elemento da posicao 3 do vetor: " << v[3] << endl;
	
	// BUSCA
	cout << "\n-> Informe caractere para busca: ";
	cin >> chave;
	for(i=0; i<v.size(); i++) {
		if (chave == v[i]) {
			cout << chave << " encontrado na posicao " << i << endl;
			break;
		}
	}
	if (i == v.size()) cout << chave << " nao encontrado\n";
	
	// REMOÇÃO
	cout << "\nConteudo do vetor: ";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << "\nRemocao do elemento final. Caractere " << v.back() << endl;
	v.pop_back();
	cout << "Conteudo do vetor: ";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << endl;
	cout << "Remocao do elemento inicial. Caractere " << v.front() << endl;
	v.erase(v.begin());
	cout << "Conteudo do vetor: ";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	cout << endl;
	
	cout << "-> Informe caractere que deseja remover: ";
	cin >> chave;
	for(i=0; i<v.size(); i++) {
		if (chave == v[i]) {
			v.erase( v.begin()+i );
			cout << "Caractere removido da posicao " << i << endl;
			break;
		}
	}
	cout << "Conteudo do vetor: ";
	for(i=0; i<v.size(); i++) cout << v[i] << " ";
	
	// FUNCIONALIDADES ÚTEIS
	cout << "\n\nEsvaziando todo o vetor.";
	v.clear();
	cout << "\nO vetor esta vazio? Resposta: ";
	cout << v.empty() << endl << endl;
	
	system("pause");
	return 0;
}

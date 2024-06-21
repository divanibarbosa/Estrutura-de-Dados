#include <iostream>
#include <set>
using namespace std;
/* O conteiner set oferece insercao, remocao e busca em tempo logaritmico O(log n)
   e acesso ao conteudp de maneira ordenada em tempo O(log n)
   Nao eh uma Arvore binaria tradicional, ao inves disso ele eh uma Self-Balancing 
   Binary Search Tree (Arvore de Busca Binaria Auto-Balanceada ou Arvore Rubro-Negra)
   https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
   Sao arvores obrigatoriamente balanceada (tem uma condicao de ajuste para mante-la assim)
*/
 
int main() {
	multiset <int> arv;
	multiset <int>::iterator it;
	int chave, i;
	
	//INSERCAO
	int valor[] = {25,11,42,6,19,37,14};
	cout << "Adicionando itens na arvore binaria rubro-negra.\n";
	for(i=0; i<7; i++) {
		arv.insert(valor[i]);
	}
	cout << "Conteudo da arvore: ";
	for(it=arv.begin(); it!=arv.end(); it++) {
		cout << *it << " ";
	}
	cout << "\nInforme um valor que deseja inserir: ";
	cin >> chave;
	arv.insert(chave);
	
	//CONTEUDO
	cout << "Conteudo da arvore: ";
	for(it=arv.begin(); it!=arv.end(); it++) {
		cout << *it << " ";
	}
	cout << "\nQuantidade de itens da arvore: " << arv.size() << endl;
	
	//BUSCA
	cout << "\nInforme o valor deseja encontrar: ";
	cin >> chave;
	it = arv.find(chave);
	if (it == arv.end()) cout << "Elemento " << chave << " nao encontrado na arvore\n";
	else cout << "Caractere " << chave << " encontrado na arvore\n";
	
	//REMOCAO
	cout << "\nInforme o valor deseja remover: ";
	cin >> chave;
	it = arv.find(chave);
	if (it == arv.end()) cout << "Elemento " << chave << " nao encontrado na arvore\n";
	else arv.erase(chave);
	cout << "Conteudo da arvore: ";
	for(it=arv.begin(); it!=arv.end(); it++) {
		cout << *it << " ";
	}
	
	cout << endl << endl;
	system("pause");
	return 0;
}

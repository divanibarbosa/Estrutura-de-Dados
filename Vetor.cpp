#include <iostream>
using namespace std;

class Vetor { 
 private: 
   int *v; 
   int n;
   int tam_max;
 public:
   Vetor(int x) { 
       tam_max = x;
       v = new int[tam_max];
       n = 0; 
   }  
   void inserir(int valor){
     if (n >= tam_max)
	return;
     v[n] = valor;
     n++;
   } 
   void mostrar() {
     for(int i=0; i<n; i++) 
       cout << "v[" << i << "]= " << v[i] << endl;
   }
 int busca_linear(int chave) {
   for (int i=0; i<n; i++) 
     if ( v[i] == chave ) 
        return i;
   return -1;	    
 }
 void remover(int chave) {
   for (int i=0; i<n; i++) {
     if (v[i] == chave) { 
        if (i != (n-1)) { 
          for(int k=i; k<(n-1); k++)
             v[k] = v[k+1];
        }
        n--;
        break; 
     }    
   } 
 }
}; 

main() {
 Vetor v(100);
 int valor;
 cout << "Inserindo 5 elementos no vetor" << endl;
 for (int i=0; i<5; i++) {
	cout << "Forneca valor inteiro v[" << i << "] = ";
	cin >> valor;
	v.inserir(valor);
 } 
 cout << "\nMostrando todos elementos do vetor" << endl; 
 v.mostrar();
 cout << "\nForneca um valor para busca: ";
 cin >> valor; 
 int encontrou = v.busca_linear(valor);
 if (encontrou == -1) {
 	cout << "Valor NAO encontrado" << endl; 
 }
 else {
 	cout << "Valor encontrada no indice " << encontrou << endl;
 }
 cout << "\nForneca um valor para remocao: "; 
 cin >> valor;
 v.remover(valor);
 cout << "\nMostrando todos elementos do vetor" << endl; 
 v.mostrar();
}

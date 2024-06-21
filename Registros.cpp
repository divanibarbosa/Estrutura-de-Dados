#include <iostream>
using namespace std;

typedef struct {
	char nome[80], dep[80];
	float sal;
} Funcionario;

main() {
	
  Funcionario reg[3];    
  
  cout << "Preencha a ficha cadastral de tres funcionarios:\n";
  for(int i=0; i<3; i++) {
	  cout << "Nome: ";
	  fflush(stdin);  gets(reg[i].nome);
	  cout << "Departamento: "; 
	  fflush(stdin);  gets(reg[i].dep);
	  cout << "Salario: ";      
	  cin >> reg[i].sal;   	
	  cout << "............................\n";
  } 
  
  for(int i=0; i<3; i++) {
	  cout << "\nImprimindo Conteudo:\n";
	  cout << "Nome: " << reg[i].nome << endl;
	  cout << "Departamento: " << reg[i].dep << endl;
	  cout << "Salario: " << reg[i].sal << endl;  	
  }
  
} 

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

/* A Hash oferece insercao, remocao e busca O(1) */

main() {
    unordered_map<string, string> hashTable; 
    // O primeiro tipo eh do valor chave (onde sera aplicada a funcao hash) <string>
	// O segundo tipo eh da informacao que deseja guardar <string>

    hashTable.insert({"Sao Paulo","Sao Paulo"});
    hashTable.insert({"Rio de Janeiro","Rio de Janeiro"});
    hashTable.insert({"Minas Gerais","Belo Horizonte"});
    hashTable.insert({"Santa Catarina","Florianopolis"});
    hashTable.insert({"Parana","Curitiba"});
    hashTable.insert({"Rio Grande do Norte","Natal"});  
    hashTable.insert({"Bahia","Salvador"});
    hashTable.insert({"Acre","Rio Branco"});
    hashTable.insert({"Alagoas","Maceio"});
    hashTable.insert({"Amapa","Macapa"});
    hashTable.insert({"Amazonas","Manaus"});
    hashTable.insert({"Ceara","Fortaleza"});
    hashTable.insert({"Distrito Federal","Brasilia"});
    hashTable.insert({"Espirito Santo","Vitoria"});
    hashTable.insert({"Goias","Goiania"});
    hashTable.insert({"Maranhao","Sao Luis"});
    hashTable.insert({"Mato Grosso","Cuiaba"});
    hashTable.insert({"Mato Grosso do Sul","Campo Grande"});
    hashTable.insert({"Para","Belem"});
    hashTable.insert({"Paraiba","Joao Pessoa"});
    hashTable.insert({"Pernambuco","Recife"});
    hashTable.insert({"Piaui","Teresina"});
    hashTable.insert({"Rio Grande do Sul","Porto Alegre"});
    hashTable.insert({"Rondonia","Porto Velho"});
    hashTable.insert({"Roraima","Boa Vista"});
    hashTable.insert({"Sergipe","Aracaju"});
    hashTable.insert({"Tocantins","Palmas"});
    //hashTable.erase("teste");
    
    char estado[1000];
    cout << "\nInforme o estado: ";
    gets(estado); 
    cout << "Capital: " << hashTable[estado];
    cout << endl << endl;
    system("pause");
    cout << endl;

    cout << "Imprimindo o conteudo da Tabela HASH com posicoes:\n\n";
    system("pause");
    cout << endl;
    for ( unsigned i = 0; i < hashTable.bucket_count(); ++i) {
       cout << " hashTable[" << i << "]";
       for ( auto local_it = hashTable.cbegin(i); local_it!= hashTable.cend(i); ++local_it )
           cout << " -> " << local_it->first << ": " << local_it->second;
       cout << endl;
    }

  cout << endl;
  system("pause");
}

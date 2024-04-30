#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* inicio = NULL;
NO* fim = NULL;

// headers
void menu();
void inicializar();
void insere();
void mostrarElementos();
void remove();
//--------------------------


int main() {
	menu();
}

void menu() {
	int op = 0;
	while (op != 5) {
		system("cls"); // somente no windows
		cout << "Menu Fila";
		cout << endl << endl;
		cout << "1 - Inicializar Fila \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Remover elemento  \n";
		cout << "4 - Mostrar Elementos  \n";
		cout << "5 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op) {
		case 1: inicializar();
			break;
		case 2:insere();
			break;
		case 3: remove();
			break;
		case 4: mostrarElementos();
			break;
		case 5:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar() {

	NO* aux = inicio;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	inicio = NULL;
	fim = NULL;
	cout << "Fila inicializada \n";

}


void insere() {

	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL) {
		cout << "Erro ao alocar memoria dinamicamente.";
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if(inicio == NULL) {//se a fila for nula, entao esta vazia
		inicio = novo;
		fim = novo;
	} else { //se a fila nao estiver vazia, nem for nula
		fim->prox = novo;
		fim = novo;
	}


}

void remove() {

	if(inicio == NULL) {
		cout << "A fila esta vazia! Nao ha elementos para remover." << endl;
		return;
	}

	cout << "O elemento removido foi: " << inicio->valor << endl;

	if(inicio == fim) {
		inicio = NULL;
		fim = NULL;
	} else {
		inicio = inicio->prox;
	}

}

void mostrarElementos(){

	 NO* aux = inicio; // ponteiro temporario para percorrer a pilha

    if(inicio == NULL){
        cout << "Pilha vazia!";
        return;
    }

    cout << "Elementos da Pilha: " << endl;
    while (aux != NULL){
        cout << aux-> valor << endl;
        aux = aux->prox;
    }
}


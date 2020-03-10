#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
	//declarar archivos
	char numeros[15];
	char operadores[5];
	int resultado;
	string entrada, salida, linea;
	cout << "Cual es tu archivo de entrada? ";
	cin >> entrada;
	cout << "Cual es tu archivo de salida? ";
	cin >> salida;
  //abrir archivos
	ifstream input(entrada + ".txt");
	ofstream output(salida + ".txt");
	
	//leer los numeros
	
	for (int i = 0; i < 10; i++) {
		char c;
		input >> c;
		numeros[i] = c;
	}
	// leer los  operadores

	for (int i = 0; i < 4; i++) {
		char c;
		input >> c;
		operadores[i] = c;
	}
  
	//lee linea por linea
	// comer el caracter \n
	input.get();
	while (getline(input, linea)) {
		// cout << linea << '\n';
	
		//se vuelve a declarar i para q se reinicie
		// i va a ser el indice de la linea
		int i = 0;

		// esto es para el primer numero dentro del parentesis
		output << '(';
		string num1 = "";
		int n1;
		while (linea[i] != ' ') {
			char c = linea[i]; 
			// cout << c << " ";
			for (int j = 0; j < 10; j++) {
				if (numeros[j] == c) {
					output << j;
          //se le suma 48 por el codigo ascii
					num1 += 48 + j;
					break;
				}
			}
			i++;
		}
		output << ") ";

		// aqui vamos a sacar el operador
		i++;
		char operador = linea[i];
		for (int j = 0; j < 4; j++) {
			if (operadores[j] == operador) {
				if (j == 0)	operador = '+';
				if (j == 1)	operador = '-';
				if (j == 2)	operador = '*';
				if (j == 3)	operador = '/';
				output << operador << " ";
			}
		}

		i++;
    
    output << '(';
		string num2 = "";
		int n2;
		while (i < linea.size()) {
			char c = linea[i]; 
			// cout << c << " ";
			for (int j = 0; j < 10; j++) {
				if (numeros[j] == c) {
					output << j;
          //le sumamos 48 por el codigo ascii
					num2 += 48 + j;
					break;
				}
			}
			i++;
		}

		// convertimos de string a int ambos numeros
		n1 = stoi(num1);
		n2 = stoi(num2);
		output << ") = ";
		
    //identificamos el operador e imprimimos segun su operacion
    // guarda el resultado en la variable resultado
		if (operador == '+') resultado = n1 + n2;
    if (operador == '-') resultado = n1 - n2;
    if (operador == '*') resultado = n1 * n2;
    if (operador == '/') resultado = n1 / n2;
		output << resultado << '\n';


	}
  input.close();
  output.close();
	return 0;
}
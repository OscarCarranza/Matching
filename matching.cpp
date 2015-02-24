
#include <iostream>
#include <cstdlib>
#include <vector> 
#include <cstring>
#include <iomanip>
#include <ctime>

using namespace std;

int main(int argc, char** argv){


int resp = 1;

while( resp == 1){

	cout << "\n\t MATCHING WORDS \n" << endl;
	cout << "Ingrese numero de respuestas: " ;
	int num_words;
	cin >> num_words;

	char a[20]; 
	char* answers[20];
	char w[20];
	char* words[20];

	for(int i = 0; i < num_words; i++){
		cout << "Palabra #" << i+1 << ": ";
		cin >> w;
		words[i] = new char[strlen(w)+1];
		strcpy(words[i],w);
	
		cout << "Descripción correspondiente a " << words[i] << ": ";
		cin >> a;
		answers[i] = new char[strlen(a)+1];
		strcpy(answers[i],a);
	}

	//shuffle
	char* shuffled[20];
	for(int i = 0; i < num_words; i++){
		shuffled[i] = new char[strlen(answers[i])];
	}

	srand(time(0));
	int nums[num_words]; 

	for(int i = 0; i < num_words; i++){
		nums[i] = 200;
	}

	for(int i = 0; i < num_words; i++){
		int r = rand() % num_words;

		for(int j = 0; j < num_words; j++){
			if(r == nums[j]){
				r = rand() % num_words;
				j=0;
			}
		}	
		nums[i] = r;
		strcpy(shuffled[i],answers[r]);
	}



	cout << "  Palabras" << setw(20) << "Respuestas" << endl;

	for(int i = 0; i < num_words; i++){
		cout << i+1 << ". " << words[i] << setw(15) 
		<< i+1 << ". " << shuffled[i] << endl;
	}

	// usuario comienza a jugar
	int correct = 0;
	for(int i = 0; i < num_words; i++){
		int pos;
		cout << "Posición " << i+1 << " encaja con posición: ";
		cin >> pos;
		cout << shuffled[pos-1] << endl;
		cout << answers[i] << endl;
		if (strcmp(shuffled[pos-1],answers[i]) == 0){
			correct++;
		}
		
	}

	cout << "Has acertado " << correct << "/" << num_words;


	for(int i = 0; i < num_words; i++){
		delete[] words[i];
		delete[] answers[i];
		delete[] shuffled[i];
	}

	cout << endl;
	cout << "Desea jugar de nuevo?[1.SI/2.NO]: ";
	cin >> resp;


	while(resp < 1 || resp > 2){
		cout << "Opción inválida!" << endl;
		cout << "Desea jugar de nuevo?[1.SI/2.NO]: ";
		cin >> resp;
	}

} // fin resp usuario

return 0;
}
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int menu();
//Provisionar la matriz de ints
int** provisionarMatriz(int);

//liberar memoria de la matriz
void liberarMatriz(int**&,int);

//imprimir la matriz
void printMatriz(int**,int);

//leer la matriz
int** readMatriz(int**,int);

//ejercicio1
void ejercicio1(int**, int);

//ejercicio2
bool ejercicio2(int);
void retorno(int);

//ejercicio3
void ejercicio3(string);

int main(){
	int opc =0;
	int size = 5;
	int** matriz = NULL;
	int num;
	do{
		switch(opc=menu()){
			
			case 1:
				matriz = provisionarMatriz(size);
				readMatriz(matriz, size);
				printMatriz(matriz, size);
				cout<<"Los puntos de silla son: "<<endl;
				ejercicio1(matriz, size);
				liberarMatriz(matriz, size);
				break;
				
			case 2:
				cout<<"Ingrese numero: ";
				cin>>num;
				if(ejercicio2(num)==true){
					cout<<"El numero es triangular"<<endl;
				}
				else{
					cout<<"El numero no es triangular"<<endl;
					retorno(num);
					cout<<" es el numero triangular mas cercano"<<endl;
				}
				break;
				
			case 3:
				break;
				
			case 4:
				break;
		}
	}while(opc!=4);
	return 0;
}

int menu(){
	int opc=0;
	while (true){
		cout<<"MENU"<<endl
			<<"1.-Ejercicio 1"<<endl
			<<"2.-Ejercicio 2"<<endl
			<<"3.-Ejercicio 3"<<endl
			<<"4.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=4){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}

int** provisionarMatriz(int size){
        int** matrix = new int* [size];
        for(int i=0; i<size; i++){
                matrix[i]=new int[size];
        }
        return matrix;
}

int** readMatriz(int** matriz, int size){
	int val;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<"Ingrese valor: ["<<i<<"]["<<j<<"]"<<endl;
			cin>>val;
			matriz[i][j]=val;
			//matriz[i][j] = (1+rand()%50);
		}
	}
	return matriz;
}

void liberarMatriz(int**& matrix, int size){
        for(int i=0;i<size;i++){
                if (matrix[i]!=NULL){
                         delete[]matrix[i];
                        matrix[i]=NULL;
                }
        }

        if(matrix!=NULL){
                delete[] matrix;
                matrix=NULL;
        }
}

void printMatriz(int** matriz, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
        	cout<<"["<<matriz[i][j]<<"]";
		}
		cout<<endl;
    }
}

void ejercicio1(int** matriz, int size){
	int cont=0;
	int maximom[size]={-65534,-65534,-65534,-65534,-65534};
	int minimom[size]={65534,65534,65534,65534,65534};
	for (int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(matriz[i][j]>maximom[i]){
				maximom[i]=matriz[i][j];
				//cout<<"Max: "<<maximom[i]<<endl;
			}
			if(matriz[i][j]<minimom[j]){
				minimom[j]=matriz[i][j];
				//cout<<"Min: "<<minimom[i]<<endl;
			}
		}
	}
	cout<<endl;
	cout<<endl;
	for(int j=0;j<5;j++){
		cout<<"Max: "<<maximom[j]<<endl;
	}
	cout<<endl;
	for(int j=0;j<5;j++){
		cout<<"Min: "<<minimom[j]<<endl;
	}
	
	for (int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			//cout<<1<<endl;
			if(maximom[i]==minimom[j]){
				//cout<<2<<endl;
				cout<<"Punto en: ["<<i<<"],["<<j<<"]"<<maximom[i]<<endl;
				//cout<<3<<endl;
				cont++;
			}
		}
	}
	cout<<"Hay en total: "<<cont<<endl;
	if(cont==0){
		cout<<"No hay puntos"<<endl;
	}
}

bool ejercicio2(int x){
	bool ret = false;
	int j,num,cont=0, past;
	for(j=1 ; j<=x ; j++){
		num=(j*(j+1))/2;
		//cout<<num<<endl;
		if(num==x){
			ret = true;
		}
		if(num<x){
			past = num;
		}
		if(cont==x){
			ret = false;
		}
		cont++;
	}
	return ret;
}

void retorno(int x){
	int j,num,cont=0, past;
	for(j=1 ; j<=x ; j++){
		num=(j*(j+1))/2;
		if(num<x){
			past = num;
		}
		cont++;
	}
	cout<<past;
}


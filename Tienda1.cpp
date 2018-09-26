#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;
const int N = 5;
void menu ();
void showData ();
void showDataBuy ();
int findEmptyPlace ();
int findEmptyPlaceBuy ();
int searchSong (int b);
int searchSongBuy (int a);
int removeCredit (int c, int p);
struct files{
	double price;
	int availableProducts;
};
struct music{
	int track;
	char name[15];
	char author[15];
	char genre[15];
	int year;
	struct files file;
};
struct music song [N];
struct filesBuy{
	double priceBuy;
	int availableProductsBuy;
};
struct musicBuy{
	int trackBuy;
	char nameBuy[15];
	char authorBuy[15];
	char genreBuy[15];
	int yearBuy;
	struct filesBuy fileBuy;
};
struct musicBuy songBuy [10];
int main(){
    double credit = 150;
	int option;
	do{
            system("cls");
		menu();
		cin >> option;
		switch(option){
			case 1:
                system("cls");
                cout << endl;
                for(int i=1; i<N; i++){
                    cout << "Track:    ";
                    cin >> song[i].track;
                    cout << endl;
					cout << "Name:     ";
					cin.ignore();
					cin.getline(song[i].name,15,'\n');
					cout << endl;
					cout << "Author:   ";
					cin.getline(song[i].author,15,'\n');
					cout << endl;
					cout << "Genre:    ";
					cin.getline(song[i].genre,15,'\n');
					cout << endl;
					cout << "Year:     ";
					cin >> song[i].year;
					cout << endl;
					cout << "Price:    ";
					cin >> song[i].file.price;
					cout << endl;
					cout << "Products: ";
					cin >> song[i].file.availableProducts;
					cout << endl;
					system("cls");
					showData();
					cout << endl;
					system("pause");
				}
				break;
			case 2:
			    system("cls");
                int optionKey, emptyPlace;
                showData();
                cout << endl;
                cout << "inserte clave de la cancion a comprar: ";
                cin >> optionKey;
                emptyPlace = searchSong(optionKey);
                cout << "posicion de la cancion: " << emptyPlace << endl;
                if(emptyPlace == -1){
                    cout << " No Encontrado " << endl;
                }else{
                    if(song[emptyPlace].file.availableProducts <= 0){
                        cout << "sin canciones disponibles " << endl;
                    }else if (searchSongBuy(optionKey) != -1){
                        cout << "ya tienes comprada esta cancion" << endl;
                        system("pause");
                    }else{
                        if ((credit - song[emptyPlace].file.price) < 0){
                            cout << "sin credito disponible " << endl;
                        }else{
                            int place;
                            place = findEmptyPlaceBuy();
                            songBuy[place].trackBuy = song[emptyPlace].track;
                            strcpy(songBuy[place].nameBuy , song[emptyPlace].name);
                            strcpy(songBuy[place].authorBuy , song[emptyPlace].author);
                            strcpy(songBuy[place].genreBuy , song[emptyPlace].genre);
                            songBuy[place].yearBuy = song[emptyPlace].year;
							credit = credit - song[emptyPlace].file.price;
							song[emptyPlace].file.availableProducts = (song[emptyPlace].file.availableProducts) - (1);
                        }
                    }
                }
				break;
			case 3:
				system("cls");
				showData();
				cout << endl;
				system("pause");
				break;
			case 4:
				system("cls");
				showDataBuy();
				cout << endl;
				system("pause");
				break;
			case 5:
			    system("cls");
				cout << "Credit:   " << credit << endl;
				system("pause");
				break;
			case 6:
				break;
			default:
				break;
		}
	}while(option != 6);
	return 0;
}//fin de main()
void menu(){
	cout << "   INICIO " << endl;
	cout << "1.-Agregar canciones" << endl;
	cout << "2.-Comprar canciones" << endl;
	cout << "3.-ver canciones " << endl;
	cout << "4.-cer canciones compradas" << endl;
	cout << "5.-consultar Credito " << endl;
	cout << "6.-salir" << endl;
	cout << "inserta tu opcion: " ;
}
void showData(){
    cout << endl;
    cout << setw(6) << "TRACK"
            << setw(20) << "NAME"
            << setw(20) << "AUTHOR"
            << setw(15) << "GENRE"
            << setw(15) << "YEAR"
            << setw(15) << "PRICE"
            << setw(15) << "PRODUCTS" << endl;
    for(int i=1; i<N; i++){
        if(song[i].file.availableProducts != 0){
            cout << setw(6) << song[i].track
                    << setw(20) << song[i].name
                    << setw(20) << song[i].author
                    << setw(15) << song[i].genre
                    << setw(15) << song[i].year
                    << setw(15) << song[i].file.price
                    << setw(15) << song[i].file.availableProducts << endl;
        }
    }
}
int findEmptyPlace (){
	for (int i = 1; i <= 10; i++) {
        if (song[i].file.availableProducts == 0) {
            return i;
        }
    }
    return -1;
}
int searchSong(int b){
	for(int i=1; i<=10; i++){
		if(song[i].track == b){
			return i;
		}
	}
	return -1;
}
void showDataBuy(){
    cout << endl;
    cout << setw(6) << "TRACK"
            << setw(20) << "NAME"
            << setw(20) << "AUTHOR"
            << setw(15) << "GENRE"
            << setw(15) << "YEAR"
            << setw(15) << "STATUS" << endl;
    for(int i=1; i<=10; i++){
        if(songBuy[i].trackBuy != 0){
            cout << setw(6) << songBuy[i].trackBuy
                    << setw(20) << songBuy[i].nameBuy
                    << setw(20) << songBuy[i].authorBuy
                    << setw(15) << songBuy[i].genreBuy
                    << setw(15) << songBuy[i].yearBuy
                    << setw(15) << "Bought" << endl;
        }
    }
}
int findEmptyPlaceBuy (){
	for (int i = 1; i < 100; i++) {
        if (songBuy[i].fileBuy.availableProductsBuy == 0) {
            return i;
        }
    }
    return -1;
}
int searchSongBuy(int a){
	for(int i=1; i<=10; i++){
		if(songBuy[i].trackBuy == a){
			return i;
		}
	}
	return -1;
}


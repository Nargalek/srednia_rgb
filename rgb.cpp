#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

struct rgb {
	int r;
	int g;
	int b;
};



bool wczytaj(string, vector<rgb>&);
void generuj(vector<rgb>&);
int w,k,wiel,wyn;

int main(){
	vector<rgb> tab;	
	bool otwarty=wczytaj("dane.txt", tab);
	
	if(otwarty)
	{
		cout<<"Zapisuje plik.";
		generuj(tab);
		cout<<"\n";
	}else cout<<"Nie otwarto"<<endl;
	
	
	
	
	cout<<"\n\n\n";
	system("PAUSE");
	return 0;
}

bool wczytaj(string nazwa_pliku, vector<rgb> &tab){
		
	ifstream dane;
	dane.open(nazwa_pliku.c_str());
	 
	if(dane.good() == true){
	 dane.ignore(6);
	 dane>>w>>k;
	 wiel=w*k/3;
	 for(int i=0;i<wiel;i++){
	 		tab.push_back(rgb());
	 		dane>>tab[i].r>>tab[i].b>>tab[i].g;
		 }
	 }
	else return false;
	
	dane.close();
	return true;
	
}

void generuj(vector<rgb> &tab){
		ofstream wynik;
  		wynik.open("RGB.txt");
  		if(wynik.good() == true){
		for(int i=0; i<wiel;i++){
				wyn=(tab[i].r+tab[i].g+tab[i].b)/3;
				wynik<<wyn<<" ";
				if((i+1)%(k/3) == 0)wynik<<"\n";	
		}
		wynik.close();	
		} else cout<<"Nie zapisano!";
			
		
}






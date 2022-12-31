#include <iostream>
#include <vector>
using namespace std;

string cesarSifrele(string sifre){//bu fonksiyon 2 parametre alıcak biri string biri int. int deger 2 olsun ornegin
                                        //sifre ahmet olsun int deger 2 deger olursa a alfabede kendinden 2 sonraki harfle degistirilir
    int i = 0;
    char cr;
    string kriptoSifre;
    while(i != sifre.length()){
        cr = sifre.at(i);
        cr += 2;
        kriptoSifre += cr;
        i++;
    }

    return kriptoSifre;
}

string sifreyiDonustur(string kriptoSifre){
    int i = 0;
    char cr;
    string sifre;
    while(cr = sifre.at(i) == '\0'){
        cr -= 2;
        sifre += cr;
        i++;
    }

    return sifre;
}

class kisi{
    string ad;
    string soyad;
    string kriptoSifre;

public:
    kisi(){}
    kisi(string ad,string soyad,string kriptoSifre){
        this->ad = ad;
        this->kriptoSifre = kriptoSifre;
        this->soyad = soyad;
    }

    friend void uyeOl(vector<kisi>&);
    friend bool girisYap(vector<kisi>&);
    friend ostream &operator<<(ostream &out,kisi &k); 

};
ostream &operator<<(ostream &out,kisi &k){
    out<<"ad : "<<k.ad<<endl<<"soyad : "<<k.soyad<<endl<<"kripto sifre : "<<k.kriptoSifre<<endl;
    return out;
}
//uye olma fonku
void uyeOl(vector<kisi>& v){
                               
    cout<<"adinizi giriniz : ";
    string ad;
    cin>>ad;
    cout<<endl<<"soyadinizi giriniz : ";
    string soyad;
    cin>>soyad;
    cout<<endl<<"sifrenizi giriniz : ";
    string sifre;
    cin>>sifre;
    cout<<endl;
    sifre = cesarSifrele(sifre);

    kisi yenikisi(ad,soyad,sifre);
    v.push_back(yenikisi);

}

bool girisYap(vector<kisi> &v){
    cout<<"adinizi giriniz : ";
    string ad;
    cin>>ad;
    cout<<endl<<"soyadinizi giriniz : ";
    string soyad;
    cin>>soyad;
    

    //vector<kisi>::iterator it;
    
    for(auto it = v.begin(); it != v.end(); it++ ){
        if((*it).ad == ad && (*it).soyad == soyad){
            try
            {
                cout<<"kullanici bulundu..."<<endl;
                cout<<"lutfen sifrenizi giriniz : ";
                string girilenSifre;
                cin>>girilenSifre;
                girilenSifre = cesarSifrele(girilenSifre);
                string hesapSifresi = (*it).kriptoSifre;
                if(girilenSifre == hesapSifresi){
                    cout<<"giris basarili..."<<endl;
                    return true;
                }
                else throw 0;
            }
            catch(...)
            {
                
                    cout<<"sifre yanlis"<<endl;
                    return false;
                

            }
            
            
          
        }
    }

    cout<<"kullanici bulunamadi..."<<endl;
    return false;
    


    

}








int main(){
    vector <kisi> kisiler;
while(true){
    cout<<"kayit sistemine hosgeldiniz...."<<endl;
    cout<<"_______________________________"<<endl;
    cout<<"isleminizi seciniz : "<<endl<<"1 - uye ol"<<endl<<"2 - profil goruntule"<<endl;
    
    int secim;
    cin>>secim;


    switch(secim){
        case 1:uyeOl(kisiler);break;
        case 2:girisYap(kisiler);break;
    }

}

    
    
    return 0;
}
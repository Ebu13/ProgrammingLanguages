#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Kullanýcýdan dosya adýný al
    string dosyaAdi;
    cout << "Lutfen dosya adini girin: ";
    cin >> dosyaAdi;

    // Dosyayý aç
    ifstream dosya(dosyaAdi.c_str());
    if (!dosya) {
        cerr << "Dosya acilamadi!\n";
        return 1;
    }

    // Dosyayý oku
    string satir;
    bool ilkSinif = true;
    while (getline(dosya, satir)) {
        // Sýnýf baþlangýcý bulundu mu?
        if (satir.find("class") != string::npos) {
            // Ýlk sýnýf deðilse, bir satýr boþluk yazdýr
            if (!ilkSinif) {
                cout << endl;
            } else {
                ilkSinif = false;
            }

            // Sýnýf adýný al
            string sinifAdi = satir.substr(satir.find("class") + 6);
            sinifAdi = sinifAdi.substr(0, sinifAdi.find("{"));
            cout << "Sinif adi: " << sinifAdi << endl;

            // Sýnýfýn özelliklerini ve metodlarýný bul
            while (getline(dosya, satir)) {
                if (satir.find("private:") != string::npos || satir.find("public:") != string::npos) {
                    continue; // Sadece özellik ve metodlarýn bulunduðu bölüme git
                } else if (satir.find("};") != string::npos) {
                    break; // Sýnýf sonu
                } else if (satir.find("(") != string::npos) {
                    // Bu bir metot tanýmý
                    string metotAdi = satir.substr(0, satir.find("("));
                    metotAdi = metotAdi.substr(metotAdi.rfind(" ") + 1);
                    cout << "Metot adi: " << metotAdi << endl;
                } else if (satir.find(";") != string::npos) {
                    // Bu bir özellik tanýmý
                    string ozellikAdi = satir.substr(0, satir.find(";"));
                    ozellikAdi = ozellikAdi.substr(ozellikAdi.rfind(" ") + 1);
                    cout << "Ozellik adi: " << ozellikAdi << endl;
                }
            }
        }
    }

    // Dosyayý kapat
    dosya.close();

    return 0;
}


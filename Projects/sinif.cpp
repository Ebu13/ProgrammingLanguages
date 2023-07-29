#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Kullan�c�dan dosya ad�n� al
    string dosyaAdi;
    cout << "Lutfen dosya adini girin: ";
    cin >> dosyaAdi;

    // Dosyay� a�
    ifstream dosya(dosyaAdi.c_str());
    if (!dosya) {
        cerr << "Dosya acilamadi!\n";
        return 1;
    }

    // Dosyay� oku
    string satir;
    bool ilkSinif = true;
    while (getline(dosya, satir)) {
        // S�n�f ba�lang�c� bulundu mu?
        if (satir.find("class") != string::npos) {
            // �lk s�n�f de�ilse, bir sat�r bo�luk yazd�r
            if (!ilkSinif) {
                cout << endl;
            } else {
                ilkSinif = false;
            }

            // S�n�f ad�n� al
            string sinifAdi = satir.substr(satir.find("class") + 6);
            sinifAdi = sinifAdi.substr(0, sinifAdi.find("{"));
            cout << "Sinif adi: " << sinifAdi << endl;

            // S�n�f�n �zelliklerini ve metodlar�n� bul
            while (getline(dosya, satir)) {
                if (satir.find("private:") != string::npos || satir.find("public:") != string::npos) {
                    continue; // Sadece �zellik ve metodlar�n bulundu�u b�l�me git
                } else if (satir.find("};") != string::npos) {
                    break; // S�n�f sonu
                } else if (satir.find("(") != string::npos) {
                    // Bu bir metot tan�m�
                    string metotAdi = satir.substr(0, satir.find("("));
                    metotAdi = metotAdi.substr(metotAdi.rfind(" ") + 1);
                    cout << "Metot adi: " << metotAdi << endl;
                } else if (satir.find(";") != string::npos) {
                    // Bu bir �zellik tan�m�
                    string ozellikAdi = satir.substr(0, satir.find(";"));
                    ozellikAdi = ozellikAdi.substr(ozellikAdi.rfind(" ") + 1);
                    cout << "Ozellik adi: " << ozellikAdi << endl;
                }
            }
        }
    }

    // Dosyay� kapat
    dosya.close();

    return 0;
}


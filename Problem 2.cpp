#include <iostream>
using namespace std;

int nilaiHuruf(char huruf) {
    return huruf - 'A' + 1;
}

char ubahHuruf(int nilai) {
    return 'A' + nilai - 1;
}

int main() {
    char pesan[100];

    cout << "Masukkan pesan: ";
    cin >> pesan;

    cout << "Hasil enkripsi: ";
    cout << pesan[0];

    int i = 1;

    while (pesan[i] != '\0') {

        int nilaiSekarang = nilaiHuruf(pesan[i]);
        int nilaiSebelumnya = nilaiHuruf(pesan[i - 1]);

        int hasil = nilaiSekarang + nilaiSebelumnya;

        if (hasil > 26) {
            hasil = hasil - 26;
        }

        char hurufHasil = ubahHuruf(hasil);

        cout << hurufHasil;

        i++;
    }

    cout << endl;

    return 0;
}
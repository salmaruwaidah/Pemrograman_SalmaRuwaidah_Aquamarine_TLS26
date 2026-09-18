#include <iostream>
using namespace std;

void isiAstronaut(int astronaut[], int N) {
    for (int i = 0; i < N; i++) {
        astronaut[i] = i + 1;
    }
}

int tentukanPosisi(int posisi, int K, int jumlah) {
    return (posisi + K - 1) % jumlah;
}

void hapusAstronaut(int astronaut[], int posisi, int jumlah) {
    for (int i = posisi; i < jumlah - 1; i++) {
        astronaut[i] = astronaut[i + 1];
    }
}

int ubahK(int K, int astronaut_dihapus) {
    if (astronaut_dihapus % 2 == 0) {
        K = K + 2;
    }
    else {
        K = K - 1;

        if (K < 2) {
            K = 2;
        }
    }

    return K;
}

int main() {
    int N, K;

    cout << "Masukkan jumlah astronaut: ";
    cin >> N;

    cout << "Masukkan nilai K: ";
    cin >> K;

    int* astronaut = new int[N];

    isiAstronaut(astronaut, N);

    int jumlah = N;
    int posisi = 0;

    cout << "Urutan astronaut yang dieliminasi: ";

    while (jumlah > 1) {

        posisi = tentukanPosisi(posisi, K, jumlah);

        int astronaut_dihapus = astronaut[posisi];

        cout << astronaut_dihapus << " ";

        hapusAstronaut(astronaut, posisi, jumlah);

        jumlah--;

        K = ubahK(K, astronaut_dihapus);
    }

    cout << endl;
    cout << "Astronaut terakhir yang bertahan: " << astronaut[0] << endl;

    delete[] astronaut;

    return 0;
}
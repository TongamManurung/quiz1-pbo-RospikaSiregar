#include <stdio.h>

int main() {
    int N;
    int nilai[100];
    char kelompok[100];
    char cariKelompok;
    int total = 0;

    
    printf("Masukkan jumlah data siswa: ");
    scanf("%d", &N);

    
    for (int i = 0; i < N; i++) {
        printf("Data siswa ke-%d\n", i + 1);
        printf("Nilai: ");
        scanf("%d", &nilai[i]);
        printf("Kode kelompok (A/B/C): ");
        scanf(" %c", &kelompok[i]);
    }

   
    printf("\nMasukkan kode kelompok yang ingin dihitung total nilainya: ");
    scanf(" %c", &cariKelompok);

    
    for (int i = 0; i < N; i++) {
        if (kelompok[i] == cariKelompok) {
            total += nilai[i];
        }
    }

   
    printf("\nTotal nilai untuk kelompok %c adalah: %d\n", cariKelompok, total);

    return 0;
}


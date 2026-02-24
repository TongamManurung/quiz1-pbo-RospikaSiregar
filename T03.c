#include <stdio.h>
#include <string.h>


struct Member {
    char nim[15];
    char nama[50];
    int poin;
};


int hitungPoinBaru(float berat) {
    return (int)berat * 10;
}

int main() {
    struct Member m1;
    float berat;
    int pilihanPakePoin;

    printf("=== SISTEM LOYALITAS LAUNDRY DEL ===\n");
    
    
    printf("Masukkan NIM Mahasiswa : ");
    scanf("%s", m1.nim);
    printf("Masukkan Nama          : ");
    scanf(" %[^\n]s", m1.nama);
    
    
    m1.poin = 45; 

    printf("\n--- Status Member ---\n");
    printf("Nama: %s | Poin Saat Ini: %d\n", m1.nama, m1.poin);

    printf("\nMasukkan Berat Cucian (kg): ");
    scanf("%f", &berat);

    
    int poinBaru = hitungPoinBaru(berat);
    m1.poin += poinBaru;

    printf("Selamat! Anda mendapatkan %d poin baru.\n", poinBaru);
    printf("Total poin Anda sekarang: %d\n", m1.poin);

    
    if (m1.poin >= 50) {
        printf("\n[PROMO] Poin Anda cukup untuk diskon Rp 5.000!\n");
        printf("Gunakan poin sekarang? (1: Ya, 0: Tidak): ");
        scanf("%d", &pilihanPakePoin);

        if (pilihanPakePoin == 1) {
            m1.poin -= 50; 
            printf("Diskon diterapkan. Sisa poin Anda: %d\n", m1.poin);
        }
    }

    printf("\n--- Transaksi Selesai ---\n");
    printf("Terima kasih, %s. Semangat kuliahnya di Del!\n", m1.nama);

    return 0;
}
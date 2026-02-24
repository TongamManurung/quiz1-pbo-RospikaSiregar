#include <stdio.h>
#include <string.h>


typedef struct {
    char kode[5];
    char nama[30];
    int harga;
} Menu;


typedef struct {
    char nama[30];
    int porsi;
    int harga;
    int total;
} Pesanan;

int main() {
    
    Menu katalog[] = {
        {"NGS", "Nasi Goreng Spesial", 15000},
        {"AP",  "Ayam Penyet", 20000},
        {"SA",  "Sate Ayam (10 Tusuk)", 25000},
        {"BU",  "Bakso Urat", 18000},
        {"MAP", "Mie Ayam Pangsit", 15000},
        {"GG",  "Gado-Gado", 15000},
        {"SAM", "Soto Ayam", 17000},
        {"RD",  "Rendang Daging", 25000},
        {"IB",  "Ikan Bakar", 35000},
        {"NUK", "Nasi Uduk Komplit", 20000}
    };
    int jumlah_menu = 10;

    Pesanan daftar_pesanan[50]; 
    int jumlah_pesanan = 0;
    int total_pembayaran = 0;
    
    char input_kode[10];
    int input_porsi;

    printf("Masukkan kode menu dan porsi (Ketik END untuk selesai):\n");

    
    while (1) {
        scanf("%s", input_kode);
        
        
        if (strcmp(input_kode, "END") == 0) {
            break;
        }

        
        int ditemukan = 0;
        for (int i = 0; i < jumlah_menu; i++) {
            if (strcmp(input_kode, katalog[i].kode) == 0) {
                scanf("%d", &input_porsi);
                
                
                strcpy(daftar_pesanan[jumlah_pesanan].nama, katalog[i].nama);
                daftar_pesanan[jumlah_pesanan].porsi = input_porsi;
                daftar_pesanan[jumlah_pesanan].harga = katalog[i].harga;
                daftar_pesanan[jumlah_pesanan].total = input_porsi * katalog[i].harga;
                
                total_pembayaran += daftar_pesanan[jumlah_pesanan].total;
                jumlah_pesanan++;
                ditemukan = 1;
                break;
            }
        }
        
        if (!ditemukan) {
            printf("Kode '%s' tidak ditemukan!\n", input_kode);
        }
    }

  
    printf("\n\n");
    printf("%-25s %-7s %-10s %-10s\n", "Menu", "Porsi", "Harga", "Total");
    printf("========================================================\n");
    
    for (int i = 0; i < jumlah_pesanan; i++) {
        printf("%-25s %-7d %-10d %-10d\n", 
               daftar_pesanan[i].nama, 
               daftar_pesanan[i].porsi, 
               daftar_pesanan[i].harga, 
               daftar_pesanan[i].total);
    }
    
    printf("========================================================\n");
    printf("%-44s %-10d\n", "Total Pembayaran", total_pembayaran);

    return 0;
}
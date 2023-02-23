/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getImage(int img[50][50], int *M, int *N, int *err)
{
   //Implementasi ambil matriks gambar dari file txt
   //MxN adalah BarisxKolom matrix img dan err adalah variable menyatakan file tidak ditemukan 
   printf("Masukkan nama file gambar: ");
   //Ambil file gambar dari user

   //Jika file tidak ditemukan
   printf("Hayo gambar apatuh yang dibuka, kok ga bisa");
}

void getKernel(int kernel[3][3])
{
    //Implementasi mengambil matriks kernel 3x3 dari user

}

void conv_2D(int kernel[3][3], int img[50][50], int hasil[50][50], int M, int N)
{
    //Impementasi konvolusi 2D M adalah jumlah baris dan N adalah jumlah kolom img
}

void printMatrix(...)
{
    //Mencetak matrix ke layar
    for ()
    {
        for ()
        {
            printf("%d\t", //matrix[i,j]);
        }
        printf("\n");
    }
}

int main()
{
    // Declare Variables
    // Dimensi Gambar
    int M, N, err;

    // Matrix Gambar, Hasil, Kernel
    int img[50][50];
    int hasil[50][50];
    int kernel[3][3];

    // Ambil Isi Kernel
    printf("Masukkan Kernel:\n");
    getKernel(kernel);

    // Masukkan File Gambar
    getImage(...);
    if (!err)
    {
        // Cetak Gambar Asli
        printf("Gambar Asli:\n");
        printMatrix(...);
        conv_2D(...);

        // Cetak Gambar Hasil Konvolusi
        printf("Gambar Hasil Konvolusi:\n");
        printMatrix(...);
    }

    return 0;
}

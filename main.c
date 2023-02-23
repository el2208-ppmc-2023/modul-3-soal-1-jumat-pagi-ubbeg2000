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
    char str[1000], fileName[20];
    FILE *fptr;
    printf("Masukkan nama file gambar: ");
    scanf("%s", fileName);
    if ((fptr = fopen(fileName, "r")) == NULL)
    {
        // Gambar gagal dibuka
        printf("Hayo gambar apatuh yang dibuka, kok ga bisa");
        *err = 1;
    }
    else
    {
        *err = 0;
        int i = -1;
        int j = 0;
        while (fgets(str, sizeof(str), fptr) != NULL)
        {
            char *token = strtok(str, ",");
            while (token != NULL)
            {
                if (i < 0)
                {
                    *M = atoi(token);
                    token = strtok(NULL, ",");
                    *N = atoi(token);
                    token = strtok(NULL, ",");
                }
                else
                {
                    *(*(img + i) + j) = atoi(token);
                    token = strtok(NULL, ",");
                    j++;
                }
            }
            i++;
            j = 0;
        }
    }
    fclose(fptr);
}

void getKernel(int kernel[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d %d", (*(kernel + i) + 0), (*(kernel + i) + 1), (*(kernel + i) + 2));
    }
}

void conv_2D(int kernel[3][3], int img[50][50], int hasil[50][50], int M, int N)
{
    for (int m = 0; m < M; m++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if ((m - k) >= 0 || n - l >= 0)
                    {
                        *(*(hasil + m) + n) += *(*(kernel + (k + 1)) + (l + 1)) * (*(*(img + (m - k)) + n - l));
                    }
                }
            }
        }
    }
}

void printMatrix(int matrix[50][50], int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", *(*(matrix + i) + j));
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
    getImage(img, &M, &N, &err);
    if (!err)
    {
        // Cetak Gambar Asli
        printf("Gambar Asli:\n");
        printMatrix(img, M, N);
        conv_2D(kernel, img, hasil, M, N);

        // Cetak Gambar Hasil Konvolusi
        printf("Gambar Hasil Konvolusi:\n");
        printMatrix(hasil, M, N);
    }

    return 0;
}

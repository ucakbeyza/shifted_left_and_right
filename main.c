#include <stdio.h>

void bitKontrol(int number) {
    int sayiKaydir;
    if ((number >> 4) & 1) {
        // 5. bit 1 ise sağa kaydır
        sayiKaydir = number >> 1;
        printf("5. bit 1 olduğu için %d sayısı 1 sağa kaydırıldı: %d\n", number, sayiKaydir);
    } else {
        // 5. bit 0 ise sola kaydır
        sayiKaydir = number << 1;
        printf("5. bit 0 olduğu için %d sayısı 1 sola kaydırıldı: %d\n", number, sayiKaydir);
    }


    FILE *file = fopen("sayi.txt", "a");
    if (file == NULL) {
        printf("Dosya oluşturulamadı veya açılamadı.");
        return;
    }
    fprintf(file, "%d\n", sayiKaydir);
    fclose(file);
}

int main() {
    int number;

    printf("Bir sayı girin: ");
    scanf("%d", &number);

    bitKontrol(number);

    printf("İşlem tamamlandı. Dosyaya ve çıktıya yazıldı: sayi.txt\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct LL {
    int value;
    struct LL* next;
};

struct ARR {
    int value;
};

void computeFreqInList(struct LL* head) {
    // Bağlı listedeki değerlerin tekrar sayısını hesaplar ve yazdırır.
    struct LL* curr = head;
    int freq[100] = {0}; // Varsayımsal olarak 0-99 arasında değerler var.

    while (curr != NULL) {
        freq[curr->value]++;
        curr = curr->next;
    }

    // Sıklıkları azalan sırada yazdırır
    for (int i = 99; i >= 0; i--) {
        if (freq[i] > 0) {
            printf("%d %d\n", i, freq[i]);
        }
    }
}

void computeFreqInArr(struct ARR arr[], int size) {
    // Dizi içindeki değerlerin tekrar sayısını hesaplar ve yazdırır.
    int freq[100] = {0}; // Varsayımsal olarak 0-99 arasında değerler var.
    int i = 0;

    while (i < size) {
        freq[arr[i].value]++;
        i++;
    }

    // Sıklıkları azalan sırada yazdırır
    for (int i = 99; i >= 0; i--) {
        if (freq[i] > 0) {
            printf("%d %d\n", i, freq[i]);
        }
    }
}

int main(void) {
    // Test için örnekler eklenebilir
}

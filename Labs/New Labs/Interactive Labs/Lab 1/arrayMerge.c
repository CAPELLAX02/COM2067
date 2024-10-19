#include <stdio.h>

// Iki sirali diziyi birlestirme fonksiyonu
void merge(int* nums1, int m, int* nums2, int n) {
    int i = m - 1;  // nums1'in son geçerli elemaninin indeksi
    int j = n - 1;  // nums2'nin son elemaninin indeksi
    int k = m + n - 1;  // nums1'in son elemaninin bulundugu yer (yer tutucu)

    // nums1 ve nums2'yi sondan basa dogru birlestir
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            k--;
            i--;
            
        } else {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }

    // nums2'de kalan elemanlar varsa, onlari nums1'e kopyala
    while (j >= 0) {
        nums1[k] = nums2[j];
        k--;
        j--;
    }
}

int main() {
    int nums1[6] = {1, 2, 3, 0, 0, 0};  // nums1'in ilk 3 elemani geçerli
    int nums2[3] = {2, 5, 6};  // nums2 dizisi

    int m = 3;  // nums1'deki geçerli eleman sayisi
    int n = 3;  // nums2'deki eleman sayisi

    merge(nums1, m, nums2, n);

    // Birlestirilen nums1 dizisini yazdir
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;

    // OUTPUT: 1 2 2 3 5 6
}

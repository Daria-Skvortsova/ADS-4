// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int otvet = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) {
                otvet++;
            }
        }
    }
    return otvet;
}
int countPairs2(int* arr, int len, int value) {
    int left = len;
    int proverka = 0;
    while (arr[left] > value) {
        left--;
    }
    int otvet = 0;
    for (int right = 0; right < left; right++) {
        for (int j = right + 1; j < left; j++) {
            if ((arr[right] + arr[j]) == value) {
                otvet++;
            }
        }
        left--;
    }
    return otvet;
}
int cbinsearch(int* arr, int size, int value) {
    int otvet, ceredina;
    int granica_1 = 0;
    int granica_2 = size - 1;
    otvet = 0;
    while (granica_1 <= granica_2) {
        ceredina = granica_1 + ((granica_2 - granica_1) / 2);
        otvet = 0;
        if (arr[ceredina] == value) {
            for (int i = 0; arr[ceredina + i] == value; i++) {
                otvet++;
                if ((ceredina + i) == granica_2) {
                    break;
                }
            }
            for (int i = 1; arr[ceredina - i] == value; i++) {
                otvet++;
                if (ceredina - i == 0) {
                    break;
                }
            }
            break;
        } else if (arr[ceredina] > value) {
            granica_2 = ceredina - 1;
          } else {
              granica_1 = ceredina + 1;
            }
    }
    if (otvet == 0) {
        return 0;
    } else {
        return otvet;
      }
}
int countPairs3(int* arr, int len, int value) {
    int otvet = 0;
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[len - 1] > value) {
            len--;
        }
        int proverka = value - arr[i];
        if ((arr[i] == (value / 2)) && ((value % 2) == 0)) {
            count = cbinsearch(&arr[i], len - i, value / 2);
            int n = count * (1 + count) / 2;
            otvet += n - count;
            break;
        } else {
            otvet = otvet + cbinsearch(&arr[i + 1], len - i, proverka);
          }
        if (proverka < 0) {
            break;
        }
    }
    if ((value % 2) == 0) {
        return otvet;
    } else {
        return otvet;
      }
}

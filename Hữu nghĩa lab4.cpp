#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

// Hàm tính trung bình cộng của mảng số dương và số âm
void calculateAverage(int arr[], int n) {
    int positiveSum = 0, positiveCount = 0;
    int negativeSum = 0, negativeCount = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            positiveSum += arr[i];
            positiveCount++;
        } else if (arr[i] < 0) {
            negativeSum += arr[i];
            negativeCount++;
        }
    }

    if (positiveCount > 0) {
        double positiveAverage = static_cast<double>(positiveSum) / positiveCount;
        cout << "Trung binh cong cua cac so duong: " << positiveAverage << endl;
    } else {
        cout << "Khong co so duong trong mang." << endl;
    }

    if (negativeCount > 0) {
        double negativeAverage = static_cast<double>(negativeSum) / negativeCount;
        cout << "Trung binh cong cua cac so am: " << negativeAverage << endl;
    } else {
        cout << "Khong co so am trong mang." << endl;
    }
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Hàm in ra các số nguyên tố trong mảng
void printPrimes(int arr[], int n) {
    cout << "Cac so nguyen to trong mang: ";
    for (int i = 0; i < n; ++i) {
        if (isPrime(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// Hàm sắp xếp mảng chẵn theo thứ tự tăng dần
void sortEven(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] % 2 == 0 && arr[j] % 2 == 0 && arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm xóa phần tử x khỏi mảng
int removeElement(int arr[], int &n, int x) {
    int newSize = n;
    for (int i = 0; i < newSize; ++i) {
        if (arr[i] == x) {
            for (int j = i; j < newSize - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            newSize--;
            i--;
        }
    }
    return newSize;
}

// Hàm chèn x vào mảng sao cho mảng vẫn giữa nguyên tính thứ tự
void insertAndMaintainOrder(int arr[], int &n, int x) {
    int insertPos = n;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > x) {
            insertPos = i;
            break;
        }
    }
    for (int i = n; i > insertPos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[insertPos] = x;
    n++;
}

// Hàm loại bỏ các phần tử trùng nhau trong mảng
int removeDuplicates(int arr[], int &n) {
    int newSize = n;
    for (int i = 0; i < newSize - 1; ++i) {
        for (int j = i + 1; j < newSize; ++j) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < newSize - 1; ++k) {
                    arr[k] = arr[k + 1];
                }
                newSize--;
                j--;
            }
        }
    }
    return newSize;
}

// Hàm hủy n phần tử trong mảng bắt đầu từ vị trí p
void removeNElementsFromPosition(int arr[], int &n, int p, int count) {
    if (p < 0 || p >= n || count <= 0) {
        return;
    }
    int newSize = n - count;
    for (int i = p; i < newSize; ++i) {
        arr[i] = arr[i + count];
    }
    n = newSize;
}

// Hàm chèn mảng B vào mảng A từ vị trí p
void insertArray(int arrA[], int &nA, int arrB[], int nB, int p) {
    if (p < 0 || p > nA) {
        return;
    }
    int newSize = nA + nB;
    for (int i = newSize - 1; i >= p + nB; --i) {
        arrA[i] = arrA[i - nB];
    }
    for (int i = 0; i < nB; ++i) {
        arrA[p + i] = arrB[i];
    }
    nA = newSize;
}

int main() {
    int choice;

    do {
        cout << "Menu: " << endl;
        cout << "1. Tinh trung binh cong cua so duong va so am" << endl;
        cout << "2. In cac so nguyen to trong mang" << endl;
        cout << "3. Sap xep mang so nguyen chan" << endl;
        cout << "4. Xoa cac phan tu co gia tri x trong mang" << endl;
        cout << "5. Chen x vao mang va giu nguyen thu tu" << endl;
        cout << "6. Loai bo cac phan tu trung nhau trong mang" << endl;
        cout << "7. Huy n phan tu tu vi tri p trong mang" << endl;
        cout << "8. Chen mang B vao mang A tu vi tri p" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Nhap so luong phan tu: ";
                cin >> n;
                int arr[MAX_SIZE];
                cout << "Nhap cac phan tu: ";
                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
                }
                calculateAverage(arr, n);
                break;
            }
            case 2: {
                int n;
                cout << "Nhap so luong phan tu: ";
                cin >> n;
                int arr[MAX_SIZE];
                cout << "Nhap cac phan tu: ";
                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
                }
                printPrimes(arr, n);
                break;
            }
            case 3: {
                int n;
                cout << "Nhap so luong phan tu: ";
                cin >> n;
                int arr[MAX_SIZE];
                cout << "Nhap cac phan tu: ";
                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
                }
                sortEven(arr, n);
                cout << "Mang sau khi sap xep: ";
                for (int i = 0; i < n; ++i) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 4: {
                int n, x;
                cout << "Nhap so luong phan tu: ";
                cin >> n;
                int arr[MAX_SIZE];
                cout << "Nhap cac phan tu: ";
                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
                }
                cout << "Nhap gia tri x muon xoa: ";
                cin >> x;
                int newSize = removeElement(arr, n, x);
                cout << "Mang sau khi xoa phan tu " << x << ": ";
                for (int i = 0; i < newSize; ++i) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 5: {
                int n, x;
                cout << "Nhap so luong phan tu: ";
                cin >> n;
                int arr[MAX_SIZE];
                cout << "Nhap cac phan tu: ";
                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
                }
                cout << "Nhap gia tri x muon chen: ";
                cin >> x;
                insertAndMaintainOrder(arr, n, x);
                cout << "Mang sau khi chen " << x << ": ";
                for (int i = 0; i < n; ++i) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 6: {
                int n;
                cout << "Nhap so luong phan tu: ";
                cin >> n;
                int arr[MAX_SIZE];
                cout << "Nhap cac phan tu: ";
                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
                }
                int newSize = removeDuplicates(arr, n);
                cout << "Mang sau khi loai bo phan tu trung nhau: ";
                for (int i = 0; i < newSize; ++i) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 7: {
                int n, p, count;
                cout << "Nhap so luong phan tu: ";
                cin >> n;
                int arr[MAX_SIZE];
                cout << "Nhap cac phan tu: ";
                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
                }
                cout << "Nhap vi tri p muon xoa: ";
                cin >> p;
                cout << "Nhap so luong phan tu muon xoa: ";
                cin >> count;
                removeNElementsFromPosition(arr, n, p, count);
                cout << "Mang sau khi xoa " << count << " phan tu tu vi tri " << p << ": ";
                for (int i = 0; i < n; ++i) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 8: {
                int nA, nB, p;
                cout << "Nhap so luong phan tu mang A: ";
                cin >> nA;
                int arrA[MAX_SIZE];
                cout << "Nhap cac phan tu mang A: ";
                for (int i = 0; i < nA; ++i) {
                    cin >> arrA[i];
                }
                cout << "Nhap so luong phan tu mang B: ";
                cin >> nB;
                int arrB[MAX_SIZE];
                cout << "Nhap cac phan tu mang B: ";
                for (int i = 0; i < nB; ++i) {
                    cin >> arrB[i];
                }
                cout << "Nhap vi tri p muon chen: ";
                cin >> p;
                insertArray(arrA, nA, arrB, nB, p);
                cout << "Mang A sau khi chen mang B tu vi tri " << p << ": ";
                for (int i = 0; i < nA; ++i) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;
            }
            case 0:
                cout << "Ket thuc chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }

    } while (choice != 0);

    return 0;
}

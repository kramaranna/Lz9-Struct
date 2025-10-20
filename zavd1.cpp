#include <iostream>
#include <string>
#include <limits> // додано для numeric_limits
using namespace std;

struct Student {
    string PIB; // ПІБ
    int NG;     // Номер групи
    int RN;     // Рік народження
};

int main() {
    const int SIZE = 10;
    Student st[SIZE];

    // Введення даних
    cout << "Введіть дані для 10 студентів:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\n" << i + 1 << "-й студент:\n";
        cout << "Введіть ПІБ: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищення буфера
        getline(cin, st[i].PIB);
        cout << "Введіть номер групи: ";
        cin >> st[i].NG;
        cout << "Введіть рік народження: ";
        cin >> st[i].RN;
    }

    // Сортування за номером групи (метод бульбашки)
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (st[j].NG > st[j + 1].NG) {
                Student temp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = temp;
            }
        }
    }

    // Виведення відсортованого списку
    cout << "\nВідсортований список студентів за номером групи:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << st[i].PIB << " — група " << st[i].NG 
             << ", рік народження " << st[i].RN << endl;
    }

    // Пошук студентів одного року народження
    int searchYear;
    cout << "\nВведіть рік народження для пошуку: ";
    cin >> searchYear;

    bool found = false;
    cout << "\nСтуденти, народжені у " << searchYear << " році:\n";
    for (int i = 0; i < SIZE; i++) {
        if (st[i].RN == searchYear) {
            cout << st[i].PIB << " — група " << st[i].NG << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Немає студентів, народжених у цьому році.\n";

    return 0;
}
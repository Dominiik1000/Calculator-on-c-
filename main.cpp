#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cmath>    // для sqrt и pow
#include <iomanip>  // для setprecision
using namespace std;

int main() {
    float num1, num2, res;
    char math;

    // Автор
    string author = "Made by Dominiik";
    for (char c : author) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(60));
    }
    cout << endl;

    // Баннер
    string banner[] = {
        "|--------------|",
        "|    HELLO     |",
        "|   WELCOME    |",
        "|      TO      |",
        "|  CALCULATOR  |",
        "|--------------|"
    };

    for (const string& line : banner) {
        for (char c : line) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(40));
        }
        cout << endl;
    }

    string thinking = "thinking 1..2..3";

    while (true) {
        // Меню (по буквам)
        string menu =
            "\n--- CALCULATOR MENU ---\n"
            "[+] Addition\n"
            "[-] Subtraction\n"
            "[*] Multiplication\n"
            "[/] Division\n"
            "[^] Power\n"
            "[r] Square root\n"
            "[q] Quit\n"
            "Choose operation: ";

        for (char c : menu) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(30));
        }
        cin >> math;

        if (math == 'q') {
            string bye = "Goodbye!";
            for (char c : bye) {
                cout << c << flush;
                this_thread::sleep_for(chrono::milliseconds(80));
            }
            cout << endl;
            break;
        }

        if (math == 'r') {
            string ask = "Enter number: ";
            for (char c : ask) {
                cout << c << flush;
                this_thread::sleep_for(chrono::milliseconds(50));
            }
            cin >> num1;

            if (num1 < 0) {
                string err = "Error: Cannot take sqrt of negative number!";
                for (char c : err) {
                    cout << c << flush;
                    this_thread::sleep_for(chrono::milliseconds(50));
                }
                cout << endl;
                continue;
            }
            res = sqrt(num1);
        } else {
            string ask1 = "Enter first number: ";
            for (char c : ask1) {
                cout << c << flush;
                this_thread::sleep_for(chrono::milliseconds(50));
            }
            cin >> num1;

            string ask2 = "Enter second number: ";
            for (char c : ask2) {
                cout << c << flush;
                this_thread::sleep_for(chrono::milliseconds(50));
            }
            cin >> num2;

            switch (math) {
                case '+': res = num1 + num2; break;
                case '-': res = num1 - num2; break;
                case '*': res = num1 * num2; break;
                case '/':
                    if (num2 == 0) {
                        string err = "Error: Division by zero!";
                        for (char c : err) {
                            cout << c << flush;
                            this_thread::sleep_for(chrono::milliseconds(50));
                        }
                        cout << endl;
                        continue;
                    }
                    res = num1 / num2;
                    break;
                case '^': res = pow(num1, num2); break;
                default: {
                    string err = "Unknown operation!";
                    for (char c : err) {
                        cout << c << flush;
                        this_thread::sleep_for(chrono::milliseconds(50));
                    }
                    cout << endl;
                    continue;
                }
            }
        }

        // Thinking анимация
        for (char c : thinking) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        cout << endl;

        // Вывод результата по буквам
        string result = "Result: " + to_string(res);
        for (char c : result) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(60));
        }
        cout << endl;
    }

    return 0;
}

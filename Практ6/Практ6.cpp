#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNumber, double initialBalance) {
        this->accountNumber = accNumber;
        this->balance = initialBalance;
        this->interestRate = 0.0;
    }
    void deposit(double a) {
        if (a > 0) {
            balance += a;
            cout << "Успешно!";
        }
        else {
            cout << "Нельзя внести отрицательное число";
        }
    }
    void withdraw(double a) {
        if (a > 0) {
            if (a > balance) {
                cout << "Недостаточно средств";
            }
            else {
                balance -= a;
                cout << "Успешно";
            }
        }
        else {
            cout << "Нельзя снять отрицательное число";
        }
    }
    double getBalance() {
        return balance;
    }
    int getAccountNumber() {
        return accountNumber;
    }
    void setInterestRate(double InterestRate) {
        interestRate = InterestRate;
    }
    double getInterest() {
        return balance * interestRate * (1 / 12);
    }
    friend bool transfer(BankAccount& first, BankAccount& second, double a) {
        bool res;
        if (a > first.balance) {
            cout << "Недостаточно средств";
            res = false;
        }
        else if (a < 0) {
            cout << "Нельзя перевести";
            res = false;
        }
        else {
            first.balance -= a;
            second.balance += a;
            res = true;
            cout << "Успешно!";
        }
        return res;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    BankAccount first(1, 2000.50);
    BankAccount second(2, 30.20);
    cout << "1. Внести средства на счёт \n2. Снять средства \n3. Посмотреть текущий баланс \n4. Посмотреть сумму процентов \n5. Обновить процентную ставку \n6. Получить номер банковского счёта \n7. Перевод стредств \nЧто хотите сделать? " << endl;
    int choice;
    int ch;
    double b;
    cin >> choice;
    cout << "В банке 2 аккаунта: 1 и 2";
    switch (choice)
    {
    case 1:
        cout << "\nНа какой аккаунт хотите внести средства? ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "\nСколько хотите внести? ";
            cin >> b;
            first.deposit(b);
            break;
        case 2:
            cout << "\nСколько хотите внести?";
            cin >> b;
            second.deposit(b);
            break;
        default:
            cout << "\nЧто-то пошло не так";
            break;
        }
        break;
    case 2:
        cout << "\nС какого аккаунта хотите снять средства? ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "\nСколько хотите снять?";
            cin >> b;
            first.withdraw(b);
            break;
        case 2:
            cout << "\nСколько хотите снять?";
            cin >> b;
            second.withdraw(b);
            break;
        default:
            cout << "\nЧто-то пошло не так";
            break;
        }
        break;
    case 3:
        cout << "\nБалланс какого аккаунта хотите посмотреть? "<<endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << first.getBalance();
            break;
        case 2:
            cout << second.getBalance();
            break;
        default:
            cout << "\nЧто-то пошло не так";
            break;
        }
        break;
    case 4:
        cout << "\nСумму процентов какого аккаунта хотите посмотреть? "<< endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout<< first.getInterest();
            break;
        case 2:
            cout << second.getInterest();
            break;
        default:
            cout << "\nЧто-то пошло не так";
            break;
        }
        break;
    case 5:
        cout << "\nПроцентную ставку какого аккаунта хотите поменять? ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "\nНа какю поменяете? ";
            cin >> b;
            first.setInterestRate(b);
            break;
        case 2:
            cout << "\nНа какую поменяете? ";
            cin >> b;
            second.setInterestRate(b);
            break;
        default:
            cout << "Что-то пошло не так";
            break;
        }
        break;
    case 6:
        cout << "\nНомер банковского счёта какого аккаунта хотите посмотреть? \n"<<endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << first.getAccountNumber();
            break;
        case 2:
            cout << second.getAccountNumber();
            break;
        default:
            cout << "\nЧто-то пошло не так";
            break;
        }
        break;
    case 7:
        cout << "\nС какого аккаунта хотите провести транзакцию ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "\nСколько хотите перевести? ";
            cin >> b;
            transfer(first, second, b);
            break;
        case 2:
            cout << "\nСколько хотите перевести? ";
            cin >> b;
            transfer(second, first, b);
            break;
        default:
            cout << "\nЧто-то пошло не так";
            break;
        }
    break;
    default:
        cout << "\nЧто-то пошло не так";
        break;
    }
}
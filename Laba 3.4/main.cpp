#include "Classes.h"


int main() {
    T2* obj1 = nullptr;
    T2* obj2 = nullptr;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Create object 1" << endl;
        cout << "2. Create object 2" << endl;
        cout << "3. Delete object 1" << endl;
        cout << "4. Delete object 2" << endl;
        cout << "5. Show object 1 value" << endl;
        cout << "6. Show object 2 value" << endl;
        cout << "7. Show octal representation of object 1 value" << endl;
        cout << "8. Show octal representation of object 2 value" << endl;
        cout << "9. Add two objects" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                string id, val;
                cout << "Enter identifier for the object 1: ";
                cin >> id;
                cout << "Enter value for the object 1: ";
                cin >> val;
                obj1 = Factory::create(id, val);
                break;
            }
            case 2: {
                string id, val;
                cout << "Enter identifier for the object 2: ";
                cin >> id;
                cout << "Enter value for the object 2: ";
                cin >> val;
                obj2 = Factory::create(id, val);
                break;
            }
            case 3: {
                if (obj1 != nullptr) {
                    Factory::deleteObject(obj1);
                    obj1 = nullptr;
                } else {
                    cout << "No object 1 to delete." << endl;
                }
                break;
            }
            case 4: {
                if (obj2 != nullptr) {
                    Factory::deleteObject(obj2);
                    obj2 = nullptr;
                } else {
                    cout << "No object 2 to delete." << endl;
                }
                break;
            }
            case 5: {
                if (obj1 != nullptr) {
                    obj1->showValue();
                } else {
                    cout << "No object 1 to show." << endl;
                }
                break;
            }
            case 6: {
                if (obj2 != nullptr) {
                    obj2->showValue();
                } else {
                    cout << "No object 2 to show." << endl;
                }
                break;
            }
            case 7: {
                if (obj1 != nullptr) {
                    obj1->ShowOct();
                } else {
                    cout << "No object 1 to show." << endl;
                }
                break;
            }
            case 8: {
                if (obj2 != nullptr) {
                    obj2->ShowOct();
                } else {
                    cout << "No object 2 to show." << endl;
                }
                break;
            }
            case 9: {
                if (obj1 != nullptr && obj2 != nullptr) {
                    T2 result = *obj1 + *obj2;
                    result.showValue();
                } else {
                    cout << "Need two objects to add." << endl;
                }
                break;
            }
            case 10:
                cout << "Exiting program." << endl;

                if (obj1 != nullptr) {
                    Factory::deleteObject(obj1);
                }
                if (obj2 != nullptr) {
                    Factory::deleteObject(obj2);
                }
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 10." << endl;
        }
    }
}

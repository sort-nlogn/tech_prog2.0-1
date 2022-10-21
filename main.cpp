#include <iostream>
#include <string>
#include "Keeper.hpp"

using namespace std;

void show_menu() {
    cout << "1 - add a new element\n2 - print collection\n3 - edit collection\n4 - delete element\n" <<
    "5 - load from file\n6 - save to the file\n" <<
    "7 - clear collection\n8 - calculate total cost\n9 - exit\n";
}

int main(){
    Keeper *keeper = new Keeper();
    bool stop = false;
    int action;
    show_menu();
    while(!stop){
        cout << "\nEnter action: "; cin >> action;
        system("cls");
        show_menu();

        if (action ==  1){
            cout << "Select type(1 - stationery, 2 - book, 3 - schoolbook): "; int ch; cin >> ch;
            if(ch == 1){
                Stationery *s = new Stationery(); cin >> *s;
                keeper->add(s);
            }else if(ch == 2){
                Book *b = new Book(); cin >> *b;
                keeper->add(b);
            }else if(ch == 3){
                Schoolbook *sb = new Schoolbook(); cin >> *sb;
                keeper->add(sb);
            }
        }else if(action == 2){
            keeper->print();
        }else if(action == 3){
            int pos; cout << "Enter pos: "; cin >> pos;
            keeper->edit(pos);
        }else if(action == 4){
            int pos; cout << "Enter pos: "; cin >> pos;
            keeper->remove(pos);
        }else if(action == 5){
            string path; cout << "Enter path: "; cin >> path;
            keeper->load_from_file(path);
        }else if(action == 6){
            string path; cout << "Enter path: "; cin >> path;
            keeper->save_to_file(path);
        }else if(action == 7){
            keeper->free();
        }else if(action == 8){
            cout << "Total cost: " << keeper->total_cost() << endl;
        }else if(action == 9){
            stop = true;
        }else{
            cout << "No such action" << endl; break;
        }
    }
    return 0;
}
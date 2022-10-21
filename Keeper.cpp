#include "Keeper.hpp"

Keeper::Keeper() {
  std::cout << "Keeper default constructor has been called" << "\n";
  size = 0;
}

Keeper::~Keeper() {
  std::cout << "Keeper destructor has been called" << "\n";
  delete head;
  delete tail;
}

void Keeper::add(Stuff *stuff){
    Node *temp = new Node;
    temp->stuff = stuff;
    temp->next = NULL;  
    if (head == NULL) {
        head = temp;
        tail = temp;
        temp = NULL;
    }else{
        tail->next = temp;
        tail = temp;
    }
    size++;
    cout << "Now collection size is " << size << "\n";
}

void Keeper::print(){
    if (!size) throw std::runtime_error("The collection is empty");
    Node *temp = new Node;  
    temp = head;
    int counter = 1;
    while(temp != nullptr){
        std::cout << counter++ << ". ";
        temp->stuff->describe();
        temp = temp->next;
    }
}

void Keeper::remove(int pos) {
    if (!size) throw std::runtime_error("the list of ships is empty");
    if (pos > size || pos < 1) {
      throw std::runtime_error("The number doesn't fall within the range [1; " + std::to_string(size) + "]");
    }

    Node *curr = new Node;
    Node *prev = new Node;
    curr = head;
    if (pos == 1) head = head->next;    
    for(int i = 1; i < pos; i++) {
      prev = curr;
      curr = curr->next;
    }
    if (pos == size) {
      tail = prev;
      prev->next = NULL;
      tail->next = NULL;
    } else {
      prev->next = curr->next;
    }
    size--;  
    delete curr->stuff;
}

Stuff *Keeper::get(int num) {
    if (!size) throw std::runtime_error("The collection is empty");
    if (num > size || num < 1) {
      throw std::runtime_error("The number should fall within the range [1: " + std::to_string(size) + "]");
    }
    Node *cur = new Node;
    Node *prev = new Node;
    cur = head;
    if (num == 1) return head->stuff;    
    for(int i = 1; i < num; i++) {
      prev = cur;
      cur = cur->next;
    }
    return cur->stuff;
}

void Keeper::edit(int pos){
    Stuff::variant type = this->get(pos)->get_type();
    int n; string str; int val;

    if(type == Stuff::variant::STATIONERY){
        Stationery *s = (Stationery *)this->get(pos);
        cout << "Select stationery property to edit (1 - type, 2 - purpose, 3 - color, 4 - cost): ";
        cin >> n;
        if (n == 1){
            cout << "Enter type: "; cin >> str; s->set_type_stationery(str);
        }else if(n == 2){
            cout << "Enter purpose: "; cin >> str; s->set_purpose_stationery(str);
        }else if(n == 3){
            cout << "Enter color: "; cin >> str; s->set_color_stationery(str);
        }else if(n == 4){
            cout << "Enter cost: "; cin >> val; s->set_cost_stationery(val);
        }
    }else if(type == Stuff::variant::BOOK){
        Book *b = (Book *)this->get(pos);
        cout << "Select book property to edit (1 - author, 2 - annotation, 3 - genere, 4 - pages, 5 - cost, 6 - release year, 7 - name";
        cin >> n;
        if (n == 1){
            cout << "Enter author: "; cin >> str; b->set_author_book(str);
        }else if(n == 2){
            cout << "Enter annotation: "; cin >> str; b->set_annotation_book(str);
        }else if(n == 3){
            cout << "Enter genere: "; cin >> str; b->set_genere_book(str);
        }else if(n == 4){
            cout << "Enter pages: "; cin >> val; b->set_pages_book(val);
        }else if(n == 5){
            cout << "Enter cost: "; cin >> val; b->set_cost_book(val);
        }else if(n == 6){
            cout << "Enter release_year: "; cin >> val; b->set_release_year_book(val);
        }else if(n == 7){
            cout << "Enter name: "; cin >> str; b->set_name_book(str);
        }
    }else{
        Schoolbook *sb = (Schoolbook *)this->get(pos);
        cout << "Select schoolbook property to edit (1 - name, 2 - author, 3 - university name, 4 - pages, 5 - cost, 6 - release year, 7 - class number";
        cin >> n;
        if (n == 1){
            cout << "Enter name: "; cin >> str; sb->set_name_schoolbook(str);
        }else if(n == 2){
            cout << "Enter author: "; cin >> str; sb->set_author_schoolbook(str);
        }else if(n == 3){
            cout << "Enter universty name: "; cin >> str; sb->set_uni_name_schoolbook(str);
        }else if(n == 4){
            cout << "Enter pages: "; cin >> val; sb->set_pages_schoolbook(val);
        }else if(n == 5){
            cout << "Enter cost: "; cin >> val; sb->set_cost_schoolbook(val);
        }else if(n == 6){
            cout << "Enter release year : "; cin >> val; sb->set_release_year_schoolbook(val);
        }else if(n == 7){
            cout << "Enter class number: "; cin >> val; sb->set_class_number_schoolbook(val);
        }
    }
}

void Keeper::free() {
    if (!size) return;  
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        delete curr->stuff;
        delete curr;
        curr = next;
    }
    head = NULL;
    tail = NULL;
    size = 0;
}

string *Keeper::split(string str, string delimiter, int count) {
    int pos, i = 0;
    string *strings = new string[count];

    while ((pos = str.find(delimiter)) != string::npos) {
      strings[i++] = str.substr(0, pos);
      str.erase(0, pos + delimiter.length());
    }
    strings[i] = str;
    return strings;
}

void Keeper::load_from_file(string path){
    string str;
    ifstream in(path);
    while(getline(in, str)){
        string *strs = split(str, " ", 8);
        if (strs[0] == "Stationery"){
            Stationery *s = new Stationery(strs[1], strs[2], strs[3], stoi(strs[4]));
            add(s);
        }else if(strs[0] == "Book"){
            Book *b = new Book(strs[1], strs[2], strs[3], strs[4], stoi(strs[5]), stoi(strs[6]), stoi(strs[7]));
            add(b);
        }else if(strs[0] == "Schoolbook"){
            Schoolbook *sb = new Schoolbook(strs[1], strs[2], strs[3], stoi(strs[4]), stoi(strs[5]), stoi(strs[6]), stoi(strs[7]));
            add(sb);
        }
    }
    in.close();
}
void Keeper::save_to_file(string path){
    ofstream out;
    out.open("out.txt", ios::out);
    if(out.is_open()) {
        Node *temp = new Node;
        temp = head;
        while(temp != nullptr) {
            if (temp->stuff->get_type() == Stuff::STATIONERY){
                Stationery *s = (Stationery *)temp->stuff;
                out << "Stationery ";
                out << s->get_type_stationery() << " ";
                out << s->get_purpose_stationery() << " ";
                out << s->get_color_stationery() << " ";
                out << to_string(s->get_cost_stationery()) << endl;
            }else if(temp->stuff->get_type() == Stuff::BOOK){
                Book *b = (Book *)temp->stuff;
                out << "Book ";
                out << b->get_name_book() << " ";
                out << b->get_author_book() << " ";
                out << b->get_annotation_book() << " ";
                out << b->get_genere_book() << " ";
                out << to_string(b->get_pages_book()) << " ";
                out << to_string(b->get_cost_book()) << " ";
                out << to_string(b->get_release_year_book()) << endl;
            }else if(temp->stuff->get_type() == Stuff::SCHOOLBOOK){
                Schoolbook *sb = (Schoolbook *)temp->stuff;
                out << "Schoolbook ";
                out << sb->get_name_schoolbook() << " ";
                out << sb->get_author_schoolbook() << " ";
                out << sb->get_uni_name_schoolbook() << " ";
                out << to_string(sb->get_pages_schoolbook()) << " ";
                out << to_string(sb->get_cost_schoolbook()) << " ";
                out << to_string(sb->get_release_year_schoolbook()) << " ";
                out << to_string(sb->get_class_number_schoolbook()) << endl;
            }
            temp = temp->next;
        }
    }else{
        std::cout << "failed to open the file";
    }
    out.close();
}

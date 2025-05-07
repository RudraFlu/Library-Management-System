#include <iostream>
#include <queue>
#include <map>
using namespace std;
class node{
    public:
//node for a doubly linked list
string name;
int ID;
    node *next;
    node *prev;
    node(int n,string i){
    ID = n;
    name = i;
    next = nullptr;
    prev = nullptr;
    }
};
class Members
{
    public:
    node *head;
    Members(){
        head=nullptr;
    }


    //function to add members
    void addMember(int n,string i){
        node *newnode=new node(n,i);
    if(!head){
        head = newnode;
        return;
    }
    node *temp = head;
    while(temp->next!=nullptr){
temp = temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    }
    //function for duplicate members
    bool isDuplicateMember(int id) {
        node* temp = head;
        while (temp) {
            if (temp->ID == id) return true;
            temp = temp->next;
        }
        return false;
    }
    

    //function to search member through ID
    void searchMember(int i){
    node *temp = head;
    while(temp!=nullptr){
        if(temp->ID==i){
            cout<<"Member found!!\nName: "<<temp->name<<"\nMember ID: "<<temp->ID<<endl;
        return;
        }
        temp=temp->next;
    }
    throw invalid_argument("Member not found or invalid member ID.");
    }


    //function to display all members
    void displayALLmember(){
    node *temp = head;
    int i=0;
    if(head==nullptr){
        cout<<"No members yet"<<endl;
        return;
    }
    while(temp){
        cout<<"===================="<<endl;
        cout<<"Member "<<++i<<endl;
        cout<<"Name: "<<temp->name<<"\nMember ID: "<<temp->ID<<endl;
    temp = temp->next;
    }
    }

};
class Librarian
{
public:
    int ID;
    string Name;
    Librarian(int i,string n):ID(i),Name(n){}


    //function to update librarian
    void UpdateLib(){
    cout<<"Enter ID: ";
    cin>>ID;
    cin.ignore();
    cout<<"Enter Name: ";
    getline(cin,Name);
    cout<<"Librarian Updated Successfully!!!\n\n"<<endl;
    }



    //function to display librarian
    void DisplayLib(){
    cout<<"Librarian:\nName: "<<Name<<"\nID: "<<ID<<endl;
    }

};
class Transaction{
public:
    string BOOK;
    float Price;
    Transaction(string b,float p):BOOK(b),Price(p){}
};
class Book:public Transaction{
public:
    int ID;
    string title;
    string author;

    Book(int id,string t,string a,float p):ID(id),title(t),author(a),Transaction(t,p){}

    void display(){
        cout << "Book ID: " << ID << "\nTitle: " << title << "\nAuthor: " << author << endl;
    }

    // Template search for queue
    template <typename T>
    static void searchBook(queue<Book> q, T value) {
        bool found = false;
        while (!q.empty()) {
            Book b = q.front();
            q.pop();
            if constexpr (is_same<T, int>::value) {
                if (b.ID == value) {
                    b.display();
                    found = true;
                }
            } else if constexpr (is_same<T, string>::value) {
                if (b.title == value || b.author == value) {
                    b.display();
                    found = true;
                }
            }
        }
        if (!found) {
            throw runtime_error("Book not found.");
        }
    }
};
class Library {
private:
    Members memberList;
    Librarian librarian;
    queue<Book> books;
    map<int, int> issuedBooks;
public:
    // Constructor initializing librarian
    Library() : librarian(0, "Unknown") {}

    // Add a new book
    void addBook(int id, string title, string author, float price) {
        Book b(id, title, author, price);
        books.push(b);
        cout << "Book added successfully!\n";
    }

    // Add a new member
    void addMember(int id, string name) {
        if (memberList.isDuplicateMember(id)) {
            cout << "Member with ID " << id << " already exists. Skipping.\n";
        } else {
            memberList.addMember(id, name);
            cout << "Member added successfully!\n";
        }
    }
    

    // Search for a book by ID or title/author
    template <typename T>
    void searchBook(T value) {
        try {
            Book::searchBook(books, value);
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    // Search for a member
    void searchMember(int id) {
        try {
            memberList.searchMember(id);
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    // Display all members
    void displayMembers() {
        memberList.displayALLmember();
    }

    // Update librarian
    void updateLibrarian() {
        librarian.UpdateLib();
    }

    // Display librarian
    void displayLibrarian() {
        librarian.DisplayLib();

}
//fuction to keep tab of issued books
void issueBook(int memberID) {
    try {
        if (!memberList.isDuplicateMember(memberID)) {
            throw invalid_argument("Invalid member ID. Cannot issue book.");
        }
        if (issuedBooks[memberID] >= 5) {
            throw runtime_error("Issue limit reached! Member has already issued 3 books.");
        }
        issuedBooks[memberID]++;
        cout << "Book issued to member ID: " << memberID << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}
};
int main(){

    bool exit = false;
Library L1;
while(!exit){
    cout<<endl;
int Fun=0;
cout<< "----------------------\n"
       "Enter Your Function!\n"
       "----------------------\n"
       "1.Update Librarian\n"
       "2.Add Members\n"
       "3.Search Member\n"
       "4.Display Members\n"
       "5.Display Librarian\n"
       "6.Add Book\n"
       "7.Search Book\n"
       "8.Issue Book\n"
       "9.Exit"<<endl;
       cin>>Fun;
       switch(Fun){
   case 1:
       {L1.updateLibrarian();}
    break;
   case 2:
   {int n;
   int i;
   string name;
   cout<<"How many Members would you like to add: ";
   cin>>n;
   cin.ignore();
   for(int j=0;j<n;j++){
    cout<<"Enter Name: ";
    getline(cin,name);
    cout<<"Enter ID: ";
    cin>>i;
    cin.ignore();
  L1.addMember(i,name);
   }}
   break;
   case 3:
   {int id;
   cout<<"Enter ID: ";
   cin>>id;
   L1.searchMember(id);
   break;}
   case 4:
   {L1.displayMembers();}
break;
case 5:
{L1.displayLibrarian();}
break;
case 6:{
int n;
   int id;float p;
   string t,a;
   cout<<"How many Books would you like to add: ";
   cin>>n;
   cin.ignore();
   for(int j=0;j<n;j++){
    cout<<"Enter Title: ";
    getline(cin,t);
    cout<<"Enter ID: ";
    cin>>id;
    cin.ignore();
    cout<<"Enter Author: ";
    getline(cin,a);
    cout<<"Enter Price: ";
    cin>>p;
    cin.ignore();

  L1.addBook(id,t,a,p); }
break;}
case 7: {
    int choice;
    cout << "Search Book By:\n1. ID\n2. Title/Author\nChoice: ";
    cin >> choice;
    if (choice == 1) {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;
        L1.searchBook(id);
    } else if (choice == 2) {
        string value;
        cout << "Enter Title or Author: ";
        cin.ignore(); // Clear newline
        getline(cin, value);
        L1.searchBook(value);
    } else {
        cout << "Invalid choice.\n";
    }
    break;
}
case 8: {
    int id;
    cout << "Enter Member ID to issue a book: ";
    cin >> id;
    L1.issueBook(id);
    break;
}

   case 9:{
    exit=true;
    cout<<"Exiting program!!"<<endl;
    break;
}
default:
cout<<"Invalid Input"<<endl;
break;
}
}}

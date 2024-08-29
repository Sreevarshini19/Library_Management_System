//#include <iostream>
//#include <set>
//#include <fstream>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <utility>
//#include <ctime>
//#include <unordered_map> // Updated to use unordered_map
//using namespace std;
//// Student structure to hold student information
////struct Student {
////    string registerNumber;
////    string name;
////    int due;
////
////    Student(string regNo, string name, int due = 0) 
////        : registerNumber(regNo), name(name), due(due) {}
////};
//struct Student {
//    string registerNumber;
//    string name;
//    int due;
//
//    // Default constructor
//    Student() : registerNumber(""), name(""), due(0) {}
//
//    // Parameterized constructor
//    Student(string regNo, string name, int due = 0) 
//        : registerNumber(regNo), name(name), due(due) {}
//};
//
//
//// Book class definition
//class book {
//private:
//    int id;
//    string author;
//    string book_name;
//    int year_of_publish;
//    int edition;
//    string subject;
//    int borrowed;
//    int due;
//    time_t borrowed_date;
//
//public:
//    // Constructor
//    book(int id, string author, string book_name, int year_of_publish, int edition, string subject)
//        : id(id), author(author), book_name(book_name), year_of_publish(year_of_publish),
//          edition(edition), subject(subject), borrowed(0), due(0) {}
//
//    // Accessor methods
//    int getId() const { return id; }
//    string getAuthor() const { return author; }
//    string getBookName() const { return book_name; }
//    int getYearOfPublish() const { return year_of_publish; }
//    int getEdition() const { return edition; }
//    string getSubject() const { return subject; }
//    int getBorrowed() const { return borrowed; }
//    int getDue() const { return due; }
//    time_t getBorrowedDate() const { return borrowed_date; }
//
//    // Mutator methods
//    void setBorrowed(int status) { borrowed = status; }
//    void setBorrowedDate(time_t date) { borrowed_date = date; }
//    void setDue(int dueAmount) { due = dueAmount; }
//
//    // Function to convert book to string format for file storage
//    string toString() const {
//        return to_string(id) + "," + author + "," + book_name + "," + to_string(year_of_publish) + "," +
//               to_string(edition) + "," + subject + "," + to_string(borrowed) + "," + to_string(due);
//    }
//
//    // Static function to parse a string into a book object
//    static book fromString(const string& bookData) {
//        stringstream ss(bookData);
//        string token;
//        int id, year_of_publish, edition, borrowed, due;
//        string author, book_name, subject;
//
//        getline(ss, token, ',');
//        id = stoi(token);
//        getline(ss, author, ',');
//        getline(ss, book_name, ',');
//        getline(ss, token, ',');
//        year_of_publish = stoi(token);
//        getline(ss, token, ',');
//        edition = stoi(token);
//        getline(ss, subject, ',');
//        getline(ss, token, ',');
//        borrowed = stoi(token);
//        getline(ss, token, ',');
//        due = stoi(token);
//
//        book b(id, author, book_name, year_of_publish, edition, subject);
//        b.setBorrowed(borrowed);
//        b.setDue(due);
//
//        return b;
//    }
//
//    // Comparison operator for set ordering
//    bool operator<(const book& other) const {
//        return this->id < other.id; // Example: comparing by id
//    }
//
//    // Display method
//    void display() const {
//        cout << "ID: " << id << ", Author: " << author << ", Book Name: " << book_name
//             << ", Year of Publish: " << year_of_publish << ", Edition: " << edition
//             << ", Subject: " << subject << ", Borrowed: " << borrowed << ", Due: " << due << endl;
//    }
//};
//
//// Library class to manage books and students
//class library {
//private:
//    set<book> books;
//    unordered_map <string, Student> students; // Changed to unordered_map
//
//public:
//    library() {
//        loadBooksFromFile();
//        loadStudentsFromFile();
//    }
//
//    // Add a new book
//    void addBook() {
//        int id, year, edition;
//        string author, name, subject;
//
//        cout << "Enter Book ID: ";
//        cin >> id;
//        cout << "Enter Author: ";
//        cin.ignore();
//        getline(cin, author);
//        cout << "Enter Book Name: ";
//        getline(cin, name);
//        cout << "Enter Year of Publish: ";
//        cin >> year;
//        cout << "Enter Edition: ";
//        cin >> edition;
//        cout << "Enter Subject: ";
//        cin.ignore();
//        getline(cin, subject);
//
//        book newBook(id, author, name, year, edition, subject);
//        books.insert(newBook);
//        saveBooksToFile();
//        cout << "Book added successfully!" << endl;
//    }
//
//    // Delete a book by ID
//    void deleteBook() {
//        int id;
//        cout << "Enter Book ID to delete: ";
//        cin >> id;
//
//        for (auto it = books.begin(); it != books.end(); ++it) {
//            if (it->getId() == id) {
//                books.erase(it);
//                saveBooksToFile();
//                cout << "Book deleted successfully!" << endl;
//                return;
//            }
//        }
//        cout << "Book not found!" << endl;
//    }
//
//    // Show all books
//    void show_all_books() const {
//        for (const auto& b : books) {
//            b.display();
//        }
//    }
//
//    // Search book by ID or name
//    void search_book() const {
//        string name;
//        cout << "Enter Book Name to search: ";
//        cin.ignore();
//        getline(cin, name);
//
//        for (const auto& b : books) {
//            if (b.getBookName() == name) {
//                b.display();
//                return;
//            }
//        }
//        cout << "Book not found!" << endl;
//    }
//
//    // Register a student
//    void register_student() {
//        string regNo, studentName;
//
//        cout << "Enter Register Number: ";
//        cin >> regNo;
//        cout << "Enter Student Name: ";
//        cin.ignore();
//        getline(cin, studentName);
//
//        // Check if student is already registered
//        if (students.find(regNo) != students.end()) {
//            cout << "Student already registered!" << endl;
//            return;
//        }
//
//        students[regNo] = Student(regNo, studentName);
//        saveStudentsToFile();
//        cout << "Student registered successfully!" << endl;
//    }
//
//    // Check if a student is registered
//    bool is_student_registered(const string& regNo) const {
//        return students.find(regNo) != students.end();
//    }
//
//    // Check and pay dues
//    void check_and_pay_dues() {
//        string regNo;
//        cout << "Enter Register Number to check dues: ";
//        cin >> regNo;
//
//        auto it = students.find(regNo);
//        if (it == students.end()) {
//            cout << "Student not registered!" << endl;
//            return;
//        }
//
//        Student& student = it->second;
//        cout << "Current dues for " << student.name << " (" << student.registerNumber << "): $" << student.due << endl;
//
//        if (student.due > 0) {
//            char pay;
//            cout << "Would you like to pay the dues? (y/n): ";
//            cin >> pay;
//            if (pay == 'y' || pay == 'Y') {
//                student.due = 0;
//                saveStudentsToFile();
//                cout << "Dues paid successfully!" << endl;
//            }
//        } else {
//            cout << "No dues to pay." << endl;
//        }
//    }
//
//    // Calculate due when returning a book
//    void calculate_due() {
//        int id;
//        cout << "Enter Book ID to calculate due: ";
//        cin >> id;
//
//        auto it = books.find(book(id, "", "", 0, 0, ""));
//        if (it != books.end()) {
//            if (it->getBorrowed() == 1) {
//                book b = *it;
//                books.erase(it);
//
//                time_t current_time = time(0);
//                double days = difftime(current_time, b.getBorrowedDate()) / (60 * 60 * 24);
//                int due = static_cast<int>(days) * 5;
//                b.setDue(due);
//
//                // Insert modified book back into the set
//                books.insert(b);
//                saveBooksToFile();
//
//                string regNo;
//                cout << "Enter student register number for this borrowed book: ";
//                cin >> regNo;
//
//                if (is_student_registered(regNo)) {
//                    students[regNo].due += due; // Add due amount to the student
//                    saveStudentsToFile();
//                    cout << "Due amount calculated and added to student's account successfully!" << endl;
//                } else {
//                    cout << "Student not registered!" << endl;
//                }
//            } else {
//                cout << "Book is not borrowed!" << endl;
//            }
//        } else {
//            cout << "Book not found!" << endl;
//        }
//    }
//
//    // Borrow a book
//    void borrow_book() {
//        int id;
//        string regNo;
//        cout << "Enter Book ID to borrow: ";
//        cin >> id;
//        cout << "Enter Register Number: ";
//        cin >> regNo;
//
//        if (!is_student_registered(regNo)) {
//            cout << "Student not registered!" << endl;
//            return;
//        }
//
//        auto it = books.find(book(id, "", "", 0, 0, ""));
//        if (it != books.end()) {
//            book b = *it;
//            if (b.getBorrowed() == 0) {
//                b.setBorrowed(1);
//                b.setBorrowedDate(time(0));
//                books.erase(it);
//                books.insert(b);
//                saveBooksToFile();
//                cout << "Book borrowed successfully!" << endl;
//            } else {
//                cout << "Book is already borrowed!" << endl;
//            }
//        } else {
//            cout << "Book not found!" << endl;
//        }
//    }
//
//    // Return a book
//    void return_book() {
//        int id;
//        string regNo;
//        cout << "Enter Book ID to return: ";
//        cin >> id;
//        cout << "Enter Register Number: ";
//        cin >> regNo;
//
//        auto it = books.find(book(id, "", "", 0, 0, ""));
//        if (it != books.end()) {
//            book b = *it;
//            if (b.getBorrowed() == 1) {
//                b.setBorrowed(0);
//                books.erase(it);
//                books.insert(b);
//                saveBooksToFile();
//                cout << "Book returned successfully!" << endl;
//
//                // Calculate and update the due amount
//                calculate_due();
//            } else {
//                cout << "Book was not borrowed!" << endl;
//            }
//        } else {
//            cout << "Book not found!" << endl;
//        }
//    }
//
//private:
//    // Save all students to file
//    void saveStudentsToFile() const {
//        ofstream outFile("students.txt", ios::out);
//        if (outFile.is_open()) {
//            for (const auto& pair : students) {
//                const Student& s = pair.second;
//                outFile << s.registerNumber << "," << s.name << "," << s.due << endl;
//            }
//            outFile.close();
//        }
//    }
//
//    // Load all students from file
//    void loadStudentsFromFile() {
//        ifstream inFile("students.txt", ios::in);
//        if (inFile.is_open()) {
//            string line;
//            while (getline(inFile, line)) {
//                stringstream ss(line);
//                string regNo, name, dueStr;
//                int due;
//
//                getline(ss, regNo, ',');
//                getline(ss, name, ',');
//                getline(ss, dueStr, ',');
//                due = stoi(dueStr);
//
//                students[regNo] = Student(regNo, name, due);
//            }
//            inFile.close();
//        }
//    }
//
//    // Save all books to file
//    void saveBooksToFile() const {
//        ofstream outFile("books.txt", ios::out);
//        if (outFile.is_open()) {
//            for (const auto& b : books) {
//                outFile << b.toString() << endl;
//            }
//            outFile.close();
//        }
//    }
//
//    // Load all books from file
//    void loadBooksFromFile() {
//        ifstream inFile("books.txt", ios::in);
//        if (inFile.is_open()) {
//            string line;
//            while (getline(inFile, line)) {
//                book b = book::fromString(line);
//                books.insert(b);
//            }
//            inFile.close();
//        }
//    }
//};
//
//// Function to display admin options
//void options_admin() {
//    cout << "--------------------ADMIN--------------------" << endl;
//    cout << "1.ADD BOOK" << endl;
//    cout << "2.DELETE BOOK" << endl;
//    cout << "3.SHOW ALL BOOKS" << endl;
//    cout << "4.SEARCH BOOK" << endl;
//    cout << "5.REGISTER STUDENT" << endl;
//    cout << "6.CALCULATE DUE" << endl;
//    cout << "7.CHECK AND PAY DUES" << endl;
//    cout << "0.EXIT" << endl;
//}
//
//// Function to display student options
//void options_student() {
//    cout << "--------------------STUDENT--------------------" << endl;
//    cout << "1.BORROW BOOKS" << endl;
//    cout << "2.RETURN BOOKS" << endl;
//    cout << "3.SHOW ALL THE BOOK DETAILS" << endl;
//    cout << "4.SEARCH BOOKS" << endl;
//    cout << "5.CHECK AND PAY DUES" << endl;
//    cout << "0.EXIT" << endl;
//}
//
//// Main function
//int main() {
//    library lib;
//    int choice;
//
//    while (true) {
//        cout << "--------------------MAIN MENU--------------------" << endl;
//        cout << "1.ADMIN" << endl;
//        cout << "2.STUDENT" << endl;
//        cout << "0.EXIT" << endl;
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        if (choice == 0) break;
//
//        if (choice == 1) {
//            while (true) {
//                options_admin();
//                cout << "Enter your choice: ";
//                cin >> choice;
//
//                if (choice == 0) break;
//
//                switch (choice) {
//                    case 1:
//                        lib.addBook();
//                        break;
//                    case 2:
//                        lib.deleteBook();
//                        break;
//                    case 3:
//                        lib.show_all_books();
//                        break;
//                    case 4:
//                        lib.search_book();
//                        break;
//                    case 5:
//                        lib.register_student();
//                        break;
//                    case 6:
//                        lib.calculate_due();
//                        break;
//                    case 7:
//                        lib.check_and_pay_dues();
//                        break;
//                    default:
//                        cout << "Invalid choice, try again." << endl;
//                }
//            }
//        } else if (choice == 2) {
//            while (true) {
//                options_student();
//                cout << "Enter your choice: ";
//                cin >> choice;
//
//                if (choice == 0) break;
//
//                switch (choice) {
//                    case 1:
//                        lib.borrow_book();
//                        break;
//                    case 2:
//                        lib.return_book();
//                        break;
//                    case 3:
//                        lib.show_all_books();
//                        break;
//                    case 4:
//                        lib.search_book();
//                        break;
//                    case 5:
//                        lib.check_and_pay_dues();
//                        break;
//                    default:
//                        cout << "Invalid choice, try again." << endl;
//                }
//            }
//        } else {
//            cout << "Invalid choice, try again." << endl;
//        }
//    }
//
//    return 0;
//}

#include <iostream>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <ctime>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

using namespace std;

struct Student {
    string registerNumber;
    string name;
    int due;
    int borrowedBooks;

    Student() : registerNumber(""), name(""), due(0), borrowedBooks(0) {}

    Student(string regNo, string name, int due = 0, int borrowedBooks = 0)
        : registerNumber(regNo), name(name), due(due), borrowedBooks(borrowedBooks) {}
};

class book {
private:
    int id;
    string author;
    string book_name;
    int year_of_publish;
    int edition;
    string subject;
    int borrowed;
    int due;
    time_t borrowed_date;

public:
    book(int id, string author, string book_name, int year_of_publish, int edition, string subject)
        : id(id), author(author), book_name(book_name), year_of_publish(year_of_publish),
          edition(edition), subject(subject), borrowed(0), due(0) {}

    int getId() const { return id; }
    string getAuthor() const { return author; }
    string getBookName() const { return book_name; }
    int getYearOfPublish() const { return year_of_publish; }
    int getEdition() const { return edition; }
    string getSubject() const { return subject; }
    int getBorrowed() const { return borrowed; }
    int getDue() const { return due; }
    time_t getBorrowedDate() const { return borrowed_date; }

    void setBorrowed(int status) { borrowed = status; }
    void setBorrowedDate(time_t date) { borrowed_date = date; }
    void setDue(int dueAmount) { due = dueAmount; }

    string toString() const {
        return to_string(id) + "," + author + "," + book_name + "," + to_string(year_of_publish) + "," +
               to_string(edition) + "," + subject + "," + to_string(borrowed) + "," + to_string(due);
    }

    static book fromString(const string& bookData) {
        stringstream ss(bookData);
        string token;
        int id, year_of_publish, edition, borrowed, due;
        string author, book_name, subject;

        try {
            getline(ss, token, ',');
            id = stoi(token);
            getline(ss, author, ',');
            getline(ss, book_name, ',');
            getline(ss, token, ',');
            year_of_publish = stoi(token);
            getline(ss, token, ',');
            edition = stoi(token);
            getline(ss, subject, ',');
            getline(ss, token, ',');
            borrowed = stoi(token);
            getline(ss, token, ',');
            due = stoi(token);
        } catch (const invalid_argument& e) {
            cerr << "Error parsing book data: " << e.what() << endl;
            throw;
        }

        book b(id, author, book_name, year_of_publish, edition, subject);
        b.setBorrowed(borrowed);
        b.setDue(due);

        return b;
    }

    bool operator<(const book& other) const {
        return this->id < other.id;
    }
 void display() const {
        cout << "| " << setw(4) << id << " | " 
             << setw(6) << author << " | " 
             << setw(13) << book_name << " | " 
             << setw(4) << year_of_publish << " | " 
             << setw(7) << edition << " | " 
             << setw(8) << subject << " | " 
             << setw(9) << borrowed << " | " 
             << setw(4) << due << " |" 
             << endl;
    }
//    void display() const {
//        cout << "| " << id << " | " << author << " | " << book_name << " | " << year_of_publish << " | "
//             << edition << " | " << subject << " | " << borrowed << " | " << due << " |" << endl;
//    }
};

class library {
private:
    set<book> books;
     int next_id;
    unordered_map<string, Student> students;

    string toLowerCase(string str) const {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    string trim(const string& str) const {
        size_t start = str.find_first_not_of(" \t");
        size_t end = str.find_last_not_of(" \t");
        return (start == string::npos) ? "" : str.substr(start, end - start + 1);
    }

public:
    library():next_id(1) {
        loadBooksFromFile();
        loadStudentsFromFile();
    }
	 void addBook() {
        string author, book_name, subject;
        int year_of_publish, edition;
        
        cout << "Enter book details:" << endl;
        cout << "Author: ";
        cin.ignore();
        getline(cin, author);
        cout << "Book Name: ";
        getline(cin, book_name);
        cout << "Year of Publish: ";
        cin >> year_of_publish;
        cout << "Edition: ";
        cin >> edition;
        cout << "Subject: ";
        cin.ignore();
        getline(cin, subject);
//         book newBook(id, author, name, year, edition, subject);
       
        books.insert(book(next_id++, author, book_name, year_of_publish, edition, subject));
//         books.insert(newBook);
        saveBooksToFile();
        cout << "Book added successfully with ID: " << (next_id - 1) << endl;
    }
  

       
    

    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;

        auto it = books.find(book(id, "", "", 0, 0, ""));
        if (it != books.end()) {
            books.erase(it);
            saveBooksToFile();
            cout << "Book deleted successfully!" << endl;
        } else {
            cout << "Book not found!" << endl;
        }
    }

    void show_all_books() const {
         cout << "| " << setw(4) << "ID" 
             << " | " << setw(6) << "Author" 
             << " | " << setw(13) << "Book Name" 
             << " | " << setw(4) << "Year" 
             << " | " << setw(7) << "Edition" 
             << " | " << setw(8) << "Subject" 
             << " | " << setw(9) << "Borrowed" 
             << " | " << setw(4) << "Due" 
             << " |" << endl;
        // Print separator
        cout << "|------------------------------------------------------------------------------|" << endl;

        for (const auto& b : books) {
            b.display();
        }
    }

    void search_book() const {
        string query;
        cout << "Enter Book Name or ID to search: ";
        cin.ignore();
        getline(cin, query);
        query = trim(query);
        transform(query.begin(), query.end(), query.begin(), ::tolower);
		 cout << "| " << setw(4) << "ID" 
             << " | " << setw(6) << "Author" 
             << " | " << setw(13) << "Book Name" 
             << " | " << setw(4) << "Year" 
             << " | " << setw(7) << "Edition" 
             << " | " << setw(8) << "Subject" 
             << " | " << setw(9) << "Borrowed" 
             << " | " << setw(4) << "Due" 
             << " |" << endl;
        // Print separator
        
        cout << "|------------------------------------------------------------------------------|" << endl;
		 for (const auto& b : books) {
            string bookNameLower = toLowerCase(b.getBookName());
            if (toLowerCase(to_string(b.getId())) == query || bookNameLower == query) {
                b.display();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void register_student() {
        string regNo, studentName;

        cout << "Enter Register Number: ";
        cin >> regNo;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, studentName);

        if (students.find(regNo) != students.end()) {
            cout << "Student already registered!" << endl;
            return;
        }

        students[regNo] = Student(regNo, studentName);
        saveStudentsToFile();
        cout << "Student registered successfully!" << endl;
    }

    bool is_student_registered(const string& regNo) const {
        return students.find(regNo) != students.end();
    }

    void check_and_pay_dues() {
        string regNo;
        cout << "Enter Register Number to check dues: ";
        cin >> regNo;

        auto it = students.find(regNo);
        if (it == students.end()) {
            cout << "Student not registered!" << endl;
            return;
        }

        Student& student = it->second;
        cout << "Current dues for " << student.name << " (" << student.registerNumber << "): $" << student.due << endl;

        if (student.due > 0) {
            char pay;
            cout << "Would you like to pay the dues? (y/n): ";
            cin >> pay;
            if (pay == 'y' || pay == 'Y') {
                student.due = 0;
                saveStudentsToFile();
                cout << "Dues paid successfully!" << endl;
            }
        } else {
            cout << "No dues to pay." << endl;
        }
    }

    void calculate_due() {
        int id;
        cout << "Enter Book ID to calculate due: ";
        cin >> id;

        auto it = books.find(book(id, "", "", 0, 0, ""));
        if (it != books.end()) {
            if (it->getBorrowed() == 1) {
                book b = *it;
                books.erase(it);

                time_t current_time = time(0);
                double days = difftime(current_time, b.getBorrowedDate()) / (60 * 60 * 24);
                int due = static_cast<int>(days) * 5;
                b.setDue(due);

                books.insert(b);
                saveBooksToFile();

                string regNo;
                cout << "Enter student register number for this borrowed book: ";
                cin >> regNo;

                if (is_student_registered(regNo)) {
                    students[regNo].due += due;
                    saveStudentsToFile();
                    cout << "Due amount calculated and added to student's account successfully!" << endl;
                } else {
                    cout << "Student not registered!" << endl;
                }
            } else {
                cout << "The book is not borrowed!" << endl;
            }
        } else {
            cout << "Book not found!" << endl;
        }
    }
    void show_registered_students() const {
//        cout << "| Register Number | Student Name | Due | Borrowed Books |" << endl;
//        cout << "|-----------------|--------------|-----|----------------|" << endl;
//        for (const auto& entry : students) {
//            const Student& s = entry.second;
//            cout << "|" << s.registerNumber << " | " << s.name << " | "<< s.due <<" | "<< s.borrowedBooks << " |" << endl;
//        }
 		const int regNumWidth = 15; // Adjust as necessary
        const int nameWidth = 15;   // Adjust as necessary
        const int dueWidth = 4;     // Width for due
        const int borrowedWidth = 16; // Width for borrowedBooks

        cout << "|" << setw(regNumWidth) << left << "Register Number" 
             << "|" << setw(nameWidth) << left << "Student Name" 
             << "|" << setw(dueWidth) << left << "Due" 
             << "|" << setw(borrowedWidth) << left << "Borrowed Books" 
             << "|" << endl;

        cout << "|" << string(regNumWidth, '-') 
             << "|" << string(nameWidth, '-') 
             << "|" << string(dueWidth, '-') 
             << "|" << string(borrowedWidth, '-') 
             << "|" << endl;

        for (const auto& entry : students) {
            const Student& s = entry.second;
            cout << "|" << setw(regNumWidth) << left << s.registerNumber
                 << "|" << setw(nameWidth) << left << s.name
                 << "|" << setw(dueWidth) << left << s.due
                 << "|" << setw(borrowedWidth) << left << s.borrowedBooks
                 << "|" << endl;
        }
        cout<<endl;
    }

    void borrow_book() {
        int id;
        cout << "Enter Book ID to borrow: ";
        cin >> id;

        auto it = books.find(book(id, "", "", 0, 0, ""));
        if (it != books.end()) {
            if (it->getBorrowed() == 0) {
                book b = *it;
                books.erase(it);

                string regNo;
                cout << "Enter student register number: ";
                cin >> regNo;

                if (is_student_registered(regNo)) {
                    b.setBorrowed(1);
                    b.setBorrowedDate(time(0));
                    books.insert(b);
                    saveBooksToFile();

                    students[regNo].borrowedBooks++;
                    saveStudentsToFile();

                    cout << "Book borrowed successfully!" << endl;
                } else {
                    cout << "Student not registered!" << endl;
                }
            } else {
                cout << "The book is already borrowed!" << endl;
            }
        } else {
            cout << "Book not found!" << endl;
        }
    }

    void return_book() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;

        auto it = books.find(book(id, "", "", 0, 0, ""));
        if (it != books.end()) {
            if (it->getBorrowed() == 1) {
                book b = *it;
                books.erase(it);

                string regNo;
                cout << "Enter student register number: ";
                cin >> regNo;

                if (is_student_registered(regNo)) {
                    b.setBorrowed(0);
                    b.setBorrowedDate(0);
                    books.insert(b);
                    saveBooksToFile();

                    students[regNo].borrowedBooks--;
                    saveStudentsToFile();

                    cout << "Book returned successfully!" << endl;
                } else {
                    cout << "Student not registered!" << endl;
                }
            } else {
                cout << "The book was not borrowed!" << endl;
            }
        } else {
            cout << "Book not found!" << endl;
        }
    }
   
private:
    void loadBooksFromFile() {
        ifstream infile("books.txt");
        string line;
        while (getline(infile, line)) {
            try {
                book b = book::fromString(line);
                books.insert(b);
            } catch (const runtime_error&) {
                cerr << "Error loading book data from file." << endl;
            }
        }
    }

    void loadStudentsFromFile() {
        ifstream infile("students.txt");
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            string regNo, name, token;
            int due, borrowedBooks;

            getline(ss, regNo, ',');
            getline(ss, name, ',');
            getline(ss, token, ',');
            due = stoi(token);
            getline(ss, token, ',');
            borrowedBooks = stoi(token);

            students[regNo] = Student(regNo, name, due, borrowedBooks);
        }
    }

    void saveBooksToFile() const {
        ofstream outfile("books.txt");
        for (const auto& b : books) {
            outfile << b.toString() << endl;
        }
    }

    void saveStudentsToFile() const {
        ofstream outfile("students.txt");
        for (const auto& entry : students) {
            const Student& s = entry.second;
            outfile << s.registerNumber << "," << s.name << "," << s.due << "," << s.borrowedBooks << endl;
        }
    }
//	void show_registered_students() const {
//    cout << "| Register Number | Student Name |" << endl;
//    cout << "|-----------------|--------------|" << endl;
//    for (const auto& entry : students) {
//        const Student& s = entry.second;
//        cout << "| " << setw(15) << s.registerNumber << " | " << setw(12) << s.name << " |" << endl;
//    }
//	}


};
 void options_student() {
    cout << "--------------------STUDENT--------------------" << endl;
    cout << "1. " << setw(40) << left << "BORROW BOOK" << endl;
    cout << "2. " << setw(40) << left << "RETURN BOOK" << endl;
    cout << "3. " << setw(40) << left << "SHOW ALL BOOK DETAILS" << endl;
    cout << "4. " << setw(40) << left << "SEARCH BOOK" << endl;
    cout << "5. " << setw(40) << left << "CHECK AND PAY DUES" << endl;
    cout << "0. " << setw(40) << left << "EXIT" << endl;
}
void options_admin() {
    cout << "--------------------ADMIN--------------------" << endl;
    cout << "1. " << setw(40) << left << "ADD BOOK" << endl;
    cout << "2. " << setw(40) << left << "DELETE BOOK" << endl;
    cout << "3. " << setw(40) << left << "SHOW ALL BOOKS" << endl;
    cout << "4. " << setw(40) << left << "SEARCH BOOK" << endl;
    cout << "5. " << setw(40) << left << "REGISTER STUDENT" << endl;
    cout << "6. " << setw(40) << left << "CALCULATE DUE" << endl;
    cout << "7. " << setw(40) << left << "CHECK AND PAY DUES" << endl;
    cout << "8. " << setw(40) << left << "SHOW REGISTERED STUDENTS" << endl;  // New option
    cout << "0. " << setw(40) << left << "EXIT" << endl;
}


// Main function
int main() {
    library lib;
    int choice;

    while (true) {
        cout << "--------------------MAIN MENU--------------------" << endl;
        cout << "1. ADMIN" << endl;
        cout << "2. STUDENT" << endl;
        cout << "0. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            while (true) {
                options_admin();
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 0) break;

                switch (choice) {
                    case 1:
                        lib.addBook();
                        break;
                    case 2:
                        lib.deleteBook();
                        break;
                    case 3:
                        lib.show_all_books();
                        break;
                    case 4:
                        lib.search_book();
                        break;
                    case 5:
                        lib.register_student();
                        break;
                    case 6:
                        lib.calculate_due();
                        break;
                    case 7:
                        lib.check_and_pay_dues();
                        break;
                	case 8:
                		lib.show_registered_students();
                		break;
                    default:
                        cout << "Invalid choice, try again." << endl;
                }
            }
        } else if (choice == 2) {
            while (true) {
                options_student();
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 0) break;

                switch (choice) {
                    case 1:
                        lib.borrow_book();
                        break;
                    case 2:
                        lib.return_book();
                        break;
                    case 3:
                        lib.show_all_books();
                        break;
                    case 4:
                        lib.search_book();
                        break;
                    case 5:
                        lib.check_and_pay_dues();
                        break;
                    default:
                        cout << "Invalid choice, try again." << endl;
                }
            }
        } else {
            cout << "Invalid choice, try again." << endl;
        }
    }

    return 0;
}


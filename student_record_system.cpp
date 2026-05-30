#include <iostream>
#include <string>

const int MAX_STUDENTS = 50;

void input_single_student(int& count, int scores[], std::string names[]);
void display_students(int count, const int scores[], const std::string names[]);
void top_student(const int scores[], int count, const std::string names[]);
double calculate_average(int count, const int scores[]);
void search_student(const std::string& target, int count, const std::string names[], const int scores[]);

int main() {
    std::string names[MAX_STUDENTS];
    int scores[MAX_STUDENTS];
    int count = 0; 
  
    while (true) {
        std::cout << "\n=== Student Record System ===\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Students\n";
        std::cout << "3. Highest Score\n";
        std::cout << "4. Search student\n";
        std::cout << "5. Average Score\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        
        int choice = 0;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        std::cin.ignore(1000, '\n');
      
        switch (choice) {
            case 1: 
                if (count < MAX_STUDENTS) {
                    input_single_student(count, scores, names);
                } else {
                    std::cout << "Database is full!\n";
                }
                break;
          
            case 2: 
                if (count == 0) std::cout << "No student data available\n";
                else display_students(count, scores, names);
                break;
        
            case 3: 
                if (count == 0) std::cout << "No student data available\n";
                else top_student(scores, count, names);
                break;
        
            case 4: {
                if (count == 0) {
                    std::cout << "No student data available\n";
                } else {
                    std::string target;
                    std::cout << "Enter student name to search: ";
                    std::getline(std::cin, target);
                    search_student(target, count, names, scores);
                }
                break;
            }
        
            case 5: 
                if (count == 0) std::cout << "No student data available\n";
                else std::cout << "Average: " << calculate_average(count, scores) << '\n';
                break;
        
            case 6:
                std::cout << "Exiting system.....\n";
                return 0; 
            
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}

void input_single_student(int& count, int scores[], std::string names[]) {
    std::cout << "Enter name: ";
    std::getline(std::cin, names[count]);
    
    std::cout << "Enter score: ";
    std::cin >> scores[count];
    std::cin.ignore(1000, '\n'); 
    
    count++; 
    std::cout << "Student added successfully!\n";
}

void display_students(int count, const int scores[], const std::string names[]) {
    for (int j = 0; j < count; ++j) {
        std::cout << names[j] << " scored: " << scores[j] << '\n';
    } 
}

void top_student(const int scores[], int count, const std::string names[]) {
    int max = scores[0];
    
    std::string top_scorer = names[0];
   
    for (int j = 1; j < count; ++j) { 
        if (scores[j] > max) {
            max = scores[j];
            top_scorer = names[j];
        }
    }
    std::cout << top_scorer << " has the highest mark: " << max << '\n';
}

double calculate_average(int count, const int scores[]) {
    int total = 0;
    for (int j = 0; j < count; ++j) {
        total += scores[j]; 
    }
    return static_cast<double>(total) / count; 
}

void search_student(const std::string& target, int count, const std::string names[], const int scores[]) {
    bool found = false;
    for (int j = 0; j < count; ++j) {
        if (target == names[j]) {
            found = true;
            std::cout << names[j] << " scored " << scores[j] << '\n';
        }
    }
    if (!found) {
         std::cout << "Student not found\n";
    } 
}

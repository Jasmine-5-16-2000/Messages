#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// Message structure
struct Message {
    string sender;
    string content;
    time_t timestamp;

    // Constructor to initialize timestamp automatically
    Message(const string& sender, const string& content) 
        : sender(sender), content(content), timestamp(time(nullptr)) {}
};

// Function to display the menu
void displayMenu() {
    cout << "\n===== Messaging App =====" << endl;
    cout << "1. Send Message" << endl;
    cout << "2. View Messages" << endl;
    cout << "3. Quit" << endl;
    cout << "=========================" << endl;
}

// Function to clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to send a message
void sendMessage(vector<Message>& messages) {
    string sender, content;
    cout << "Enter sender's name: ";
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, sender);
    cout << "Enter message content: ";
    getline(cin, content);

    // Create and add message to vector
    messages.emplace_back(sender, content);
    cout << "Message sent successfully." << endl;
}

// Function to view all messages
void viewMessages(const vector<Message>& messages) {
    cout << "\n===== Messages =====" << endl;
    if (messages.empty()) {
        cout << "No messages." << endl;
    } else {
        for (const auto& msg : messages) {
            cout << "Sender: " << msg.sender << endl;
            cout << "Content: " << msg.content << endl;
            cout << "Timestamp: " << ctime(&msg.timestamp); // Convert timestamp to string
            cout << "-------------------" << endl;
        }
    }
    cout << "====================" << endl;
}

int main() {
    vector<Message> messages;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sendMessage(messages);
                break;
            case 2:
                viewMessages(messages);
                break;
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                clearInputBuffer(); // Clear input buffer in case of invalid input
        }

    } while (choice != 3);

    return 0;
}

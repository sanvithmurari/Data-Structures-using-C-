#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Browser{
    stack<string> back;
    stack<string> front;
    vector<string> history;
    public:
    string current;
    Browser(){
        current="";
    }

    void visit_new_page(string newpage){
        if(current!=""){ 
            back.push(current);
        }
        current = newpage;
        while(!front.empty()){
            front.pop();
        }
        history.push_back(current);
    }

    void go_back(){
        if(back.empty()){
            cout<<"No previous pages!\n";
            return;
        }
        front.push(current);
        current=back.top();
        back.pop();
        cout<<"Current page:"<<current<<endl;
    }

    void go_front(){
        if(front.empty()){
            cout<<"No forward pages\n";
            return;
        }
        back.push(current);
        current=front.top();
        front.pop();
        cout<<"Current page: "<<current<<endl;
    }

    void close_page(string page){
         if(current == page){

            cout << page << " closed.\n";

            if(!back.empty()){

                current = back.top();
                back.pop();

                cout << "Now current page: " << current << endl;
            }
            else{
                current = "";
                cout << "No pages open now.\n";
            }
        }
        
        stack<string> temp;
        bool found = false;

        while(!back.empty()){

            if(back.top() == page){
                found = true;
                back.pop();
                break;
            }

            temp.push(back.top());
            back.pop();
        }
        while(!temp.empty()){
            back.push(temp.top());
            temp.pop();
        }

        stack<string> temp2;

        while(!front.empty()){

            if(front.top() == page){
                found = true;
                front.pop();
                break;
            }

            temp2.push(front.top());
            front.pop();
        }

        while(!temp2.empty()){
            front.push(temp2.top());
            temp2.pop();
        }

        if(found){
            cout << page << " closed successfully.\n";
        }
        else{
            cout << "Page not found!\n";
        }
    }

    void show_history(){
        if(history.empty()){
        cout << "No browsing history available!\n";
        return;
        }
        cout << "\n===== Browsing History =====\n";
        for(int i = 0; i < history.size(); i++){
        cout << i + 1 << ". " << history[i] << endl;
        }
    }

    void clear_history(){
        while(!back.empty()){
            back.pop();
        }
        while(!front.empty()){
            front.pop();
        }

        history.clear();

        cout << "Browsing history cleared!\n";
    }
};

int main() {
    Browser myBrowser;
    int choice;
    string pageName;

    do {
        // 1st: Display the menu options
        cout << "\n========== BROWSER MENU ==========\n";
        cout << "1. Visit New Page\n";
        cout << "2. Go Back\n";
        cout << "3. Go Front\n";
        cout << "4. Close Page\n";
        cout << "5. Show Browser History\n";
        cout << "6. Clear Browser History\n";
        cout << "7. Exit\n";
        cout << "==================================\n";
        
        // 2nd: Take input choice from the user
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        // Run through switch cases based on user input
        switch (choice) {
            case 1:
                cout << "Enter the name of the new page: ";
                cin >> pageName;
                myBrowser.visit_new_page(pageName);
                cout << "Successfully visited: " << myBrowser.current << "\n";
                break;
                
            case 2:
                myBrowser.go_back();
                break;
                
            case 3:
                myBrowser.go_front();
                break;
                
            case 4:
                cout << "Enter the name of the page to close: ";
                cin >> pageName;
                myBrowser.close_page(pageName);
                break;
            
            case 5:
                myBrowser.show_history();
                break;

            case 6:
                myBrowser.clear_history();
                break;
                
            case 7:
                cout << "Exiting the browser...\n";
                break;
                
            default:
                cout << "Invalid choice! Please select a valid option (1-6).\n";
                break;
        }
    } while (choice != 6);
    return 0;
}
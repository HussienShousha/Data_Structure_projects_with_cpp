#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Patient{
private:
    string name;
    int age ;
    string condition;
    int priority;
public:
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        this->name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    const string &getCondition() const {
        return condition;
    }

    void setCondition(const string &condition) {
        this->condition = condition;
    }

    int getPriority() const {
        return priority;
    }

    void setPriority() {
        if (condition=="critical")priority=3;
        else if (condition=="urgent")priority=2;
        else priority=1;

    }
    void displayPatient(){
        cout<<"Name: "<<this->getName()<<", "<<"Age: "<< this->getAge()<<", "<<"Condition: "<<this->getCondition()<<", "<<"Priority: "<< this->getPriority()<<endl;
    }
};
class QueueOfPatient{
private:
    struct Node{
        Patient item;
        Node* next;
    };
    Node* front;
    int length=0;
public:
    QueueOfPatient(){
        front=NULL;
    }
    void AddPatient(string name,int age,string condition){
        if(condition!="normal" and condition!="urgent" and condition!="critical"){
            cout<<"this "<<'('<<condition<<')'<<" is not a condition in our system..."<<endl;
            return;
        }
        Node* newNode=new Node;
        newNode->item.setName(name);
        newNode->item.setCondition(condition);
        newNode->item.setAge(age);
        newNode->item.setPriority();
        Node* current=front;
        Node* prev=NULL;
        if(!isEmpty() and search(newNode->item.getName(),newNode->item.getAge(),newNode->item.getCondition(),newNode->item.getPriority())){
            cout<<"this patient is already in queue..."<<endl;
            return;
        }
        if(front==NULL){
            front=newNode;
            newNode->next=NULL;
        }
        else {
            while (current!=NULL and newNode->item.getPriority()<=current->item.getPriority()){
                prev=current;
                current=current->next;
            }
            newNode->next=current;
            prev->next=newNode;
        }
        length++;
        cout<<"Patient "<<newNode->item.getName()<<" added to the queue."<<endl;
    }
    void ProcessPatient(){
        if(isEmpty()){
            cout<<"queue does not contain any patients..."<<endl;
            return;
        }
        cout<<"Processing Patient..."<<endl;
        cout<<"Processing Patient: "<<front->item.getName()<<" "<<'('<<"Priority"<<": "<<front->item.getPriority()<<')'<<endl;
        popFront();
    }

    bool isEmpty(){
        return length==0;
    }

    void clear(){
        while (!isEmpty()){
            popFront();
        }
        front=NULL;
    }
    void popFront(){
        if(!isEmpty()){
            Node* temp=front;
            front=front->next;
            length--;
            temp->next=NULL;
            delete temp;
        }
    }
    bool search(string name,int age,string condition,int priority){
        Node* cur=front;
        while (cur!=NULL){
            if(cur->item.getName()==name and cur->item.getAge()==age and cur->item.getCondition()==condition and cur->item.getPriority()==priority)
                return true;
            cur=cur->next;
        }
        return false;
    }
    void UpdateAndOrder(string name,int age,string condition,string newCondition){
        int priority;
        if (condition=="critical")priority=3;
        else if (condition=="urgent")priority=2;
        else priority=1;

        Node* cur=front;
        while (cur!=NULL){
            if(cur->item.getName()==name and cur->item.getAge()==age and cur->item.getCondition()==condition and cur->item.getPriority()==priority)
                break;
            cur=cur->next;
        }
        cur->item.setCondition(newCondition);
        cur->item.setPriority();
        if(cur->next==NULL)
            return;
        Node* after=cur->next;
        while (after!=NULL and cur->item.getPriority()<after->item.getPriority()){
            swap(cur->item,after->item);
            cur=after;
            after=after->next;
        }
        cout<<"Priority/Condition of patient "<<name<<" updated to "<<newCondition<<endl;
    }

    void UpdatePatient(string name,int age,string condition,string newCondition){
        if(newCondition!="normal" and newCondition!="urgent" and newCondition!="critical"){
            cout<<"this "<<'('<<condition<<')'<<" is not a condition in our system..."<<endl;
            return;
        }

        if(isEmpty()){
            cout<<"queue does not contain any patients..."<<endl;
            return;
        }
        if(condition==newCondition){
            cout<<name<<" has same Priority..."<<endl;
            return;
        }
        else{
            int p;
            if (condition=="critical")p=3;
            else if (condition=="urgent")p=2;
            else p=1;

            if(search(name,age,condition,p)){
                UpdateAndOrder(name,age,condition,newCondition);
                return;
            }
            else {
                cout<<name<<" not in queue..."<<endl;
                return;
            }
        }
    }
    int Size(){
        return length;
    }
    void FrontName(){
        if(!isEmpty()){
            cout<<"Front Patient Name: "<<front->item.getName()<<endl;
        }
        else cout<<"queue does not contain any patients..."<<endl;
    }
    void display_queue(){
        Node* cur=front;
        if(isEmpty()){
            cout<<"queue does not contain any patients..."<<endl;
            return;
        }
        cout<<"Current Patients in the Queue: "<<endl;
        while(cur!=NULL){
            cur->item.displayPatient();
            cur=cur->next;
        }

    }
    ~QueueOfPatient(){
        clear();
    }
};

struct Variable{
    string name;
    string dataType;
    string value;
};
void DisplayVariable(Variable v){
    cout<<"name: "<<v.name<<", "<<"Type: "<<v.dataType<<", "<<"Value: "<<v.value<<';';
}
class Stack {
    struct node {
        Variable item;
        node *next;
    };
    node *top;
    int length=0;
public:
    Stack() {
        top = NULL;
    }

    void push(Variable newItem) {
        node *newNode = new node;
        newNode->item.name = newItem.name;
        newNode->item.value=newItem.value;
        newNode->item.dataType=newItem.dataType;
        newNode->next = top;
        top = newNode;
        length++;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void pop() {
        if (isEmpty())
            return;
        node *temp = top;
        top = top->next;
        // temp=temp->next=NULL;
        temp->next = NULL;
        length--;
        delete temp;
    }
    void DisplayStack(){
        node*temp=top;
        cout<<"Stack contents:"<<endl;
        while (temp!=NULL) {
            Variable v=temp->item;
            DisplayVariable(v);
            cout<<endl;
            temp=temp->next;
        }
    }
    void clear() {
        while (!isEmpty()) {
            pop();
        }top=NULL;
    }
    void update(string variableName, string newValue){
        node* temp=top;
        while (temp!=NULL) {
            if (temp->item.name==variableName) {
                temp->item.value = newValue;
                break;
            }
            temp=temp->next;

        }
    }
    ~Stack(){
        clear();
    }
};

Stack stackOfVariables;
//  int x = 4;
void ProcessLine(string line) {
    string toBePushed = "";
    int sizeOfLine = line.size();
    Variable v;
    bool flag= true;
    if (line.find("int") != string::npos || line.find("double") != string::npos || line.find("float") != string::npos || line.find("char") != string::npos) {
        for (int i = 0; i < sizeOfLine; ++i) {
            if (line[i] != ' ') {
                if (line[i] == '=') {
                    v.name = toBePushed;
                    toBePushed.clear();
                } else if (line[i] == ';') {
                    flag= true;
                    if((toBePushed>="a" and toBePushed <="z") or (toBePushed>="A" and toBePushed<="Z") ){
                        v.name = toBePushed;
                        if(v.dataType=="int")
                            v.value='0';
                        else if(v.dataType=="double")
                            v.value="0.0";
                        else if(v.dataType=="float")
                            v.value="0.0";
                        else v.value=' ';

                    }
                    else v.value=toBePushed;
                    toBePushed.clear();
                    stackOfVariables.push(v);
                    stackOfVariables.DisplayStack();
                } else {
                    toBePushed += line[i];
                }
            } else if (!toBePushed.empty() and flag) {
                v.dataType = toBePushed;
                toBePushed.clear();
                flag= false;
            }
        }
    } else {
        string variableName, newValue;
        for (int i = 0; i < sizeOfLine; ++i) {
            if (line[i] != ' ') {
                if (line[i] == '=') {
                    variableName = toBePushed;
                    toBePushed.clear();
                } else if (line[i] == ';') {
                    newValue = toBePushed;
                    toBePushed.clear();
                    stackOfVariables.update(variableName, newValue);
                    stackOfVariables.DisplayStack();

                } else {
                    toBePushed += line[i];
                }
            }
        }
    }
}

void ProcessFile(){
    ifstream myFile("code.txt");
    if (myFile.is_open()) {
        string line;
        while (getline(myFile, line)) {
            if (line.find("int main()") != string::npos || line.find('{')!=string::npos) {
                continue;
            }
            else if(line.find("return 0")!=string::npos){
                cout<<"Reached return 0;"<<endl;
                if(!stackOfVariables.isEmpty())stackOfVariables.DisplayStack();
                else cout<<"there is no variables"<<endl;
                stackOfVariables.clear();
                break;
            }
            else{
                ProcessLine(line);
            }
            myFile.ignore();
        }
        myFile.close();
        }
    else {
        cout << "Error: Unable to open the file" <<endl;
    }

}
int main() {
    // ################################task 1#########################################################
    QueueOfPatient queue;
    bool flag=true;
    while (true ) {
        if(!flag){
            break;
        }
        cout << "-----------------------------------" <<endl;
        cout << "Emergency Room Management System" <<endl;
        cout << "-----------------------------------" <<endl;
        cout << "1. Add Patient" <<endl;
        cout << "2. Process Patient" <<endl;
        cout << "3. Update Patient" <<endl;
        cout << "4. Display Queue" <<endl;
        cout << "5. Queue Size" <<endl;
        cout << "6. Front Name" <<endl;
        cout << "7. Exit" <<endl;
        cout << "-----------------------------------" <<endl;
        cout << "Enter your choice (1-7): ";
        char choice;
        cin >> choice;
        if((choice>='a' and choice<='z') or (choice>='A' and choice<='Z'))
            return 0;
        int digit =stoi(string(1, choice));
        switch (digit) {
            case 1: {
                string name, condition;
                int age;
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter patient age: ";
                cin >> age;
                cout << "Enter patient condition (normal, urgent, critical): ";
                cin.ignore();
                cin >> condition;
                cout<<endl;
                queue.AddPatient(name, age, condition);
                break;
            }
            case 2:
                queue.ProcessPatient();
                break;
            case 3: {
                string name, condition;
                int age;
                cout <<"Enter patient name: ";
                cin >> name;
                cout <<"Enter patient age: ";
                cin >> age;
                cout <<"Enter past condition (normal, urgent, critical): ";
                cin >> condition;
                cout<<endl;
                string newCondition;
                cout <<"Enter new condition (normal, urgent, critical): ";
                cin>>newCondition;
                cout<<endl;
                queue.UpdatePatient(name,age,condition,newCondition);
                break;
            }
            case 4:
                queue.display_queue();
                break;
            case 5:
                cout <<"Queue size: " << queue.Size() <<endl;
                break;
            case 6:
                queue.FrontName();
                break;
            case 7:
                cout << "Exiting..." << endl;
                flag= false;
                break;
            default:
                cout <<"Invalid choice. Please try again." <<endl;
                break;
        }
    }
    // ###################task 2###################################################
    ProcessFile();




    return 0;
}



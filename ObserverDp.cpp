#include <iostream>
#include <vector>
#include <list>
using namespace std; 
class Observer{
    public:
    virtual void update(string message) = 0;
};

class ConcreteObserver : public Observer
{
    public:
    ConcreteObserver(string name1): name(name1)
    {
        cout<<"Observer created with name : "<<name<<endl;
    }
    void update(string message)
    {
        cout<<name<<" received message  : "<<message<<endl;
    }

    private:
    string name; 
};


class Subject{
    public:
        virtual void addObserver(Observer *observer) = 0;
        virtual void removeObserver(Observer *observer) = 0;
        virtual void notify() = 0;
};


class ConcreteSubject : public Subject
{
    public:
    void addObserver(Observer* observer) override
    {
        observerlist.push_back(observer);
    }
    void removeObserver(Observer* observer) override
    {
        observerlist.remove(observer);
    }
    void sendMessage(string message)
    {
        this->message = message; 
        std::cout<<"Sending this message to observers  : "<<message<<std::endl;
        notify();
    }
    void notify()
    {
        for(auto a : observerlist)
        {
            a->update(message);
        }
    }

    private :
    std::list<Observer*> observerlist; 
    std::string message;
};


int main() {
    ConcreteSubject subject;

    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    // Add observers to the subject
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    subject.sendMessage("Hello, observers!");

    // Remove observer2
    subject.removeObserver(&observer2);

    subject.sendMessage("Observer 2 has been removed.");

    return 0;
}

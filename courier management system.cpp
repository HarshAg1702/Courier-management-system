#include <bits/stdc++.h>
using namespace std;

class Feedback
{
private:
    int idnum, rating;
    string feed;

public:
    void getNumFeedback()
    {
        cout << "Please rate our service (out of 5): ";
        cin >> rating;
        cout << "Enter customer ID: ";
        cin >> idnum;
        ofstream fout("feedbacks.txt", ios::app);
        fout << "ID:" << idnum << "\n";
        fout << "Rating:" << rating << "\n";
        fout.close();
    }

    void getTextFeedback()
    {
        ofstream fout("feedbacks.txt", ios::app);
        cout << "Feedback (limit 200 words): ";
        cin.ignore();
        getline(cin, feed);
        fout << "Feedback:" << feed << "\n";
        fout.close();
    }
};

class Customer : public Feedback
{
public:
    int weight, distane, date, dat;
    string name, email, contact, provision, takeaway, shipping;

    float calculatePrice(int weight, int distance)
    {
        return (weight * distance * 0.1);
    }
    void customerDetails()
    {
        ifstream file("CustomersDetails.txt");
        int count = 0;
        string str;
        while (getline(file, str))
        {

            istringstream ss(str);
            do
            {
                string word;
                ss >> word;
                cout << word << "\t";
            } while (ss);
            cout << "\n\n ";
        }

        file.close();
    }
};

class Admin
{
public:
    string name = "name", password = "pass";
};
int main()
{
    bool check = false;
    string name, password, str;
    Admin admin;
    Customer customer;
    ofstream outfile;
    ifstream infile;
    int login, payment;
    int choice, count;
    while (1)
    {

        cout << "////*****  Welcome to Courier Management System" << endl;
        cout << "////*****                                   " << endl;
        cout << "////*****  Enter 1 for Admin " << endl;
        cout << "////*****  Enter 2 for Recipent " << endl;

        cout << "////*****  Enter 3 for Feedback" << endl;
        cout << "////*****  Enter 4 for parcel tracking" << endl;
        cout << "////*****  Press Any other key to exit" << endl;

        cin >> login;

        switch (login)
        {
        case 1:
            cout << "Enter User Name " << endl;
            cin >> name;
            cout << "Enter Password " << endl;
            cin >> password;
            if ((name == admin.name) && (password == admin.password))
            {

                cout << "You are Successfully  Login!" << endl;
                cout << " \n All the list of Customers " << endl;
                ifstream file("CustomersDetails.txt");
                count = 0;
                while (getline(file, str))
                {

                    istringstream ss(str);
                    do
                    {
                        string word;
                        ss >> word;
                        cout << word << "   \t";

                    } while (ss);
                    cout << "\n"
                         << endl;
                }
                file.close();
            }
            else
            {
                cout << "Your Password OR UserName is Wrong " << endl;
            }

            break;
        case 2:
            cout << "Customer Name" << endl;
            cin >> customer.name;
            cout << "Enter Weight" << endl;
            cin >> customer.weight;
            cout << "Enter Distance" << endl;
            cin >> customer.distane;
cout << "Enter Your Provision" << endl;
            cin >> customer.provision;
            cout << "Enter Email" << endl;
            cin >> customer.email;
            cout << "Enter Contact" << endl;
            cin >> customer.contact;
            cout << "enter city of parcel takeaway" << endl;
            cin >> customer.takeaway;
            cout << "enter shipping city" << endl;
            cin >> customer.shipping;
            cout << "enter date" << endl;
            cin >> customer.date;
            cout << "your total bill is" << customer.calculatePrice(customer.distane, customer.weight) << endl;
            cout << "enter payment method:" << endl
                 << "select 1 for upi payments" << endl
                 << "select 2 for cash on delivery" << endl;
            cin >> payment;
            if (payment == 1)
            {
                cout << "upi id is 8887509892@paytm" << endl;
            }
            else if (payment == 2)
            {
                cout << "you have to pay at the time of delivery" << endl;
            }
            else
            {
                cout << "please enter valid key" << endl;
            }
            outfile.open("CustomersDetails.txt", std::ios_base::app);
            outfile << "Name " << customer.name << endl;
            outfile << "Email " << customer.email << endl;
            outfile << "Contact " << customer.contact << endl;
            outfile << "Distance " << customer.distane << endl;
            outfile << "Provision " << customer.provision << endl;
            outfile << "Weight " << customer.weight << endl;
            outfile << "Charge " << customer.calculatePrice(customer.distane, customer.weight) << endl;
            outfile.close();

            break;
        case 3:
            customer.getNumFeedback();
            customer.getTextFeedback();
            break;
        default:
            cout << "Have a Nice day" << endl;
            exit(1);

        case 4:
            int date, dat;
            string takeaway, shipping;
            cout << "enter name";
            cin >> name;
            cout << "enter date";
            cin >> date;
            cout << "enter application date";
            cin >> dat;
            cout << "enter takeaway city";
            cin >> takeaway;
            cout << "enter shipping city";
            cin >> shipping;
            if (date == dat)
            {

                cout << "your parcel is in"
                     << "" << takeaway << endl;
            }

            else
            {
                cout << "your parcel is in"
                     << "" << shipping << endl;
                cout << "your parcel will be delivered shortly";
            }
        }
    }
    return 0;
}
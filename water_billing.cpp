#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class WaterCustomer
{
protected:
    int customerId;
    string customerName;
    double waterConsumption;

public:
    WaterCustomer(int id = 0, string name = "", double consumption = 0)
    {
        customerId = id;
        customerName = name;
        waterConsumption = consumption;
    }

    // Pure virtual function - makes this an abstract class
    virtual double calculateBill() const = 0;

    virtual string getCustomerType() const = 0;

    virtual void displayDetails() const
    {
        cout << "\n----------------------------------------" << endl;
        cout << "Customer ID       : " << customerId << endl;
        cout << "Customer Name     : " << customerName << endl;
        cout << "Customer Type     : " << getCustomerType() << endl;
        cout << "Water Consumption : "
             << waterConsumption << " units" << endl;
    }

    virtual void displayBill() const
    {
        displayDetails();

        cout << fixed << setprecision(2);
        cout << "Water Bill        : Rs. "
             << calculateBill() << endl;

        cout << "----------------------------------------" << endl;
    }

    virtual ~WaterCustomer()
    {
    }
};

class DomesticCustomer : public WaterCustomer
{
public:
    DomesticCustomer(int id, string name, double consumption)
        : WaterCustomer(id, name, consumption)
    {
    }

    double calculateBill() const override
    {
        double bill = 0;

        if (waterConsumption <= 15)
        {
            bill = waterConsumption * 5.0;
        }
        else if (waterConsumption <= 30)
        {
            bill = (15 * 5.0)
                 + ((waterConsumption - 15) * 7.0);
        }
        else
        {
            bill = (15 * 5.0)
                 + (15 * 7.0)
                 + ((waterConsumption - 30) * 10.0);
        }

        return bill;
    }

    string getCustomerType() const override
    {
        return "Domestic";
    }
};

class CommercialCustomer : public WaterCustomer
{
public:
    CommercialCustomer(int id, string name, double consumption)
        : WaterCustomer(id, name, consumption)
    {
    }

    double calculateBill() const override
    {
        double bill = 0;

        if (waterConsumption <= 20)
        {
            bill = waterConsumption * 10.0;
        }
        else if (waterConsumption <= 50)
        {
            bill = (20 * 10.0)
                 + ((waterConsumption - 20) * 12.0);
        }
        else
        {
            bill = (20 * 10.0)
                 + (30 * 12.0)
                 + ((waterConsumption - 50) * 15.0);
        }

        return bill;
    }

    string getCustomerType() const override
    {
        return "Commercial";
    }
};

void generateBill(WaterCustomer* customer)
{
    customer->displayBill();
}

int main()
{
    int choice;

    cout << fixed << setprecision(2);

    do
    {
        cout << "\n";
        cout << "============================================" << endl;
        cout << "       WATER SUPPLY BILLING SYSTEM" << endl;
        cout << "============================================" << endl;
        cout << "1. Domestic Customer" << endl;
        cout << "2. Commercial Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name;
            double consumption;

            cout << "\n---------- DOMESTIC CUSTOMER ----------" << endl;

            cout << "Enter Customer ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Customer Name: ";
            getline(cin, name);

            cout << "Enter Water Consumption (units): ";
            cin >> consumption;

            if (consumption < 0)
            {
                cout << "\nInvalid consumption value!" << endl;
                cout << "Water consumption cannot be negative." << endl;
                continue;
            }

            DomesticCustomer domestic(id, name, consumption);

            WaterCustomer* customer = &domestic;

            generateBill(customer);
        }
        else if (choice == 2)
        {
            int id;
            string name;
            double consumption;

            cout << "\n--------- COMMERCIAL CUSTOMER ---------" << endl;

            cout << "Enter Customer ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Customer Name: ";
            getline(cin, name);

            cout << "Enter Water Consumption (units): ";
            cin >> consumption;

            if (consumption < 0)
            {
                cout << "\nInvalid consumption value!" << endl;
                cout << "Water consumption cannot be negative." << endl;
                continue;
            }

            CommercialCustomer commercial(id, name, consumption);

            WaterCustomer* customer = &commercial;

            generateBill(customer);
        }
        else if (choice == 3)
        {
            cout << "\n============================================" << endl;
            cout << " Thank you for using Water Supply Billing!" << endl;
            cout << "============================================" << endl;
        }
        else
        {
            cout << "\nInvalid choice!" << endl;
            cout << "Please select option 1, 2 or 3." << endl;
        }

    } while (choice != 3);

    return 0;
}

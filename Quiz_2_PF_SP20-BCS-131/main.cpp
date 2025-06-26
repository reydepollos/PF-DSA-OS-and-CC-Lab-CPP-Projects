#include <iostream>

using namespace std;

double  apple = 2, banana = 1, orange = 3, mango = 5, grapes = 4, TotalPayout=0;
const int tex = 5;

double calculateTotal(double price, int quantity);
void applyDiscount(double &totalBill);
void DisplayMenu();

int main()
{
    int quantity=0;
    double result=0,totalBill=0,discount=0,texValue=0;
    char ch = 'y';

    while(ch=='y' || ch=='Y')
    {
        cout << "=========================\nWelcome to Shopping Cart.\n=========================" << endl;
        DisplayMenu();
        int options;
        cout<<endl;
        cout<<"Enter Option from (1-6) and 0 for Exit = ";
        cin>>options;
        switch(options)
        {
        case 1:
        {
            cout<<"Enter the Quantity of Apple = ";
            cin>>quantity;
            totalBill = calculateTotal(apple,quantity);
            cout<<"Price of "<<quantity<<" Apples = "<<totalBill<<endl;
            if(totalBill>=50)
            {
                applyDiscount(totalBill);
            }
            else
            {
                cout<<"Discount = "<<discount<<endl;
            }
            cout<<endl<<"Total Bill = "<<totalBill<<endl;
            TotalPayout = TotalPayout + totalBill;
            cout<<"Total Payout = "<<TotalPayout<<endl;
            break;
        }
        case 2:
        {
            cout<<"Enter the Quantity of Banana = ";
            cin>>quantity;
            totalBill = calculateTotal(banana,quantity);
            cout<<"Price of "<<quantity<<" Bananas = "<<totalBill<<endl;
            if(totalBill>=50)
            {
                applyDiscount(totalBill);
            }
            else
            {
                cout<<"Discount = "<<discount<<endl;
            }
            cout<<endl<<"Total Bill = "<<totalBill<<endl;
            TotalPayout = TotalPayout + totalBill;
            cout<<"Total Payout = "<<TotalPayout<<endl;
            break;
        }
        case 3:
        {
            cout<<"Enter the Quantity of Orange = ";
            cin>>quantity;
            totalBill = calculateTotal(orange,quantity);
            cout<<"Price of "<<quantity<<" Oranges = "<<totalBill<<endl;
            if(totalBill>=50)
            {
                applyDiscount(totalBill);
            }
            else
            {
                cout<<"Discount = "<<discount<<endl;
            }
            cout<<endl<<"Total Bill = "<<totalBill<<endl;
            TotalPayout = TotalPayout + totalBill;
            cout<<"Total Payout = "<<TotalPayout<<endl;
            break;
        }
        case 4:
        {
            cout<<"Enter the Quantity of Mango = ";
            cin>>quantity;
            totalBill = calculateTotal(mango,quantity);
            cout<<"Price of "<<quantity<<" Mangoes = "<<totalBill<<endl;
            if(totalBill>=50)
            {
                applyDiscount(totalBill);
            }
            else
            {
                cout<<"Discount = "<<discount<<endl;
            }
            cout<<endl<<"Total Bill = "<<totalBill<<endl;
            TotalPayout = TotalPayout + totalBill;
            cout<<"Total Payout = "<<TotalPayout<<endl;
            break;
        }
        case 5:
        {
            cout<<"Enter the Quantity of Grapes = ";
            cin>>quantity;
            totalBill = calculateTotal(grapes,quantity);
            cout<<"Price of "<<quantity<<" Grapes = "<<totalBill<<endl;
            if(totalBill>=50)
            {
                applyDiscount(totalBill);
            }
            else
            {
                cout<<"Discount = "<<discount<<endl;
            }
            cout<<endl<<"Total Bill = "<<totalBill<<endl;
            TotalPayout = TotalPayout + totalBill;
            cout<<"Total Payout = "<<TotalPayout<<endl;
            break;
        }
        case 6:
            {
                texValue = (TotalPayout*tex)/100;
                cout<<endl<<"Calculated 5% Tex on Total Amount "<<TotalPayout<<" = "<<texValue<<endl;
            }
        case 0:
        {
            return 0;
        }
        default:
        {
            cout<<"You have Entered Invalid Entry."<<endl;
        }

        }

        cout<<"Enter the (y/Y) for Continue and any other key for Exit = ";
        cin>>ch;
    }

    return 0;
}

double calculateTotal(double price, int quantity)
{
    double result = 0;
    result = price*quantity;
    return result;
}

void DisplayMenu()
{
    cout<<"\nPlace your Order from given Menu."<<endl;
    cout<<"\t(1) Apple (Rs. "<<apple<<")\n\t(2) Banana (Rs. "<<banana<<")\n\t(3) Orange (Rs. "<<orange<<")"<<endl;
    cout<<"\t(4) Mango (Rs. "<<mango<<")\n\t(5) Grapes (Rs. "<<grapes<<")\n\t (6) Calculate Tex\n"<<endl;
}

void applyDiscount(double &totalBill)
{
    double discount = 0;
    discount = (totalBill * 10)/100;
    totalBill = totalBill - discount;
    cout<<"After 10% Discount ... Discount price is "<<discount<<endl;
}

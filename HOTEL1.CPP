#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;
int count = 0;
class Customer
{  
public:
    char name[100],address[100],phone[14],from_date[20],to_date[20];
    float payment_advance;
    int booking_id;
};
class Room
{
public:
    char type,stype,ac;
    int roomNumber,rent,status;
    class Customer cust;
    class Room addR(int);
    void searchR(int);
    void deleteR(int);
    void displayR(Room);
};
class Room rooms[50];
Room Room::addR(int rno)
{
    Room room1;
    room1.roomNumber = rno;
    cout<<"\n-------------------------------------------------------------";
    cout << "\nType AC/Non-AC (A/N) : ";
    cin >> room1.ac;
    cout << "\nType Comfort (S/N) : ";
    cin >> room1.type;
    cout << "\nType Size (B/S) : ";
    cin >> room1.stype;
    cout << "\nDaily Rent : ";
    cin >> room1.rent;
    room1.status = 0;
    cout<<"\n-------------------------------------------------------------";
    cout << "\n Room Added Successfully!";
    cout<<"\n-------------------------------------------------------------";
    getch();
    return room1;
}
void displayR(Room tempRoom)
{
    cout<<"\n-------------------------------------------------------------";
    cout << "\nRoom Number: \t" << tempRoom.roomNumber;  
    cout << "\nType AC/Non-AC (A/N) " << tempRoom.ac;  
    cout << "\nType Comfort (S/N) " << tempRoom.type;  
    cout << "\nType Size (B/S) " << tempRoom.stype;  
    cout << "\nRent: " << tempRoom.rent;  
    cout<<"\n-------------------------------------------------------------";
}  
void searchR(int rno)  
{  
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].roomNumber == rno) 
        {  
            found = 1;  
            break;  
        }  
    }  
    if (found == 1)  
    {  
        cout<<"\n-------------------------------------------------------------";
        cout << "Room Details\n"; 
        if (rooms[i].status == 1)  
        {  
            cout << "\nRoom is Reserved";  
        }  
        else  
        {  
            cout << "\nRoom is available";  
        }  
        displayR(rooms[i]); 
        getch();  
    }  
    else  
    {  
        cout << "\nRoom not found";  
        getch();  
    }  
    cout<<"\n-------------------------------------------------------------";
}  


class HotelManagement : public Room  
{  
public:  
    void checkIn();  
    void getAvailRoom();  
    void searchCustomer(char *);  
    void checkOut(int);  
    void guestSummaryReport();  
};  
void guestSummaryReport()  
{  
    cout<<"\n-------------------------------------------------------------";
    if (count == 0)  
    {  
        cout << "\n No Guests in the Hotel";  
    }  
    for (int i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 1)  
        {  
            cout << "\n Customer First Name: " << rooms[i].cust.name;  
            cout << "\n Room Number: " << rooms[i].roomNumber;  
            cout << "\n Address (City only): " << rooms[i].cust.address;  
            cout << "\n Phone: " << rooms[i].cust.phone; 
        }  
    }  
    cout<<"\n-------------------------------------------------------------";
    getch();  
}
void checkIn() 
{  
    int i, found = 0, rno;
    class Room room;  
    cout<<"\n-------------------------------------------------------------";
    cout << "\nEnter Room number : ";  
    cin >> rno;  
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].roomNumber == rno)  
        {  
            found = 1;  
            break;  
        }  
    }  
    if (found == 1)  
    {  
        if (rooms[i].status == 1)  
        {  
            cout << "\nRoom is already Booked";  
            getch();  
            return;  
        }  
        cout << "\nEnter booking id: "; 
        cin >> rooms[i].cust.booking_id;
        cout << "\nEnter Customer Name (First Name): ";  
        cin >> rooms[i].cust.name;  
        cout << "\nEnter Address (only city): ";  
        cin >> rooms[i].cust.address;  
        cout << "\nEnter Phone: ";  
        cin >> rooms[i].cust.phone;  
        cout << "\nEnter From Date: ";  
        cin >> rooms[i].cust.from_date;  
        cout << "\nEnter to  Date: ";  
        cin >> rooms[i].cust.to_date;  
        cout << "\nEnter Advance Payment: ";  
        cin >> rooms[i].cust.payment_advance;  
        rooms[i].status = 1;  
        cout<<"\n-------------------------------------------------------------";
        cout << "\n Customer Checked-in Successfully..";  
        cout<<"\n-------------------------------------------------------------";
        getch();  
    }  
}  
void getAvailRoom()  
{  
    int i, found = 0;  
    cout<<"\n-------------------------------------------------------------";
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 0)  
        {  
            displayR(rooms[i]);  
            cout << "\n\nPress enter for next room";  
            found = 1;  
            getch();  
        }  
    }  
    if (found == 0)  
    {  
        cout << "\nAll rooms are reserved";  
        getch();  
    }  
    cout<<"\n-------------------------------------------------------------";
}  

void searchCustomer(char *pname)  
{  
    int i, found = 0;  
    cout<<"\n-------------------------------------------------------------";
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 1 && strcmp(rooms[i].cust.name, pname) == 0)  
        {  
            cout << "\nCustomer Name: " << rooms[i].cust.name;  
            cout << "\nRoom Number: " << rooms[i].roomNumber;  
            cout << "\n\nPress enter for next record";
            found = 1;
            getch();
        }  
    }  
    if (found == 0)  
    {  
        cout << "\nPerson not found.";  
        getch();  
    }  
    cout<<"\n-------------------------------------------------------------";
}
void checkOut(int roomNum)
{  
    int i, found = 0, days, rno;  
    float billAmount = 0;  
    cout<<"\n-------------------------------------------------------------";
    for (i = 0; i < count; i++)  
    {  
        if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum)  
        {  
            found = 1;  
            break;
        }  
    }  
    if (found == 1)  
    { 
        cout << "\nEnter Number of Days:\t";
        cin >> days;
        billAmount = days * rooms[i].rent;
        cout << "\n\t+++++++++++++++++++ CheckOut Details +++++++++++\n";  
        cout << "\nCustomer Name : " << rooms[i].cust.name;  
        cout << "\nRoom Number : " << rooms[i].roomNumber;  
        cout << "\nAddress : " << rooms[i].cust.address;  
        cout << "\nPhone : " << rooms[i].cust.phone;  
        cout << "\nTotal Amount Due : " << billAmount << " /";  
        cout << "\nAdvance Paid: " << rooms[i].cust.payment_advance << " /";  
        cout << "\n*** Total Payable: " << billAmount - rooms[i].cust.payment_advance << "/ only"; 
        cout<<"\n-------------------------------------------------------------";
        cout <<"\n Thank you visit Again . . . . ...................";
        rooms[i].status = 0;  
    }  
    cout<<"\n-------------------------------------------------------------";
    getch();  
}  

void manageRooms()
{  
    class Room room;  
    int opt, rno, i, flag = 0;
    char ch;  
    cout<<"\n-------------------------------------------------------------";
    do  
    {
        cout << "\n++++++++++++++ Manage Rooms +++++++++++++++++";  
        cout << "\n1. Add Room";  
        cout << "\n2. Search Room";  
        cout << "\n3. Back to Main Menu";  
        cout << "\n\nEnter Option: ";  
        cin >> opt;  
        switch (opt)  
        {  
        case 1:  
            cout << "\nEnter Room Number: ";  
            cin >> rno;  
            i = 0;  
            for (i = 0; i < count; i++)  
            {  
                if (rooms[i].roomNumber == rno)  
                {  
                    flag = 1;  
                }  
            }  
            if (flag == 1)  
            {  
                cout << "\nRoom Number is Present.\nPlease enter unique Number";  
                flag = 0;  
                getch();  
            }  
            else  
            {  
                rooms[count] = room.addR(rno);  
                count++;  
            }  
            break;  
        case 2:  
            cout << "\nEnter room number: ";  
            cin >> rno;  
            searchR(rno);  
            break;  
        case 3:
            break;  
        default:  
            cout << "\nPlease Enter correct option";  
            break;  
        }  
    } while (opt != 3);  
}  

int main()  
{  
    class HotelManagement k2;  
    int i, j, opt, rno;  
    char ch;  
    char pname[100];
    do
    {
        cout<<"\n-------------------------------------------------------------";
        cout << "+++++++++++++++++++++++++++++ Hotel Management ++++++++++++++++\n";  
        cout << "\n1. Manage Rooms";  
        cout << "\n2. Check-In Room";  
        cout << "\n3. Available Rooms";  
        cout << "\n4. Search Customer";  
        cout << "\n5. Check-Out Room";  
        cout << "\n6. Guest Summary Report";  
        cout << "\n7. Exit";  
        cout << "\n\nEnter Option: ";  
        cin >> opt;  
        switch (opt)  
        {  
        case 1:  
            manageRooms();  
            break;  
        case 2:  
            if (count == 0)  
            {  
                cout << "\nRooms data is not available.\nPlease add the rooms first.";  
                getch();  
            }  
            else  
                checkIn();  
            break;  
        case 3:  
            if (count == 0)  
            {  
                cout << "\nRooms data is not available.\nPlease add the rooms first.";  
                getch();  
            }  
            else  
                getAvailRoom();  
            break;  
        case 4:  
            if (count == 0)  
            {  
                cout << "\nRooms are not available.\nPlease add the rooms first.";  
                getch();  
            }  
            else  
            {  
                cout << "Enter Customer Name: ";  
                cin >> pname;  
                searchCustomer(pname);  
            }  
            break;  
        case 5:  
            if (count == 0)  
            {  
                cout << "\nRooms are not available.\nPlease add the rooms first.";  
                getch();  
            }  
            else  
            {  
                cout << "Enter Room Number : ";  
                cin >> rno;  
                checkOut(rno);  
            }  
	    break;
	case 6:
	    guestSummaryReport();
	    break;
	case 7:
	    cout << "\nTHANK YOU! FOR USING SOFTWARE";
	    break;
	default:
	    cout << "\nPlease Enter correct option";
	    break;
	}
    } while (opt != 7);
    cout<<"\n-------------------------------------------------------------";
    getch();
    return 0;
}

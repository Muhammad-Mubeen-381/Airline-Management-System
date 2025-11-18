#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
void resize_array_flights(int csize, int &max_size, string *&ids, string *&source, string *&destination, int *&total_s, int *&booked_s, string *&date, string *&time, string *&status, float *&fare)
{

    string *temp_id = ids;
    string *temp_source = source;
    string *temp_dest = destination;
    int *temp_total_s = total_s;
    int *temp_booked_s = booked_s;
    string *temp_date = date;
    string *temp_time = time;
    string *temp_status = status;
    float *temp_fare = fare;
    max_size += 100;
    ids = new string[max_size];
    source = new string[max_size];
    destination = new string[max_size];
    total_s = new int[max_size];
    booked_s = new int[max_size];
    date = new string[max_size];
    time = new string[max_size];
    status = new string[max_size];
    fare = new float[max_size];
    for (int i = 0; i < csize; i++)
    {
        ids[i] = temp_id[i];
        source[i] = temp_source[i];
        destination[i] = temp_dest[i];
        total_s[i] = temp_total_s[i];
        booked_s[i] = temp_booked_s[i];
        date[i] = temp_date[i];
        time[i] = temp_time[i];
        status[i] = temp_status[i];
        fare[i] = temp_fare[i];
    }
    delete[] temp_id;
    temp_id = nullptr;
    delete[] temp_source;
    temp_source = nullptr;
    delete[] temp_dest;
    temp_dest = nullptr;
    delete[] temp_total_s;
    temp_total_s = nullptr;
    delete[] temp_booked_s;
    temp_booked_s = nullptr;
    delete[] temp_date;
    temp_date = nullptr;
    delete[] temp_time;
    temp_time = nullptr;
    delete[] temp_status;
    temp_status = nullptr;
    delete[] temp_fare;
    temp_fare = nullptr;
}
void admin_search_flights(string ids)
{
    ifstream fin("flights_data.txt");
    string id;
    string s;
    string d;
    int total;
    int booked;
    string date;
    string time;
    string status;
    float fare;
    bool found = 0;

    while (fin >> id >> s >> d >> total >> booked >> date >> time >> status >> fare)
    {
        if (id == ids)
        {
            found = 1;
            break;
        }
    }
    fin.close();

    if (!found)
    {
        cout << "No Such FLight Exist!\n";
    }
    else
    {
        cout << "=====================================================================================================\n";
        cout << left << setw(7) << "Flight" << setw(14) << "Departure" << setw(14) << "Arrival" << setw(6) << "Total" << setw(8) << "Booked" << setw(15) << "Departure" << setw(10) << "Departure" << setw(14) << "Status" << setw(3) << "Fare" << "\n";
        cout << left << setw(7) << "ID    " << setw(14) << "         " << setw(14) << "       " << setw(6) << "Seats" << setw(8) << "Seats " << setw(15) << "Date     " << setw(10) << "Time     " << setw(14) << "      " << setw(3) << "    " << "\n";
        cout << "-----------------------------------------------------------------------------------------------------\n";
        cout << left << setw(7) << id << setw(14) << s << setw(14) << d << setw(6) << total << setw(8) << booked << setw(15) << date << setw(10) << time << setw(14) << status << setw(3) << fare << "\n";

        cout << "=====================================================================================================\n";
    }
}
void load_flights_data_from_file(int &csize, int &max_size, string *&ids, string *&source, string *&destination, int *&total_s, int *&booked_s, string *&date, string *&time, string *&status, float *&fare)
{
    ifstream fin("flights_data.txt");
    string id;
    string s;
    string d;
    int total;
    int booked;
    string date_c;
    string time_c;
    string status_c;
    float fare_c;
    bool loaded = 0;

    while (fin >> id >> s >> d >> total >> booked >> date_c >> time_c >> status_c >> fare_c)
    {
        csize++;
        if (csize == max_size)
        {
            resize_array_flights(csize, max_size, ids, source, destination, total_s, booked_s, date, time, status, fare);
        }
        ids[csize - 1] = id;
        source[csize - 1] = s;
        destination[csize - 1] = d;
        total_s[csize - 1] = total;
        booked_s[csize - 1] = booked;
        date[csize - 1] = date_c;
        time[csize - 1] = time_c;
        status[csize - 1] = status_c;
        fare[csize - 1] = fare_c;
    }
    fin.close();
}
void admin_update_flight_to_file(int &csize, int max_size, string *ids, string *source, string *destination, int *total_s, int *booked_s, string *date, string *time, string *status, float *fare)
{
    ofstream fout("flights_data.txt");
    for (int i = 0; i < csize; i++)
    {
        fout << ids[i] << " " << source[i] << " " << destination[i] << " " << total_s[i] << " " << booked_s[i] << " ";
        fout << date[i] << " " << time[i] << " " << status[i] << " " << fare[i] << "\n";
    }
    fout.close();
}
void admin_save_flight_to_file(string ids, string source, string destination, int total_s, int booked_s, string date, string time, string status, float fare)
{
    ofstream fout("flights_data.txt", ios::app);
    fout << ids << " " << source << " " << destination << " " << total_s << " " << booked_s << " ";
    fout << date << " " << time << " " << status << " " << fare << "\n";
    fout.close();
}
void admin_add_flight(int &csize, int &max_size, string *&ids, string *&source, string *&destination, int *&total_s, int *&booked_s, string *&date, string *&time, string *&status, float *&fare)
{
    if (csize == max_size)
    {
        resize_array_flights(csize, max_size, ids, source, destination, total_s, booked_s, date, time, status, fare);
    }
    if (csize < max_size)
    {
        cout << "Enter The Flight Id:";
        cin >> ids[csize];
        cout << "Enter The Source City:";
        cin >> source[csize];
        cout << "Enter The Destination City:";
        cin >> destination[csize];
        cout << "Enter The Total Seats Available in the Aircraft:";
        cin >> total_s[csize];
        cout << "FLight is Addes and currently Booked Seats are 0\n";
        booked_s[csize] = 0;
        cout << "Enter The Date Of Departure:";
        cin >> date[csize];
        cout << "Enter The Time Of Departure:";
        cin >> time[csize];
        cout << "Enter Current Status of Flight:";
        cin >> status[csize];
        cout << "Enter The Ticket Price:";
        cin >> fare[csize];

        admin_save_flight_to_file(ids[csize], source[csize], destination[csize], total_s[csize], booked_s[csize], date[csize], time[csize], status[csize], fare[csize]);
        csize++;
    }
}
void admin_delete_flight(int &csize, int max_size, string *ids, string *source, string *destination, int *total_s, int *booked_s, string *date, string *time, string *status, float *fare)
{
    string id;
    cout << "Enter The Flight Id to be Deleted:";
    cin >> id;
    int index = 0;
    int found = 0;
    int seat_filled = 0;
    for (int i = 0; i < csize; i++)
    {
        if (id == ids[i])
        {
            index = i;
            found = 1;
            break;
        }
    }
    if (booked_s[index] > 0)
    {
        found = 0;
        seat_filled = 1;
    }
    if (found)
    {
        for (int i = index; i < csize - 1; i++)
        {
            ids[i] = ids[i + 1];
            source[i] = source[i + 1];
            destination[i] = destination[i + 1];
            total_s[i] = total_s[i + 1];
            booked_s[i] = booked_s[i + 1];
            date[i] = date[i + 1];
            time[i] = time[i + 1];
            status[i] = status[i + 1];
            fare[i] = fare[i + 1];
        }
        csize--;
        admin_update_flight_to_file(csize, max_size, ids, source, destination, total_s, booked_s, date, time, status, fare);
        cout << "Deletion Successful\n";
    }
    else if (found == 0 && seat_filled == 0)
    {
        cout << "No Such Flight Exist\n";
    }
    if (found == 0 && seat_filled > 0)
        cout << "Seats Are Booked Cannot Delete!\n";
}
void admin_update_total_seats(int &csize, int max_size, string *ids, string *source, string *destination, int *total_s, int *booked_s, string *date, string *time, string *status, float *fare)
{
    bool found = 0;
    string id;
    cout << "Enter The ID of FLight Of Which Total Seats to be Updated:";
    cin >> id;
    int updated_seats;
    int index;
    for (int i = 0; i < csize; i++)
    {
        if (id == ids[i])
        {
            index = i;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        cout << "No such flight Exist\n";
    }
    else
    {
        cout << "Enter The Updated Seats:";
        cin >> updated_seats;
        total_s[index] = updated_seats;
        admin_update_flight_to_file(csize, max_size, ids, source, destination, total_s, booked_s, date, time, status, fare);
        cout << "Done Successfully!";
    }
}
void admin_list_flights(int csize)
{

    if (csize <= 0)
    {
        cout << "No Flights Exits\n";
    }
    else
    {
        string id;
        string s;
        string d;
        int total;
        int booked;
        string date;
        string time;
        string status;
        float fare;
        cout << "=====================================================================================================\n";
        cout << left << setw(7) << "Flight" << setw(14) << "Departure" << setw(14) << "Arrival" << setw(6) << "Total" << setw(8) << "Booked" << setw(15) << "Departure" << setw(10) << "Departure" << setw(14) << "Status" << setw(3) << "Fare" << "\n";
        cout << left << setw(7) << "ID    " << setw(14) << "         " << setw(14) << "       " << setw(6) << "Seats" << setw(8) << "Seats " << setw(15) << "Date     " << setw(10) << "Time     " << setw(14) << "      " << setw(3) << "    " << "\n";
        cout << "-----------------------------------------------------------------------------------------------------\n";
        ifstream fin("flights_data.txt");
        while (fin >> id >> s >> d >> total >> booked >> date >> time >> status >> fare)
        {
            cout << left << setw(7) << id << setw(14) << s << setw(14) << d << setw(6) << total << setw(8) << booked << setw(15) << date << setw(10) << time << setw(14) << status << setw(3) << fare << "\n";
        }
        cout << "=====================================================================================================\n";
        fin.close();
    }
}
void admin_change_flight_status(int &csize, int max_size, string *ids, string *source, string *destination, int *total_s, int *booked_s, string *date, string *time, string *status, float *fare)
{
    string id;
    cout << "Enter The FLight Id To Change Status:";
    cin >> id;
    string updated_status;
    int index;
    int found = 0;
    for (int i = 0; i < csize; i++)
    {
        if (id == ids[i])
        {
            index = i;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        cout << "No such flight Exist\n";
    }
    else
    {
        cout << "============Status Can Be Following============\n";
        cout << "Scheduled\n";
        cout << "Dealyed\n";
        cout << "Cancelled\n";
        cout << "Boarding\n";
        cout << "Deprated\n";
        cout << "Landed\n";
        cout << "================================================\n";

        cout << "Enter The Updated Status:";
        cin >> updated_status;
        status[index] = updated_status;
        admin_update_flight_to_file(csize, max_size, ids, source, destination, total_s, booked_s, date, time, status, fare);
        cout << "Done Successfully!";
    }
}
void admin_change_flight_fare(int &csize, int max_size, string *ids, string *source, string *destination, int *total_s, int *booked_s, string *date, string *time, string *status, float *fare)
{
    string id;
    cout << "Enter The FLight Id To Update Fare:";
    cin >> id;
    float updated_fare;
    int index;
    int found = 0;
    for (int i = 0; i < csize; i++)
    {
        if (id == ids[i])
        {
            index = i;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        cout << "No such flight Exist\n";
    }
    else
    {

        cout << "Enter The Updated fare:";
        cin >> updated_fare;
        fare[index] = updated_fare;
        admin_update_flight_to_file(csize, max_size, ids, source, destination, total_s, booked_s, date, time, status, fare);
        cout << "Done Successfully!";
    }
}
void admin_list_fully_booked_flights(int csize)
{
    string id;
    string s;
    string d;
    int total;
    int booked;
    string date;
    string time;
    string status;
    float fare;
    bool first = 1;
    int found = 0;
    if (csize <= 0)
    {
        cout << "No Flights Exits\n";
    }
    else
    {
        ifstream fin("flights_data.txt");
        while (fin >> id >> s >> d >> total >> booked >> date >> time >> status >> fare)
        {
            if (total == booked)
            {
                found = 1;
                if (first)
                {
                    cout << "=====================================================================================================\n";
                    cout << left << setw(7) << "Flight" << setw(14) << "Departure" << setw(14) << "Arrival" << setw(6) << "Total" << setw(8) << "Booked" << setw(15) << "Departure" << setw(10) << "Departure" << setw(14) << "Status" << setw(3) << "Fare" << "\n";
                    cout << left << setw(7) << "ID    " << setw(14) << "         " << setw(14) << "       " << setw(6) << "Seats" << setw(8) << "Seats " << setw(15) << "Date     " << setw(10) << "Time     " << setw(14) << "      " << setw(3) << "    " << "\n";
                    cout << "-----------------------------------------------------------------------------------------------------\n";
                    first = 0;
                }
                cout << left << setw(7) << id << setw(14) << s << setw(14) << d << setw(6) << total << setw(8) << booked << setw(15) << date << setw(10) << time << setw(14) << status << setw(3) << fare << "\n";
            }
        }
        cout << "=====================================================================================================\n";
        fin.close();
    }
    if (!found)
    {
        cout << "No Flights Exits\n";
    }
}

void main_dashboard()
{
    cout << "===========================================\n";
    cout << "       AIRLINE MANAGEMENT SYSTEM\n";
    cout << "===========================================\n";
    cout << "1-Admin Login\n";
    cout << "2-User Login\n";
    cout << "3-View Flights\n";
    cout << "4-Exit\n";
    cout << "-------------------------------------------\n";
    cout << "\nEnter Your Choice:_";
}
void admin_dashboard()
{
    cout << "===========================================\n";
    cout << "             ADMIN DASHBOARD \n";
    cout << "===========================================\n";
    cout << "1-ADD FLIGHT\n";
    cout << "2-DELETE FLIGHT\n";
    cout << "3-UPDATE SEATS\n";
    cout << "4-LIST FLIGHTS\n";
    cout << "5-SEARCH FLIGHTS\n";
    cout << "6-LIST ALL BOOKINGS\n";
    cout << "7-CHANGE FLIGHT STATUS\n";
    cout << "8-UPDATE FARE OF SPECIFIC FLIGHT\n";
    cout << "9-VIEW FULLY BOOKED FLIGHTS\n";
    cout << "0-Exit\n";
    cout << "-------------------------------------------\n";
}
//----------------------------------------------------------------------

int generate_booking_id()
{
    ifstream fin("bookings.txt");
    string bid;
    string user;
    string id, s, d, date, time, status;
    int total, booked;
    float fare;
    int cnic;
    int maxID = 0;

    while (fin >> bid >> user >> cnic >> id >> s >> d >> total >> booked >> date >> time >> status >> fare)
    {
        int num = 0;
        for (int i = 0; i < bid.length(); i++)
            if (bid[i] >= '0' && bid[i] <= '9')
                num = num * 10 + (bid[i] - '0');

        if (num > maxID)
            maxID = num;
    }
    fin.close();
    return maxID + 1;
}

void save_booking(string bid, string username, int cnic, string id, string s, string d,
                  int total, int booked, string date, string time, string status, float fare)
{
    ofstream fout("bookings.txt", ios::app);
    fout << bid << " " << username << " " << cnic << " " << id << " " << s << " " << d << " "
         << total << " " << booked << " " << date << " " << time << " "
         << status << " " << fare << "\n";
    fout.close();
}

void book_ticket(int &csize, int &max_size, string *ids, string *source, string *destination,
                 int *total_s, int *booked_s, string *date, string *time,
                 string *status, float *fare)
{
    string user, fid;
    int cnic;
    cout << "Enter Your Name: ";
    cin >> user;
    cout << "Enter Your Cnic: ";
    cin >> cnic;

    cout << "Enter Flight ID to Book: ";
    cin >> fid;

    int found = -1;
    for (int i = 0; i < csize; i++)
        if (ids[i] == fid)
            found = i;

    if (found == -1)
    {
        cout << "Flight Not Found\n";
        return;
    }

    if (booked_s[found] >= total_s[found])
    {
        cout << "No seats available\n";
        return;
    }

    booked_s[found]++;

    int idn = generate_booking_id();
    string bid = to_string(idn);

    save_booking(bid, user, cnic, ids[found], source[found], destination[found],
                 total_s[found], booked_s[found], date[found], time[found],
                 status[found], fare[found]);

    admin_update_flight_to_file(csize, max_size, ids, source, destination,
                                total_s, booked_s, date, time, status, fare);

    cout << "Booking Successful! Your Booking ID: " << bid << "\n";
}

void user_search_flight()
{
    string id;
    cout << "Enter Flight ID: ";
    cin >> id;
    admin_search_flights(id);
}

void my_bookings(int c)
{
    ifstream fin("bookings.txt");
    string bid, uname, id, s, d, date, time, status;
    int total, booked;
    float fare;
    bool found = false;
    int cnic;
    cout << "======================================= YOUR BOOKINGS ==========================================\n";

    while (fin >> bid >> uname >> cnic >> id >> s >> d >> total >> booked >> date >> time >> status >> fare)
    {
        if (cnic == c)
        {
            found = true;
            cout << "Booking ID:" << bid
                 << " Flight:" << id
                 << " Depatrure: " << s
                 << " Arrival: " << d
                 << " Date: " << date
                 << " Time: " << time
                 << " cnic:" << cnic << "\n";
        }
    }
    fin.close();

    if (!found)
        cout << "No Bookings Found!\n";
}

void user_menu(int &csize, int &max_size, string *ids, string *source, string *destination,
               int *total_s, int *booked_s, string *date, string *time,
               string *status, float *fare, int cn)
{
    int ch;
    int cnic;
    while (true)
    {
        cout << "\n============== USER MENU ==============\n";
        cout << " Your Cnic:" << cn << "\n";
        cout << "-----------------------------------------\n";
        cout << "1 - View All Flights\n";
        cout << "2 - Search Flight\n";
        cout << "3 - Book Ticket\n";
        cout << "4 - My Bookings\n";
        cout << "0 - Exit\n";
        cout << "Enter Choice: ";
        cin >> ch;

        if (ch == 1)
            admin_list_flights(csize);
        else if (ch == 2)
            user_search_flight();
        else if (ch == 3)
            book_ticket(csize, max_size, ids, source, destination,
                        total_s, booked_s, date, time, status, fare);
        else if (ch == 4)
        {

            cout << "Enter the Cnic:";
            cin >> cnic;
            my_bookings(cnic);
        }
        else if (ch == 0)
            break;
        else
            cout << "Invalid Choice!\n";
    }
}
void admin_view_all_bookings()
{

    ifstream fin("bookings.txt");
    string bid, uname, id, s, d, date, time, status;
    int cnic;
    int total, booked;
    float fare;
    bool found = false;

    cout << "======================================== ALL BOOKINGS ==========================================\n";

    while (fin >> bid >> uname >> cnic >> id >> s >> d >> total >> booked >> date >> time >> status >> fare)
    {

        found = true;
        cout << "Booking ID:" << bid
             << " Flight:" << id
             << " Depatrure: " << s
             << " Arrival : " << d
             << " Date: " << date
             << " Time: " << time
             << " Cnic: " << cnic << "\n";
    }
    fin.close();

    if (!found)
        cout << "No Bookings Exist!\n";
}
int main()
{
    string *flight_Ids;
    string *source_City;
    string *destination_City;
    string *date_of_flight;
    string *departure_time;
    string *status;

    char *username = new char[25];
    char *password = new char[25];
    char *f_username = new char[25];
    char *f_password = new char[25];

    int flights_size = 100;
    int current_flights = 0;

    flight_Ids = new string[flights_size];
    source_City = new string[flights_size];
    destination_City = new string[flights_size];
    date_of_flight = new string[flights_size];
    departure_time = new string[flights_size];
    status = new string[flights_size];

    int *total_seats = new int[flights_size];
    int *booked_seats = new int[flights_size];
    float *fare = new float[flights_size];
    load_flights_data_from_file(current_flights, flights_size, flight_Ids, source_City, destination_City, total_seats, booked_seats, date_of_flight, departure_time, status, fare);
    int login_selection = 10;

    while (login_selection != 4)
    {
        main_dashboard();

        cin >> login_selection;

        // Admin Portal
        if (login_selection == 1)
        {
            int tries = 0;
            cout << "===============ADMIN INTERFACE================\n";
            cout << "Only 3 Unsuccessful Attempts Allowed!\n";
            int exit = 1;
            while (exit)
            {
                int login = 0;
                cout << "\n";
                cout << "Enter The Username:";
                cin >> username;
                cout << "Enter The Password:";
                cin >> password;
                ifstream fin("login_admin.txt");
                while (fin >> f_username >> f_password)
                {
                    if (strcmp(password, f_password) == 0 && strcmp(f_username, username) == 0)
                    {
                        cout << "Login Succesful\n";
                        login = 1;
                        fin.close();
                        cout << "\n";
                        cout << "\n";
                        tries = 0;
                        break;
                    }
                }
                fin.close();
                if (!login)
                {
                    cout << "Invalid Account\n";
                    cout << "\n";
                    tries++;
                }
                if (tries == 3)
                {
                    login_selection = 4;
                    exit = 0;
                    cout << "YOUR LIMIT HAS ENDED\n";
                    break;
                }

                if (login == 1)
                {

                    int go = 1;
                    while (go)
                    {
                        admin_dashboard();
                        cin >> go;
                        if (go == 1)
                        {
                            admin_add_flight(current_flights, flights_size, flight_Ids, source_City, destination_City, total_seats, booked_seats, date_of_flight, departure_time, status, fare);
                        }
                        else if (go == 2)
                        {
                            admin_delete_flight(current_flights, flights_size, flight_Ids, source_City, destination_City, total_seats, booked_seats, date_of_flight, departure_time, status, fare);
                        }
                        else if (go == 3)
                        {
                            admin_update_total_seats(current_flights, flights_size, flight_Ids, source_City, destination_City, total_seats, booked_seats, date_of_flight, departure_time, status, fare);
                        }
                        else if (go == 4)
                        {
                            admin_list_flights(current_flights);
                        }
                        else if (go == 5)

                        {
                            string temp_id;
                            cout << "Enter The Flight Id TO TracK:";

                            cin >> temp_id;
                            admin_search_flights(temp_id);
                        }
                        else if (go == 6)
                        {

                            admin_view_all_bookings();
                        }
                        else if (go == 7)
                        {
                            admin_change_flight_status(current_flights, flights_size, flight_Ids, source_City, destination_City, total_seats, booked_seats, date_of_flight, departure_time, status, fare);
                        }
                        else if (go == 8)
                        {
                            admin_change_flight_fare(current_flights, flights_size, flight_Ids, source_City, destination_City, total_seats, booked_seats, date_of_flight, departure_time, status, fare);
                        }
                        else if (go == 9)
                        {
                            admin_list_fully_booked_flights(current_flights);
                        }
                        else if (go == 0)
                        {

                            exit = 0;
                        }
                    }
                }
            }
        } // admin if end
        if (login_selection == 3)
        {
            string yes;
            cout << "===============FLIGHTS DETAILS================\n";

            admin_list_flights(current_flights);
            cout << "\n";
            cout << "\n";
            cout << "==============================================\n";

            cout << "Wanna Login Or SignUP as a User!(Y/N)\n";
            cin >> yes;
            if (yes == "Y")
                login_selection = 2;
        }

        if (login_selection == 2)
        {
            int login = 0;
            int tries = 0;
            char *name = new char[20];
            int cnic;

            int user_type = 0;
            cout << "===============USER INTERFACE================\n";
            while (!user_type)
            {
                cout << "1-LOGIN -> EXISTING USER\n";
                cout << "2-SIGNUP-> NEWUSER USER\n";
                cout << "->:";
                cin >> user_type;
                if (user_type == 1 || user_type == 2)
                    ;
                else
                {
                    user_type = 0;
                    cout << "Invalid\n";
                }
            }
            if (user_type == 2)
            {
                cout << "Enter Your Name(No Spaces):";
                cin >> name;
                cout << "Enter You Cnic:";
                cin >> cnic;
                cout << "Enter Your Username:";
                cin >> username;
                cout << "Enter Your Password:";
                cin >> password;
                ofstream fout("login_user.txt", ios::app);
                fout << username << "\t" << password << "\t" << name << "\t" << cnic << "\n";
                fout.close();
                cout << "REGISTERED SUCCESSFULLY! DIRECTING TO USER PORTAL\n";
                login = 1;
            }

            else if (user_type == 1)
            {
                bool login_1 = false;
                cout << "Only 3 Unsuccessful Attempts Allowed!\n";

                while (!login_1)
                {
                    cout << "\n";
                    cout << "Enter The Username:";
                    cin >> username;
                    cout << "Enter The Password:";
                    cin >> password;
                    ifstream fin("login_user.txt");
                    while (fin >> f_username >> f_password >> name >> cnic)
                    {
                        if (strcmp(password, f_password) == 0 && strcmp(f_username, username) == 0)
                        {
                            cout << "Login Succesful\n";
                            login = 1;
                            login_1 = true;
                            fin.close();
                            cout << "\n";
                            cout << "\n";
                            tries = 0;
                            break;
                        }
                    }
                    fin.close();
                    if (!login_1)
                    {
                        cout << "Invalid Account\n";
                        cout << "\n";
                        tries++;
                    }
                    if (tries == 3)
                    {
                        cout << "YOUR LIMIT HAS ENDED\n";
                        break;
                    }
                }
            }
            if (login == 1)
            {
                cout << "===============USER PORTAL================\n";
                cout << "WELCOME ! " << name << " GOOD TO SEE YOU!\n";
                cout << "Your Cnic:" << cnic << "\n";
                user_menu(current_flights, flights_size, flight_Ids, source_City, destination_City, total_seats, booked_seats, date_of_flight, departure_time, status, fare, cnic);
            }
            delete[] name;
        }
    }

    delete[] flight_Ids;
    delete[] source_City;
    delete[] destination_City;
    delete[] date_of_flight;
    delete[] departure_time;
    delete[] status;
    delete[] total_seats;
    delete[] booked_seats;
    delete[] fare;
    delete[] password;
    delete[] f_password;
    delete[] username;
    delete[] f_username;
}

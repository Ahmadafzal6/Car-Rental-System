#include <iostream>

#include <fstream>

using namespace std;

// Description:
// This program simulates a car rental service called "Billionaire Garage."
// It allows users to select from a list of 30 cars, enter their rental duration,
// calculate the total rent, handle payments, and store rental details in a file.
// The program includes features such as continuous rental, refund for extra payment,
// and displays a thank-you message upon completion.

int main() {
    char renter_name[100], renter_cnic[15], renter_address[150], renter_contact[20];
    int selected_car_number, rental_duration;
    float payment_amount, total_rent, discount;
    char continue_renting;

    cout << "\n\n";
    cout << "========================================\n";
    cout << "   WELCOME TO BILLIONAIRE GARAGE      \n";
    cout << "    Your one-stop car rental service  \n";
    cout << "========================================\n";
    cout << "\n";

    do {
        // Ask for renter's details
        cout << "Please enter your name: ";
        cin.getline(renter_name, 100); // Name input

        cout << "Please enter your CNIC (13 digits): ";
        cin.getline(renter_cnic, 15); 

        cout << "Please enter your address: ";
        cin.getline(renter_address, 150); 

        cout << "Please enter your contact number: ";
        cin.getline(renter_contact, 20); 

        // Display available cars for rent with numbered options
        cout << "\nAvailable cars for rent:\n";
        cout << "1. BMW: 200 per day\n";
        cout << "2. SUZUKI: 150 per day\n";
        cout << "3. MEHRAN: 100 per day\n";
        cout << "4. TESLA: 500 per day\n";
        cout << "5. ALTO: 120 per day\n";
        cout << "6. MERCEDES: 350 per day\n";
        cout << "7. CULTUS: 180 per day\n";
        cout << "8. TOYOTA: 220 per day\n";
        cout << "9. BENZ: 400 per day\n";
        cout << "10. REVO: 250 per day\n";
        cout << "11. FERRARI: 600 per day\n";
        cout << "12. PORSCHE: 550 per day\n";
        cout << "13. AUDI: 450 per day\n";
        cout << "14. JEEP: 300 per day\n";
        cout << "15. LAND ROVER: 380 per day\n";
        cout << "16. HONDA CIVIC: 250 per day\n";
        cout << "17. COROLLA: 230 per day\n";
        cout << "18. NISSAN: 270 per day\n";
        cout << "19. KIA: 200 per day\n";
        cout << "20. MITSUBISHI: 320 per day\n";
        cout << "21. LAMBORGHINI: 700 per day\n";
        cout << "22. ROLLS ROYCE: 800 per day\n";
        cout << "23. BUGATTI: 900 per day\n";
        cout << "24. ASTON MARTIN: 650 per day\n";
        cout << "25. VOLKSWAGEN: 240 per day\n";
        cout << "26. HYUNDAI: 220 per day\n";
        cout << "27. CHEVROLET: 260 per day\n";
        cout << "28. FORD: 280 per day\n";
        cout << "29. MAZDA: 230 per day\n";
        cout << "30. SUBARU: 250 per day\n";

        // Ask renter to select a car by number
        cout << "Please select a car by number (1-30): ";
        cin >> selected_car_number;

        // Check if the selected car number is valid
        while (selected_car_number < 1 || selected_car_number > 30) {
            cout << "Invalid input! Please select a car number between 1 and 30: ";
            cin >> selected_car_number;
        }

        // Ask for rental duration
        cout << "Please enter the number of days for renting the car: ";
        cin >> rental_duration;

        // Check if rental duration is valid
        while (rental_duration <= 0) {
            cout << "Invalid input! Please enter a valid number of days: ";
            cin >> rental_duration;
        }

        // Calculate the total rent based on the selected car
        switch (selected_car_number) {
        case 1: total_rent = 200 * rental_duration; break;
        case 2: total_rent = 150 * rental_duration; break;
        case 3: total_rent = 100 * rental_duration; break;
        case 4: total_rent = 500 * rental_duration; break;
        case 5: total_rent = 120 * rental_duration; break;
        case 6: total_rent = 350 * rental_duration; break;
        case 7: total_rent = 180 * rental_duration; break;
        case 8: total_rent = 220 * rental_duration; break;
        case 9: total_rent = 400 * rental_duration; break;
        case 10: total_rent = 250 * rental_duration; break;
        case 11: total_rent = 600 * rental_duration; break;
        case 12: total_rent = 550 * rental_duration; break;
        case 13: total_rent = 450 * rental_duration; break;
        case 14: total_rent = 300 * rental_duration; break;
        case 15: total_rent = 380 * rental_duration; break;
        case 16: total_rent = 250 * rental_duration; break;
        case 17: total_rent = 230 * rental_duration; break;
        case 18: total_rent = 270 * rental_duration; break;
        case 19: total_rent = 200 * rental_duration; break;
        case 20: total_rent = 320 * rental_duration; break;
        case 21: total_rent = 700 * rental_duration; break;
        case 22: total_rent = 800 * rental_duration; break;
        case 23: total_rent = 900 * rental_duration; break;
        case 24: total_rent = 650 * rental_duration; break;
        case 25: total_rent = 240 * rental_duration; break;
        case 26: total_rent = 220 * rental_duration; break;
        case 27: total_rent = 260 * rental_duration; break;
        case 28: total_rent = 280 * rental_duration; break;
        case 29: total_rent = 230 * rental_duration; break;
        case 30: total_rent = 250 * rental_duration; break;
        }

        // Apply discount if rental duration is long enough
        if (rental_duration >= 7 && rental_duration <= 14) {
            discount = total_rent * 0.10; // 10% discount
        }
        else if (rental_duration > 14) {
            discount = total_rent * 0.20; // 20% discount
        }
        else {
            discount = 0; // No discount for less than 7 days
        }

        total_rent -= discount; //  discount from total rent

        cout << "The total rent for the selected car for " << rental_duration << " days is " << total_rent << ".\n";
        if (discount > 0) {
            cout << "You received a discount of " << discount << "!\n";
        }

        // Ask for payment amount
        cout << "Please enter your payment amount: ";
        cin >> payment_amount;

        // Check if payment amount is valid
        while (payment_amount <= 0) {
            cout << "Invalid input! Please enter a valid payment amount: ";
            cin >> payment_amount;
        }

        // Condition to check if payment is sufficient
        if (payment_amount < total_rent) {
            cout << "Insufficient payment. You need " << (total_rent - payment_amount) << " more.\n";
            continue;
        }
        else if (payment_amount > total_rent) {
            cout << "You have paid extra " << (payment_amount - total_rent) << " amount.\n";
            cout << "Sorry, we will not refund the extra amount.\n";
        }

        // Store rental information in the file (append mode)
        ofstream file("rentals.txt", ios::app); // Open file in append mode
        if (file.is_open()) {
            file << "Name: " << renter_name << "\n"
                << "CNIC: " << renter_cnic << "\n"
                << "Address: " << renter_address << "\n"
                << "Contact: " << renter_contact << "\n"
                << "Car: " << selected_car_number << "\n"
                << "Rental Duration: " << rental_duration << " days\n"
                << "Payment Amount: " << payment_amount << "\n"
                << "Total Rent: " << total_rent << "\n"
                << "Discount: " << discount << "\n"
                << "-----------------------------\n";

            file.close();
            cout << "Rental confirmed. You have rented the car for " << rental_duration << " days.\n";
        }
        else {
            cout << "Error opening file.\n";
        }

        // Ask if the renter wants to rent another car
        cout << "Do you want to rent another car? (Y/N): ";
        cin >> continue_renting;

        // Clear input buffer
        cin.ignore(); // Ignore any trailing newline characters
    } while (continue_renting == 'Y' || continue_renting == 'y'); // Continue loop if 'Y' or 'y' is entered

    cout << "-----------------------------------------------------------\n";
    cout << "-----------------------------------------------------------\n";
    cout << "BIG THANK YOU FOR USING BILLIONAIRE GARAGE!\n";
    cout << "We hope to see you again. Have an amazing day!\n";
    cout << "-----------------------------------------------------------\n";
    cout << "-----------------------------------------------------------\n";
    return 0;
}
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Record {
    string month;
    double energy;   // kWh
    double water;    // Litres
    double waste;    // kg
};

int main() {
    vector<Record> data;
    int choice;

    do {
        cout << "\n===== Digital Twin Sustainability Simulator =====\n";
        cout << "1. Add Monthly Data\n";
        cout << "2. View Sustainability Report\n";
        cout << "3. Check Sustainability Score\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Record r;
            cout << "Enter Month (e.g. Jan): ";
            cin >> r.month;

            cout << "Enter Energy Consumption (kWh): ";
            cin >> r.energy;

            cout << "Enter Water Usage (Litres): ";
            cin >> r.water;

            cout << "Enter Waste Generated (kg): ";
            cin >> r.waste;

            data.push_back(r);
            cout << "Data added successfully!\n";
        }

        else if (choice == 2) {
            if (data.empty()) {
                cout << "No data available.\n";
            } else {
                cout << "\n-----------------------------------------------\n";
                cout << left << setw(10) << "Month"
                     << setw(15) << "Energy"
                     << setw(15) << "Water"
                     << setw(10) << "Waste" << endl;
                cout << "-----------------------------------------------\n";

                double totalEnergy = 0;
                double totalWater = 0;
                double totalWaste = 0;

                for (auto r : data) {
                    cout << left << setw(10) << r.month
                         << setw(15) << r.energy
                         << setw(15) << r.water
                         << setw(10) << r.waste << endl;

                    totalEnergy += r.energy;
                    totalWater += r.water;
                    totalWaste += r.waste;
                }

                cout << "\nTotal Energy Used : " << totalEnergy << " kWh\n";
                cout << "Total Water Used  : " << totalWater << " Litres\n";
                cout << "Total Waste       : " << totalWaste << " kg\n";
            }
        }

        else if (choice == 3) {
            if (data.empty()) {
                cout << "No data available.\n";
            } else {
                double totalEnergy = 0, totalWater = 0, totalWaste = 0;

                for (auto r : data) {
                    totalEnergy += r.energy;
                    totalWater += r.water;
                    totalWaste += r.waste;
                }

                // Simple scoring logic
                double score = 100;

                score -= totalEnergy / 100.0;
                score -= totalWater / 500.0;
                score -= totalWaste / 10.0;

                if (score < 0)
                    score = 0;

                cout << "\n===== Sustainability Score =====\n";
                cout << "Score: " << fixed << setprecision(2)
                     << score << " / 100\n";

                if (score >= 80)
                    cout << "Status: Excellent Sustainability\n";
                else if (score >= 60)
                    cout << "Status: Good Sustainability\n";
                else if (score >= 40)
                    cout << "Status: Needs Improvement\n";
                else
                    cout << "Status: Poor Sustainability\n";
            }
        }

        else if (choice == 4) {
            cout << "Exiting Simulator...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

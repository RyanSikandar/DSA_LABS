#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class hospital_management_system
{
private:
    struct Patients
    {
        string name;
        int id;
        bool operator<(const Patients &other) const
        {
            return name < other.name;
        }
    };

    Patients *queue_patients; // Dynamic array to store patients
    int size;               // Current number of patients in the queue
    int capacity;           // Maximum capacity of the queue
    int front;              // Index of the front (head) of the queue
    int rear;               // Index of the rear (end) of the queue
    int current_id;         // Counter for generating patient IDs

public:
    hospital_management_system(int a) : capacity(a), size(0), rear(-1), front(0), current_id(1)
    {
        queue_patients = new Patients[capacity]; // Initialize the patient queue
    };

    void register_patient(string const &name)
    {
        if (size < capacity)
        {
            Patients new_patient = {name, current_id}; // Create a new patient

            rear = (rear + 1) % capacity; // Update the rear index
            queue_patients[rear] = new_patient; // Add the new patient to the queue

            current_id++; // Increment the ID counter
            size++;      // Increment the queue size
            cout << "\nNew Patient with name: " << new_patient.name << " has been registered with id: " << new_patient.id;
        }
        else
        {
            cout << "\n The queue is already full, please wait !";
        }
    }

    void serve_patient()
    {
        if (size > 0)
        {
            Patients next_patient = queue_patients[front]; // Get the next patient to serve

            cout << "Patient number: " << next_patient.id << " please come forward for your turn.\n";
            front = (front + 1) % capacity; // Update the front index
            size--;                        // Decrement the queue size
        }
        else
        {
            cout << "\n No patient to be served at the moment!";
        }
    }

    void cancel_all()
    {
        front = -1;   // Reset the front index
        rear = -1;    // Reset the rear index
        size = 0;     // Reset the queue size
        cout << "\n The doctor has gone for lunch, please wait till the doctor returns.";
    }

    bool can_doctor_go_home()
    {
        return size == 0; // Check if there are no patients in the queue
    }

    void show_all_patient()
    {
        if (size == 0)
        {
            cout << "\nNo Patients Waiting.";
            return;
        }
        else
        {
            Patients *sorted_patients = new Patients[size]; // Create an array to store sorted patients
            int sorted_index = 0;

            for (int i = front; i <= rear; i++)
            {
                sorted_patients[sorted_index++] = queue_patients[i]; // Copy patients into the sorted array
            }
            std::sort(sorted_patients, sorted_patients + size, [](const Patients &a, const Patients &b)
                     { return a.name < b.name; }); // Sort patients by name

            cout << "Waiting patients in sorted order:" << std::endl;
            for (int i = 0; i < size; i++)
            {
                cout << "ID: " << sorted_patients[i].id << ", Name: " << sorted_patients[i].name << endl; // Display sorted patients
            }

            delete[] sorted_patients; // Clean up memory
        }
    }
};

int main()
{
    hospital_management_system hospital(5); // Initialize the system with a capacity of 5

    hospital.register_patient("Kashif");
    hospital.register_patient("Bob");
    hospital.register_patient("Charlie");
    hospital.register_patient("Faizan");
    hospital.register_patient("Ryan");

    cout << "\nInitial Queue:" << endl;
    hospital.show_all_patient();

    cout << endl;
    hospital.serve_patient();
    hospital.serve_patient();

    cout << "\nQueue After Serving Two Patients:" << endl;
    hospital.show_all_patient();

    cout << "\nDoctor can go home? ";
    if (hospital.can_doctor_go_home())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    cout << endl;
    hospital.cancel_all();
    cout << "\nQueue After Canceling All Appointments:" << endl;
    hospital.show_all_patient();

    return 0;
}
/*
 * Smart pointer notes. CPP Advanced course AFRY 10-11 may 2023
 */

#include <iostream>
#include <memory>

class Car
{
    public:
        int mileage;
};

void reseatPtr(std::unique_ptr<Car>& car) {  // Pass by reference
    car = std::unique_ptr<Car>();            // This will destroy the original one
}

int main()
{   
    auto car_p1 = std::make_unique<Car>();    // OWNING  
    car_p1->mileage = 555;
    printf("car_p1.mileage=%d\n", car_p1->mileage); // 555

   std::cout << "car_p1=" << car_p1.get() << "\n";  // Adress in the heap
    
    // Get the raw pointer. NON-OWNING
    auto car_p2 = car_p1.get(); // Get the address in the heap
    printf("car_p2.mileage=%d\n", car_p2->mileage); // 555

    // Get a copy of the raw pointer. NON-OWNING
    auto car_p3 = car_p2;
    printf("car_p3.mileage=%d\n", car_p3->mileage); // 555

    // Get a copy of the smart pointer
    //auto car_p4 = car_p1;               // THIS IS NOT ALLOWED
    //printf("car_p3.mileage=%d\n", car_p3->mileage); // 555

    //std move

    // Reseat
    reseatPtr(car_p1);

    std::cout << "car_p1=" << car_p1.get() << "\n";  // 0x0. It's destroyed at this point

    return 0;
}
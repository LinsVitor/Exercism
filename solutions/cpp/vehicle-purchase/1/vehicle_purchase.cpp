#include "vehicle_purchase.h"
#include <cstddef>

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(std::string kind) {
    // TODO: Return true if you need a license for that kind of vehicle.
    if (kind == "car" || kind == "truck") {
        return true;
    }
    return false;
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(std::string option1, std::string option2) {
    if (option1.empty() || option2.empty()) {
        return NULL;
    }
    std::string choice{};
    std::string message = " is clearly the better choice.";
    size_t option1_i{0}, option2_i{0};
    bool option1_has_indexes = option1_i < option1.length() && option2_i == option2.length() - 1;
    bool option2_has_indexes = option2_i < option2.length() && option1_i == option1.length() - 1;
    bool running =
        (option1_i < option1.length() && option2_i < option2.length()) || option1_has_indexes || option2_has_indexes;
    while (running) {
        if (option1[option1_i] < option2[option2_i]) {
            choice = option1;
            break;
        } else if (option2[option2_i] < option1[option1_i]) {
            choice = option2;
            break;
        }
        if (option1_i < option1.length() && option2_i < option2.length()) {
            option1_i++;
            option2_i++;
        } else if (option1_has_indexes) {
            option1_i++;
        } else if (option1_has_indexes) {
            option2_i++;
        } else {
            break;
        }
    }
    return choice + message;
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    if (age < 3.0 && age != 0.0) {
        return original_price - original_price * 0.2;
    }
    if (age >= 3.0 && age < 10.0) {
        return original_price - original_price * 0.3;
    }
    if (age >= 10.0) {
        return original_price - original_price * 0.5;
    }
    return original_price;
}

} // namespace vehicle_purchase

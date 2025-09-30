#include <iostream>
#include <string>
#include "payment_modes.hpp"

// String → Enum converter
PaymentMode toPaymentMode(const std::string& method) {
    static const std::unordered_map<std::string, PaymentMode> lookup = {
        {"paypal", PaymentMode::PayPal},
        {"googlepay", PaymentMode::GooglePay},
        {"creditcard", PaymentMode::CreditCard}
    };

    std::string m = method;
    std::transform(m.begin(), m.end(), m.begin(), ::tolower);

    auto it = lookup.find(m);
    return (it != lookup.end()) ? it->second : PaymentMode::Unknown;
}

int main() {
    double amount;
    std::string modeStr;

    std::cout << "Enter payment amount: ";
    std::cin >> amount;
    std::cin.ignore();

    std::cout << "Enter payment mode (PayPal, GooglePay, CreditCard): ";
    std::getline(std::cin, modeStr);

    auto processor = ProcessorFactory::create(modeStr);
    if (processor) {
        std::cout << processor->process(amount) << '\n';
    } else {
        std::cout << "Invalid payment mode selected!\n";
    }

    return 0;
}

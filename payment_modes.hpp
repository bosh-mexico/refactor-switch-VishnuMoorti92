#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>
#include <string>
#include <algorithm>

// Enum for payment modes
enum class PaymentMode {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown
};

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

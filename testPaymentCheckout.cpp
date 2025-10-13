#include "PaymentCheckout.hpp"
#include <iostream>
#include <string>

void testCheckout(PaymentMode mode, double amount, const std::string& expectedModeStr) {
    std::cout << "Test: checkout(" << expectedModeStr << ", " << amount << ")
";
    checkout(mode, amount);
    std::cout << "-----------------------------
";
}

int main() {
    testCheckout(PaymentMode::PayPal, 10.00, "PayPal");
    testCheckout(PaymentMode::GooglePay, 20.00, "GooglePay");
    testCheckout(PaymentMode::CreditCard, 30.00, "CreditCard");
    testCheckout(PaymentMode::Unknown, 0.00, "Unknown");
    return 0;
}

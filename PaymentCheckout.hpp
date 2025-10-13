#ifndef PAYMENTCHECKOUT_HPP
#define PAYMENTCHECKOUT_HPP

#include <string>

// Enum class for Payment Modes
enum class PaymentMode {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown,
    PaymentModeCount
};

// Function declaration for checkout
void checkout(PaymentMode mode, double amount);

#endif // PAYMENTCHECKOUT_HPP

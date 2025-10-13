#include "PaymentCheckout.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void processPayPal(double amount) {
    printf("Processing PayPal payment of $%.2f\n", amount);
}

void processGooglePay(double amount) {
    printf("Processing GooglePay payment of $%.2f\n", amount);
}

void processCreditCard(double amount) {
    printf("Processing Credit Card payment of $%.2f\n", amount);
}

void processUnknown(double amount) {
    printf("Invalid payment mode selected!\n");
}

// Struct for mapping
typedef struct {
    PaymentMode mode;
    void (*processor)(double);
} PaymentProcessorMapping;

// Global mapping table
PaymentProcessorMapping paymentMap[] = {
    { PayPal,      processPayPal },
    { GooglePay,   processGooglePay },
    { CreditCard,  processCreditCard },
    { Unknown,     processUnknown }
};

// Checkout function using mapping table
void checkout(PaymentMode mode, double amount) {
    for (int i = 0; i < PaymentModeCount; i++) {
        if (paymentMap[i].mode == mode) {
            paymentMap[i].processor(amount);
            return;
        }
    }
    // Fallback if mode not found
    processUnknown(amount);
}

// Example usage
int main() {
    double amount1 = 150.75;
    double amount2 = 99.99;

    // Loop through all modes once
    for (int i = 0; i < PaymentModeCount; i++) {
        checkout(paymentMap[i].mode, amount1);
    }

    // Specific calls
    checkout(PayPal, amount2);
    checkout(Unknown, 0.0);

    return 0;
}

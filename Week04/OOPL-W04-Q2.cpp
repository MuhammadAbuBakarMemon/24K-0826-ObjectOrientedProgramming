class Account {
    private:
        double balance;
    
    public:
        Account(double initialBalance) : balance(initialBalance) {
            if (initialBalance < 0) {
                balance = 0;
            }
        }
    
        void credit(double amount) {
            balance += amount;
        }
    
        void debit(double amount) {
            if (amount > balance) {
                balance = 0;
            } else {
                balance -= amount;
            }
        }
    
        double getBalance() const {
            return balance;
        }
    };
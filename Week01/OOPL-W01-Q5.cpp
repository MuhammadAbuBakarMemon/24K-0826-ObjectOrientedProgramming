#include <iostream>
#include <iomanip>
#include <string>

//using namespace std;

int main(void)
{
    std::string m_name;
    float a_t_price = 0.0;
    float c_t_price = 0.0;
    int a_t_sold = 0;
    int c_t_sold = 0;
    float d_p_amt = 0.0;

    std::cout << "Enter Movie Name: " << std::endl;
    std::getline(std::cin, m_name);

    std::cout << "Enter Adult Ticket Price: " << std::endl;
    std::cin >> a_t_price;

    std::cout << "Enter Child Ticket Price: " << std::endl;
    std::cin >> c_t_price;

    std::cout << "Enter the Number of Adult Tickets Sold: " << std::endl;
    std::cin >> a_t_sold;

    std::cout << "Enter the Number of Child Tickets Sold: " << std::endl;
    std::cin >> c_t_sold;

    std::cout << "Enter the Percentage of Gross Amount that is to be Donated to Charity: " << std::endl;
    std::cin >> d_p_amt;

    int t_t_sold = a_t_sold + c_t_sold;
    float g_amt = (a_t_sold * a_t_price) + (c_t_sold * c_t_price);
    float amount_donated = (d_p_amt / 100) * g_amt;
    float net_sale = g_amt - amount_donated;

    std::cout << "\n";
    std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
    std::cout << "Movie Name: " << std::left << std::setw(40) << m_name << std::endl;
    std::cout << "Number of Tickets Sold: " << std::right << std::setw(30) << t_t_sold << std::endl;
    std::cout << "Gross Amount: " << std::right << std::setw(40) << "$" << std::fixed << std::setprecision(2) << g_amt << std::endl;
    std::cout << "Percentage of Gross Amount Donated: " << std::right << std::setw(15) << std::fixed << std::setprecision(2) << d_p_amt << "%" << std::endl;
    std::cout << "Amount Donated: " << std::right << std::setw(35) << "$" << std::fixed << std::setprecision(2) << amount_donated << std::endl;
    std::cout << "Net Sale: " << std::right << std::setw(40) << "$" << std::fixed << std::setprecision(2) << net_sale << std::endl;
    std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;

    return 0;
}

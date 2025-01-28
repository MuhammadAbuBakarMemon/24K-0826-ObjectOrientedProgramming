#include <iostream>
// using namespace std;

int main(void)
{

    string m_name;
    float a_t_price = 0.0;
    float c_t_price = 0.0;    
    int a_t_sold = 0;
    int c_t_sold = 0;
    float d_p_amt = 0.0;

    std::cout << "Enter Movie Name: " << std::endl;
    std::cin >> m_name;

    std::cout << "Enter Adult Ticket Price: " << std::endl;
    std::cin >> a_t_price;

    std::cout << "Enter Child Ticket Price: " << std::endl;
    std::cin >> c_t_price;

    std::cout << "Enter the Number of Adult Tickets Sold: " << std::endl;
    std::cin >> a_t_sold;

    std::cout << "Enter the Number od Child Tickets Sold: " << std::endl;
    std::cin >> c_t_sold;

    std::cout << "Enter the Percentage of Gross Amount that is to be Donated to Charity: " << std::endl;
    std::cin >> d_p_amt;

    

    return 0;
}

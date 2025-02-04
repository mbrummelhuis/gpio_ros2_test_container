#include <wiringPi.h>
#include <string>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

#define PIN1_NUMBER 10
#define PIN2_NUMBER 9
#define PIN3_NUMBER 3
#define PIN4_NUMBER 4

class GPIOTestNode : public rclcpp::Node
{
    public:
        GPIOTestNode() 
        : Node("gpio_test_node")
        {
            timer_ = this->create_wall_timer(50ms, std::bind(&GPIOTestNode::timer_callback, this));
        }
    private:
        void timer_callback()
        {
            printf("Button press result: %d \t %d \t %d \t %d \n", digitalRead(PIN1_NUMBER), digitalRead(PIN2_NUMBER), digitalRead(PIN3_NUMBER), digitalRead(PIN4_NUMBER));
        }
        rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    // Set up wiringOP
    wiringPiSetup();
    pinMode(PIN1_NUMBER, INPUT);
    pinMode(PIN2_NUMBER, INPUT);
    pinMode(PIN3_NUMBER, INPUT);
    pinMode(PIN4_NUMBER, INPUT);
    // Run node
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GPIOTestNode>());
    rclcpp::shutdown();
    return 0;
}

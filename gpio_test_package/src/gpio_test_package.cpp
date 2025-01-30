#include <wiringPi.h>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

#define PIN_NUMBER 13

class GPIOTestNode : public rclcpp::Node
{
    public:
        GPIOTestNode() 
        : Node("gpio_test_node"), state_(0)
        {
            publisher_ = this->create_publisher<std_msgs::msg::String>("press", 10);
            timer_ = this->create_wall_timer(50ms, std::bind(&GPIOTestNode::timer_callback, this));
        }
    private:
        void timer_callback()
        {
            state_ = digitalRead(PIN_NUMBER);
            auto message = std_msgs::msg::String();
            message.data = "Button press result: %i", std::to_string(state_);
            if (digitalRead(PIN_NUMBER)==LOW) {
                RCLCPP_INFO(this->get_logger(), "Low");}
            else if(digitalRead(PIN_NUMBER)==HIGH) {
                RCLCPP_INFO(this->get_logger(), "High");}
            publisher_->publish(message);
        }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        int state_;
};

int main(int argc, char * argv[])
{
    // Set up wiringOP
    wiringPiSetup();
    pinMode(PIN_NUMBER, INPUT);
    // Run node
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GPIOTestNode>());
    rclcpp::shutdown();
    return 0;
}
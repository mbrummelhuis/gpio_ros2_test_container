# gpio_ros2_test_container
Test package in container for experimenting with GPIO feedthrough on Orange Pi 5 to a ROS2 node

You need to install the [wiringOP](https://github.com/orangepi-xunlong/wiringOP)

The idea is to test this package while running it in the Docker container described by the Dockerfile. 
If wiringOP cannot determine the board, you may need to add the board to `/etc/orangepi-release`
```
echo "BOARD=orangepi5pro" | sudo tee /etc/orangepi-release
echo "BOARD=orangepi5B" | sudo tee /etc/orangepi-release
echo "BOARD=orangepi5" | sudo tee /etc/orangepi-release
```
The ROS2 node needs to be run as root because otherwise it cannot acces the GPIO via `/dev/mem`

#include <cstdio>

#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <camera_info_manager/camera_info_manager.hpp>

using namespace std::chrono_literals;

class TestCameraInfoManager : public rclcpp::Node
{
public:
  TestCameraInfoManager()
  : Node("test_cam_info_manager")
  {
      RCLCPP_INFO(rclcpp::get_logger("TestCameraInfoManager"),
              "Starting node" );
      auto nh_left = this->create_sub_node( "left" );
      auto nh_right = this->create_sub_node( "right" );

      RCLCPP_INFO( rclcpp::get_logger("TestCameraInfoManager"),
              "Created sub-node with namespace: %s", nh_left->get_effective_namespace().c_str() );
      RCLCPP_INFO( rclcpp::get_logger("TestCameraInfoManager"),
              "Created sub-node with namespace: %s", nh_right->get_effective_namespace().c_str() );

      RCLCPP_INFO( rclcpp::get_logger("TestCameraInfoManager"),
              "Starting two CameraInfoManager's" );
        
      cam_info_manager_left = std::make_shared<camera_info_manager::CameraInfoManager>(
              nh_left.get(), "left" );
      cam_info_manager_right = std::make_shared<camera_info_manager::CameraInfoManager>(
              nh_right.get(), "right" );

  }

private:
  std::shared_ptr<camera_info_manager::CameraInfoManager> cam_info_manager_left;
  std::shared_ptr<camera_info_manager::CameraInfoManager> cam_info_manager_right;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TestCameraInfoManager>());
  rclcpp::shutdown();
  return 0;
}

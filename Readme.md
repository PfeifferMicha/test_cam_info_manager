Sub-node namespace resolving test
==================================

To run:

```bash
ros2 run test_cam_info_manager  test_cam_info_manager
```

This will output (amongst others):

    /test_cam_info_manager/set_camera_info

but expected output would be:

    /test_cam_info_manager/left/set_camera_info

because the `nh_left` sub-node is used.

The namespaces of the `cam_info_manager_left` and `cam_info_manager_right` seem to be symptoms of the same problem.

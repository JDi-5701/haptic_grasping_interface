
## 1. get the position of the knob

```bash
roslaunch knob_robot_control rosserial.launch
```
get the current position of the knob:
`rostopic echo /knob_state`

```bash
header: 
  seq: 10271
  stamp: 
    secs: 1712875324
    nsecs: 290215154
  frame_id: ''
mode: 
  data: ''
position: 
  data: -4
force: 
  data: 0.0
---
```

**The position should larger than 0, if not, please turn the knob to the right side.**

## 2. Force Feedback
```python
    def publish_force(self, force=1.0) -> None:
        knob_command = KnobCommand()
        knob_command.text.data = "force"
        knob_command.tcp_force.data = float(force) # (0.0 - 2.0) is a good choice
        self.knob_command_pub.publish(knob_command)
```

If you want no force feedback, set the force less than zero. 

**IN FORCE FEEDBACK MODE,  PLEASE KEEP HANDS ON THE KNOB, OTHERWISE THE KNOB WILL ROTATE UNCONTROLLABLY!!!**

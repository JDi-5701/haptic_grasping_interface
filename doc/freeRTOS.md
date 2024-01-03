# FreeRTOS
## 1. functions
### 1.1 Tasks
`xTaskCreatePinnedToCore`
Create a new task with a specified affinity and add it to the list of tasks that are ready to run.


`xTaskCreate()`
```c
Task(const char* name, uint32_t stackDepth, UBaseType_t priority, const BaseType_t coreId = tskNO_AFFINITY) : 
        name { name },
        stackDepth {stackDepth},
        priority { priority },
        coreId { coreId }
{}
```

### 1.2 Queue
`xQueueSend()`
```c
 BaseType_t xQueueSend(
                            QueueHandle_t xQueue,
                            const void * pvItemToQueue,
                            TickType_t xTicksToWait
                         );
```

- `xQueue` 	队列的句柄，数据项将发布到此队列。
- `pvItemToQueue` 	指向待入队数据项的指针。创建队列时定义了队列将保留的项的大小，因此固定数量的字节将从复制到队列存储区域。
- `xTicksToWait` 	如果队列已满，则任务应进入阻塞态等待队列上出现可用空间的最大时间。如果队列已满，并且设置为0 ，调用将立即返回。时间在 tick 周期中定义，因此如果需要，应使用常量 portTICK_PERIOD_MS 转换为实时。
- 如果 INCLUDE_vTaskSuspend 设置为 “1” ，则将阻塞时间指定为 `portMAX_DELAY` 会导致任务无限期地阻塞（没有超时）。

`xQueueReceive()`
```c
 BaseType_t xQueueReceive(
                               QueueHandle_t xQueue,
                               void *pvBuffer,
                               TickType_t xTicksToWait
                            );
```
Receive an item from a queue. The item is received by copy so a buffer of adequate size must be provided. The number of bytes copied into the buffer was defined when the queue was created.


- `xQueue` 	The handle to the queue from which the item is to be received.
- `pvBuffer` 	Pointer to the buffer into which the received item will be copied.
- `xTicksToWait` 	The maximum amount of time the task should block waiting for an item to receive should the queue be empty at the time of the call. Setting xTicksToWait to 0 will cause the function to return immediately if the queue is empty. The time is defined in tick periods so the constant portTICK_PERIOD_MS should be used to convert to real time if this is required.





## 2. Questions
### motor.loopFOC()
What's `motor.loopFOC()` used to? What's the exactly task this function needs to execute?

For the real-time routine of the FOC algorithm we need to add the `motor.loopFOC()` and `motor.move(target)` functions in the Arduino loop().

- `motor.loopFOC()`: FOC algorithm execution - should be executed as fast as possible > 1kHz
- `motor.move(target)`: motion control routine - depends of the motor.controller parameter


### `InterfaceTask::InterfaceTask()`
```c
InterfaceTask::InterfaceTask(const uint8_t task_core, MotorTask& motor_task, DisplayTask* display_task) : 
        Task("Interface", 3000, 1, task_core),
        stream_(),
        motor_task_(motor_task),
        display_task_(display_task),
        plaintext_protocol_(stream_, motor_task_),
        proto_protocol_(stream_, motor_task_) {
    #if SK_DISPLAY
        assert(display_task != nullptr);
    #endif

    log_queue_ = xQueueCreate(10, sizeof(std::string *));
    assert(log_queue_ != NULL);

    knob_state_queue_ = xQueueCreate(1, sizeof(PB_SmartKnobState));
    assert(knob_state_queue_ != NULL);
}
```
构造函数的一项重要功能是对成员变量进行初始化，为了达到这个目的，可以在构造函数的函数体中对成员变量一一赋值，还可以采用初始化列表。
```c 
private:
    UartStream stream_;
    MotorTask& motor_task_;
    DisplayTask* display_task_;

    ...

    SerialProtocolPlaintext plaintext_protocol_;
    SerialProtocolProtobuf proto_protocol_;
```
定义构造函数时并没有在函数体中对成员变量一一赋值，其函数体为空（当然也可以有其他语句），而是在函数首部与函数体之间添加了一个冒号:，后面紧跟m_name(name), m_age(age), m_score(score)语句，这个语句的意思相当于函数体内部的m_name = name; m_age = age; m_score = score;语句，也是赋值的意思。

**使用构造函数初始化列表并没有效率上的优势，仅仅是书写方便，尤其是成员变量较多时，这种写法非常简单明了。**

假如类成员的基类或成员类都定义了默认构造函数（如存在string类型的类成员），**则在初始化时会调用他们的默认构造函数**，但如果在构造函数中又对sting成员进行了赋值，则相当于又进行了一次string的拷贝构造。相反，如果放在初始化列表中则只需要调用一次string类的初始化即可。


## 3. Repos
### Nanopb
Nanopb is a plain-C implementation of Google's Protocol Buffers data format. It is targeted at 32 bit microcontrollers, but is also fit for other embedded systems with tight (<10 kB ROM, <1 kB RAM) memory constraints.

### PacketSerial
An Arduino Library that facilitates packet-based serial communication using COBS or SLIP encoding. PacketSerial is an small, efficient, library that allows Arduinos to send and receive serial data packets (with COBS, SLIP or a user-defined encoding) that include bytes of any value (0 - 255). A packet is simply an array of bytes.


### HX711
An Arduino library to interface the Avia Semiconductor `HX711` 24-Bit Analog-to-Digital Converter (ADC) for reading load cells / weight scales.
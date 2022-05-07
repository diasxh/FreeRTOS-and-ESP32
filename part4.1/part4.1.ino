// Use only core 1 for demo purposes
#if CONFIG_FREERTOS_UNICORE
  static const BaseType_t app_cpu = 0;
#else
  static const BaseType_t app_cpu = 1;
#endif

// Some string to print
const char msg[] = "";

// Task handles
static TaskHandle_t task_1 = NULL;
static TaskHandle_t task_2 = NULL;

// Task: print to Serial Terminal with lower priority
void startTask1(void *parameter) {

  int msg_len = strlen(msg);                   // Count number of characters in string
  // Print string to Terminal
  while (1) {
    Serial.println();
    for (int i = 0; i < msg_len; i++) {
      Serial.print(msg[i]);
    }
    Serial.println();
    vTaskDelay(1000 / portTICK_PERIOD_MS);     //1000ms delay
  }
}

// Task: print to Serial Terminal with higher priority
void startTask2(void *parameter) {
  while (1) {
    Serial.print('*');
    vTaskDelay(100 / portTICK_PERIOD_MS);       //100ms delay
  }
}


void setup() {
  
  Serial.begin(115200);       // Configure Serial
  
  xTaskCreatePinnedToCore(
    startTask1,                //Function to implement the task
    "startTask1",              //Name of the task
    1024,                      //Stack size
    NULL,                      //Task input parameter 
    1,                         //Task priority
    &task_1,                   //Task handle
    app_cpu);                  //Task running core

  xTaskCreatePinnedToCore(
    startTask2,                //Function to implement the task
    "startTask2",              //Name of the task
    1024,                      //Stack size
    NULL,                      //Task input parameter 
    2,                         //Task priority
    &task_2,                   //Task handle
    app_cpu);                  //Task running core

}
void loop() {
  while(1){}
}

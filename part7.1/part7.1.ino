// Cores
int core_A = 0;
int core_B = 1;

// Task handles
static TaskHandle_t task_A = NULL;
static TaskHandle_t task_B = NULL;

void startTaskA(void *parameter) {
  while(1){
    Serial.print("I am Task A I am Running on CORE_");
    Serial.println(xPortGetCoreID());           //Print the core number
    vTaskDelay(500 / portTICK_PERIOD_MS);       //500ms delay
  }
}

void startTaskB(void *parameter) {
  while (1) {
    Serial.print("I am Task B I am Running on CORE_");
    Serial.println(xPortGetCoreID());           //Print the core number
    vTaskDelay(500 / portTICK_PERIOD_MS);       //500ms delay
  }
}

void setup() {
  
  Serial.begin(115200);       // Configure Serial
  
  xTaskCreatePinnedToCore(
    startTaskA,                //Function to implement the task
    "startTaskA",              //Name of the task
    1024,                      //Stack size
    NULL,                      //Task input parameter 
    1,                         //Task priority
    &task_A,                   //Task handle
    core_A);                   //Task running core

  xTaskCreatePinnedToCore(
    startTaskB,                //Function to implement the task
    "startTaskB",              //Name of the task
    1024,                      //Stack size
    NULL,                      //Task input parameter 
    2,                         //Task priority
    &task_B,                   //Task handle
    core_B);                   //Task running core

}
void loop() {
  while(1){}
}

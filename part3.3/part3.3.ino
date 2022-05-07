#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

int ledPin1 = 2;       
int ledPin2 = 4;   
 
void Task1 (void *pvParameters){
  
  while(1){
    Serial.println("Task1");
    digitalWrite(ledPin1, HIGH);             //Lightup the led
    vTaskDelay(500 / portTICK_PERIOD_MS);   //Task delay
    digitalWrite(ledPin1, LOW);              //Off the led
    vTaskDelay(500 / portTICK_PERIOD_MS);   //Task delay
  }
}

void Task2 (void *pvParameters){
  
  while(1){
    Serial.println("Task2");
    digitalWrite(ledPin2, HIGH);             //Lightup the led
    vTaskDelay(300 / portTICK_PERIOD_MS);   //Task delay
    digitalWrite(ledPin2, LOW);              //Off the led
    vTaskDelay(300 / portTICK_PERIOD_MS);   //Task delay
  }
}

void setup(){
    Serial.begin(115200);      // Serial monitor setup
    pinMode(ledPin1, OUTPUT);   // Set GPIO 2 as output
    pinMode(ledPin2, OUTPUT);   // Set GPIO 4 as output

    xTaskCreatePinnedToCore(
      Task1,                   //Function to implement the task
      "Task1",                 //Name of the task
      1024,                    //Stack size
      NULL,                    //Task input parameter 
      1,                       //Task priority
      NULL,                    //Task handle
      app_cpu);                //Task running core

    xTaskCreatePinnedToCore(
      Task2,                   //Function to implement the task
      "Task2",                 //Name of the task
      1024,                    //Stack size
      NULL,                    //Task input parameter 
      1,                       //Task priority
      NULL,                    //Task handle
      app_cpu);                //Task running core  
}
 
void loop(){
  while(1) {}
}

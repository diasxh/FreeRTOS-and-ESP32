#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

int ledPin1 = 2;
int ledPin2 = 4;  

String task1DelayTime="";
String task2DelayTime="";

void Task1 (void *pvParameters){
  
  while(1){
    Serial.println("Task1");
    digitalWrite(ledPin1, HIGH);                               //Lightup the led
    vTaskDelay(task1DelayTime.toInt() / portTICK_PERIOD_MS);   //Task delay
    digitalWrite(ledPin1, LOW);                                //Off the led
    vTaskDelay(task1DelayTime.toInt() / portTICK_PERIOD_MS);   //Task delay
  }
}

void Task2 (void *pvParameters){
  
  while(1){
    Serial.println("Task2");
    digitalWrite(ledPin2, HIGH);                               //Lightup the led
    vTaskDelay(task2DelayTime.toInt() / portTICK_PERIOD_MS);   //Task delay 
    digitalWrite(ledPin2, LOW);                                //Off the led
    vTaskDelay(task2DelayTime.toInt() / portTICK_PERIOD_MS);   //Task delay
  }
}

void setup(){
    Serial.begin(115200);                                               // Serial monitor setup
    Serial.println("Enter the delay time for Task 1 in miliseconds");
    while (Serial.available() == 0) {}                                  //Waiting until hit the enter
    String task1DelayTime=Serial.readString();                          //Obtaining user input for delay time
    Serial.println("Enter the delay time for Task 2 in miliseconds");
    while (Serial.available() == 0) {}                                  //Waiting until hit the enter
    String task2DelayTime=Serial.readString();                          //Obtaining user input for delay time
    pinMode(ledPin1, OUTPUT);                                           // Set LED as output
    pinMode(ledPin2, OUTPUT);                                           // Set LED as output

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

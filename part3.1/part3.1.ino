int ledPin = 2;       //Here I used D2 pin  
int core = 0;       //Here I used core 0
 
void coreTask (void *pvParameters){
  pinMode(ledPin, OUTPUT);   // Set LED as output
  
  while(1){
    digitalWrite(ledPin, HIGH);             //Lightup the led
    vTaskDelay(500 / portTICK_PERIOD_MS);   //Task delay
    digitalWrite(ledPin, LOW);              //Off the led
    vTaskDelay(500 / portTICK_PERIOD_MS);   //Task delay
  }
}

void setup(){
    Serial.begin(115200);      // Serial monitor setup

    xTaskCreatePinnedToCore(
      coreTask,                //Function to implement the task
      "coreTask",              //Name of the task
      1024,                    //Stack size
      NULL,                    //Task input parameter 
      1,                       //Task priority
      NULL,                    //Task handle
      core);                   //Task running core
}
 
void loop(){
  while(1) {}
}

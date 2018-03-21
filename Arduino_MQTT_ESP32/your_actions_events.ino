void do_actions(const char* message) {
  //Create this function according to your actions. you will receive a message something like this
  /* Eg : {
        "action":"actionOne",
        "param":{
          "ac1Value1":"1110" ,
          "parentMac":"6655591876092787",
          "ac1Value4":"port:03",
          "ac1Value5":"on",
          "mac":"6655591876092787",
          "ac1Value2":"2220",
          "ac1Value3":"567776"
        }
      } */
    Serial.println(message);
   
    StaticJsonBuffer<200> jsonBuffer;

    JsonObject& root = jsonBuffer.parseObject(message);
    
    if (!root.success()) {
      Serial.println("Parsing of JSON failed");
      return;
    }
    else{          
        String action = root["action"];
        if(action == "on"){
          send_event();
          String mac = root["param"];
          JsonObject& root = jsonBuffer.parseObject(mac);
          String mac1 = root["mac"];
          if(mac1 == "0777331122112"){
            Serial.println("inside success");
          }
        }
        else if(action == "off"){
          Serial.println("SUCCESS JSON");
          send_event();
        }
        else if(action == "blink"){          
          Serial.println("SUCCESS JSON");   
        }
  }
}
//====================================================================================================================================================================
void send_event() {
  //create this function to send some events to the backend. You should create a message format like this upto 25 values can be included per event and uptp 10 events can be included in the message
 
  char message[] = "{\"eventName\":\"test2\",\"status\":\"act\",\"mac\":\"0777331122112\"}";
  Serial.print(message);
      
  //Should call publish_message() function to send events. Pass your message as parameter
   publish_message(message);
   
}

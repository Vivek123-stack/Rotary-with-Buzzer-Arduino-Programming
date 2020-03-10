/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
 #define outputA 6
 #define outputB 7
 int counter = 0; 
 int aState;
 int aLastState; 
 const int buzzer = 9; 
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode(buzzer, OUTPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
 } 
 void loop() { 
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter=counter+99;
       if(counter>0 && counter<500)
       {
        tone(buzzer, 2000); 
        }
        else if(counter>500 && counter<1000)
        {
          tone(buzzer, 5000); 
          }
          else
          {
             noTone(buzzer);
            }
       
     }
     else {
       counter=counter-99;
        noTone(buzzer);
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
 }

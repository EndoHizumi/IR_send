int led = 6;
int ledPin=13;
const int buttonPin = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;     // the number of the pushbutton pin
const int buttonPin3 = A0;     // the number of the pushbutton pin
const int buttonPin4 = A5;     // the number of the pushbutton pin

int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;         // variable for reading the pushbutton status
int buttonState4 = 0;         // variable for reading the pushbutton status

int buttonStateBefore = 0;         // variable for reading the pushbutton status
int buttonStateBefore2 = 0;         // variable for reading the pushbutton status
int buttonStateBefore3 = 0;         // variable for reading the pushbutton status
int buttonStateBefore4 = 0;         // variable for reading the pushbutton status

int bitsize=6;
int brake[4]={1,1,1,1};
int straight[4]={0,0,0,1};
int back[4]={1,0,0,0};
int right[4]={0,0,1,1};
int left[4]={0,1,0,0};

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(ledPin, OUTPUT);  
  pinMode(buttonPin, INPUT_PULLUP);     
  pinMode(buttonPin2, INPUT_PULLUP); 
  pinMode(buttonPin3, INPUT_PULLUP); 
  pinMode(buttonPin4, INPUT_PULLUP); 
}
void loop() {
   // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
    Straight();
  } 
  else if (buttonState2 == LOW) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
    Right();
  } 
  else if (buttonState3 == LOW) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
    Back();
  } 
  else if (buttonState4 == LOW) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
    Left();
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
    Brake();
  }
  delay(100);
}

void Brake(){
  //データ部の送信
  for(int i = 0;i < bitsize;i++) {
    for(int j = 0; j< 560/26;j++) {// 560μ秒間点灯(38kHz点滅)
      digitalWrite(led,HIGH);
      delayMicroseconds(9); //8.6μ秒点灯
      digitalWrite(led,LOW);
      delayMicroseconds(17); //17μ秒消灯
    }

    if(brake[i]==0) {
      delayMicroseconds(560); // 560μ秒消灯
    } 
    else {
      delayMicroseconds(1690); // 1690μ秒消灯
    }
  }
  for(int j = 0; j< 560/26;j++) {//最後にもう一度点灯。これが無いと最後のビットが判定できない。
    digitalWrite(led,HIGH);
    delayMicroseconds(9);
    digitalWrite(led,LOW);
    delayMicroseconds(17);
  }

  delay(500);


}

void Straight(){
  //データ部の送信
  for(int i = 0;i < bitsize;i++) {
    for(int j = 0; j< 560/26;j++) {// 560μ秒間点灯(38kHz点滅)
      digitalWrite(led,HIGH);
      delayMicroseconds(9); //8.6μ秒点灯
      digitalWrite(led,LOW);
      delayMicroseconds(17); //17μ秒消灯
    }

    if(straight[i]==0) {
      delayMicroseconds(560); // 560μ秒消灯
    } 
    else {
      delayMicroseconds(1690); // 1690μ秒消灯
    }
  }
  for(int j = 0; j< 560/26;j++) {//最後にもう一度点灯。これが無いと最後のビットが判定できない。
    digitalWrite(led,HIGH);
    delayMicroseconds(9);
    digitalWrite(led,LOW);
    delayMicroseconds(17);
  }

  delay(500);


}

void Back(){
  //データ部の送信
  for(int i = 0;i < bitsize;i++) {
    for(int j = 0; j< 560/26;j++) {// 560μ秒間点灯(38kHz点滅)
      digitalWrite(led,HIGH);
      delayMicroseconds(9); //8.6μ秒点灯
      digitalWrite(led,LOW);
      delayMicroseconds(17); //17μ秒消灯
    }

    if(back[i]==0) {
      delayMicroseconds(560); // 560μ秒消灯
    } 
    else {
      delayMicroseconds(1690); // 1690μ秒消灯
    }
  }
  for(int j = 0; j< 560/26;j++) {//最後にもう一度点灯。これが無いと最後のビットが判定できない。
    digitalWrite(led,HIGH);
    delayMicroseconds(9);
    digitalWrite(led,LOW);
    delayMicroseconds(17);
  }

  delay(500);


}


void Right(){
  //データ部の送信
  for(int i = 0;i < bitsize;i++) {
    for(int j = 0; j< 560/26;j++) {// 560μ秒間点灯(38kHz点滅)
      digitalWrite(led,HIGH);
      delayMicroseconds(9); //8.6μ秒点灯
      digitalWrite(led,LOW);
      delayMicroseconds(17); //17μ秒消灯
    }

    if(left[i]==0) {
      delayMicroseconds(560); // 560μ秒消灯
    } 
    else {
      delayMicroseconds(1690); // 1690μ秒消灯
    }
  }
  for(int j = 0; j< 560/26;j++) {//最後にもう一度点灯。これが無いと最後のビットが判定できない。
    digitalWrite(led,HIGH);
    delayMicroseconds(9);
    digitalWrite(led,LOW);
    delayMicroseconds(17);
  }

    delay(500);


}

void Left(){
  //データ部の送信
  for(int i = 0;i < bitsize;i++) {
    for(int j = 0; j< 560/26;j++) {// 560μ秒間点灯(38kHz点滅)
      digitalWrite(led,HIGH);
      delayMicroseconds(9); //8.6μ秒点灯
      digitalWrite(led,LOW);
      delayMicroseconds(17); //17μ秒消灯
    }

    if(right[i]==0) {
      delayMicroseconds(560); // 560μ秒消灯
    } 
    else {
      delayMicroseconds(1690); // 1690μ秒消灯
    }
  }
  for(int j = 0; j< 560/26;j++) {//最後にもう一度点灯。これが無いと最後のビットが判定できない。
    digitalWrite(led,HIGH);
    delayMicroseconds(9);
    digitalWrite(led,LOW);
    delayMicroseconds(17);
  }

  delay(500);


}



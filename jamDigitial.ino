#include <TimerOne.h>
int detik = 0;
int menit = 0;
int jam = 0;
int detik_temp = 0;
int menit_temp = 0;
int jam_temp = 0;
int detik_alarm = 0;
int menit_alarm = 0;
int jam_alarm = 99;
int count_stopwatch = 0;
int stopwatch = 0;
int mode = 0;
int set = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(counter);
}

void counter(void){
   if (detik < 59)
      detik++;
   else{
      detik = 0;
      if (menit < 59)
          menit++;
      else{
          menit = 0;
          if (jam < 23)
              jam++;
          else{
              jam = 0;
          }
      }
   }
   if (stopwatch == 1)
      count_stopwatch++;
}

void sev_seg(int number, int digit){
  if (digit == 10){
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
  }
  else if (digit == 11){
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);  
      digitalWrite(13, LOW);  
  }
  else if (digit == 12){
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH); 
      digitalWrite(13, LOW); 
  }
  else if (digit == 13){
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW); 
      digitalWrite(13, HIGH);    
  }
  if (number == 0){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
  else if (number == 1){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);   
  }
  else if (number == 2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);   
  }
  else if (number == 3){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);   
  }
  else if (number == 4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);   
  }
  else if (number == 5){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);   
  }
  else if (number == 6){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);   
  }
  else if (number == 7){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);   
  }
  else if (number == 8){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);   
  }
  else if (number == 9){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);   
  }
   delay(5);
}

// the loop function runs over and over again forever
void loop() {
    if (digitalRead(14)){
        delay(150);
        mode++;
        set = 0;
    }
    
    if ((jam == jam_alarm) && (menit == menit_alarm) && (detik == detik_alarm)){
        digitalWrite(17, HIGH);  
    }
    
    if (mode%4 == 0){
        if (digitalRead(15)){
            delay(150);
            set++;
        }
        if (set%2 == 0){    
            sev_seg((detik%10), 10);
            sev_seg((detik/10), 11);
            sev_seg((menit%10), 12);
            sev_seg((menit/10), 13);
        }
        else {
            sev_seg((jam%10), 12);
            sev_seg((jam/10), 13);
        }
    }
    else if (mode%4 == 1){
        if (set%3 == 0){
            sev_seg((jam_temp%10), 10);
            sev_seg((jam_temp/10), 11);
            if (digitalRead(16)){
                delay(150);
                jam_temp = (jam_temp + 1)%24;
            }
            if (digitalRead(15)){
                delay(150);
                jam = jam_temp;
                set++;
            }
        }
        else if (set%3 == 1){
            sev_seg((menit_temp%10), 10);
            sev_seg((menit_temp/10), 11);
            if (digitalRead(16)){
                delay(150);
                menit_temp = (menit_temp + 1)%60;
            }
            if (digitalRead(15)){
                delay(150);
                menit = menit_temp;
                set++;
            }
        }
        else {
            sev_seg((detik_temp%10), 10);
            sev_seg((detik_temp/10), 11);
            if (digitalRead(16)){
                delay(150);
                detik_temp = (detik_temp + 1)%60;
            }
            if (digitalRead(15)){
                delay(150);
                detik = detik_temp;
                set++;
            }
        }
    }
    else if (mode%4 == 2){
        if (set%3 == 0){
            sev_seg((jam_temp%10), 12);
            sev_seg((jam_temp/10), 13);
            if (digitalRead(16)){
                delay(150);
                jam_temp = (jam_temp + 1)%24;
            }
            if (digitalRead(15)){
                delay(150);
                jam_alarm = jam_temp;
                set++;
            }
        }
        else if (set%3 == 1){
            sev_seg((menit_temp%10), 12);
            sev_seg((menit_temp/10), 13);
            if (digitalRead(16)){
                delay(150);
                menit_temp = (menit_temp + 1)%60;
            }
            if (digitalRead(15)){
                delay(150);
                menit_alarm = menit_temp;
                set++;
            }
        }
        else {
            sev_seg((detik_temp%10), 12);
            sev_seg((detik_temp/10), 13);
            if (digitalRead(16)){
                delay(150);
                detik_temp = (detik_temp + 1)%60;
            }
            if (digitalRead(15)){
                delay(150);
                detik_alarm = detik_temp;
                set++;
            }
        }
    }
    else {
        sev_seg(((count_stopwatch%60)%10), 10);
        sev_seg(((count_stopwatch%60)/10), 11);
        sev_seg(((count_stopwatch/60)%10), 12);
        sev_seg(((count_stopwatch/60)/10), 13);
        
        if (digitalRead(15)){
            delay(150);
            set++;
        }
        if (set%3 == 0){
            stopwatch = 1;  
        }
        else if (set%3 == 1){
            stopwatch = 0;  
        }
        else {
            count_stopwatch = 0;
            stopwatch = 0;  
        }
    }
}

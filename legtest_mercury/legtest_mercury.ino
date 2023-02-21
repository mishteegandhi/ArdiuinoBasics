#define left_leg 7
#define right_leg  6
#define right_ext 5
#define left_ext 4

#define left_leg_in   digitalWrite(left_leg,HIGH);
#define left_leg_out  digitalWrite(left_leg,LOW);
#define right_leg_in  digitalWrite(right_leg,LOW);
#define right_leg_out digitalWrite(right_leg,HIGH);
#define right_ext_in  digitalWrite(right_ext,LOW);
#define right_ext_out digitalWrite(right_ext,HIGH);
#define left_ext_in   digitalWrite(left_ext,LOW);
#define left_ext_out  digitalWrite(left_ext,HIGH);

#define START 0
#define SELECT 1
#define R1 2
#define R2 3
#define L1 4
#define L2 5
#define R3 6
#define L3 7
#define UP 8
#define LEFT 9
#define DOWN 10
#define RIGHT 11
#define TRIANGLE 12
#define SQUARE 13
#define CROSS 14
#define CIRCLE 15

int LX, LY, RX, RY;
int button[16];
int s_mode = 0;

void receiveData();
void ps();
void rest_pos();

void setup() {
  pinMode(right_leg, OUTPUT);
  pinMode(left_leg, OUTPUT);
  pinMode(right_ext, OUTPUT);
  pinMode(left_ext, OUTPUT);
  Serial.begin(9600);
  //Serial1.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  receiveData();
  ps();
  Serial.print("s_mode is \t\t");
  int currentTime = millis();
  /*Serial.println(s_mode);
    switch (s_mode) {
    case 0:
      rest_pos();
      break;
    case 1:
      pronck_front();
      break;
    case 2:
      walk_front();
      break;
    case 3:
      pronck_back();
      break;
    case 4:
      walk_back();
      break;*/
  }

}

void rest_pos()
{
  right_leg_out;
  left_leg_out;
  right_ext_in;
  left_ext_out
}

void pronck_front() {
  Serial.println("Pronck Front");
  right_ext_out;
  left_ext_out;
  left_leg_out;
  right_leg_out;
  delay_ms(300);
  right_ext_out;
  left_ext_out;
  left_leg_in;
  right_leg_in;
  delay_ms(120);
}

void pronck_back() {
  Serial.println("Pronck Back");
  right_ext_in;                   //proncking back side
  left_ext_in;
  left_leg_out;
  right_leg_out;
  delay_ms(300);
  right_ext_in;
  left_ext_in;
  left_leg_in;
  right_leg_in;
  delay_ms(120);

}

void walk_front() {
  Serial.println("Walk Front");
  right_leg_out;                //walking front side
  left_leg_in;
  right_ext_in;
  left_ext_out;
  delay_ms(75);
  right_leg_out;
  left_leg_in;
  right_ext_out;
  left_ext_in;
  delay_ms(75);
  right_leg_out;
  left_leg_out;
  right_ext_out;
  left_ext_in;
  delay_ms(70);

  right_leg_in;
  left_leg_out;
  right_ext_out;
  left_ext_in;
  delay_ms(75);
  right_leg_in;
  left_leg_out;
  right_ext_in;
  left_ext_out;
  delay_ms(75);
  right_leg_out;
  left_leg_out;
  right_ext_in;
  left_ext_out;
  delay_ms(70);
}

void walk_back() {
  Serial.println("Walk Back");
  right_leg_out;                //walking back side
  left_leg_in;
  right_ext_out;
  left_ext_in;
  delay_ms(75);
  right_leg_out;
  left_leg_in;
  right_ext_in;
  left_ext_out;
  delay_ms(75);
  right_leg_out;
  left_leg_out;
  right_ext_in;
  left_ext_out;
  delay_ms(70);

  right_leg_in;
  left_leg_out;
  right_ext_in;
  left_ext_out;
  delay_ms(75);
  right_leg_in;
  left_leg_out;
  right_ext_out;
  left_ext_in;
  delay_ms(75);
  right_leg_out;
  left_leg_out;
  right_ext_out;
  left_ext_in;
  delay_ms(70);
}
/*void ps() {
  if (button[TRIANGLE] == 1) {
    s_mode = 1;
    button[TRIANGLE] = 0;
  }
  if (button[SQUARE] == 1) {
    s_mode = 2;
    button[SQUARE] = 0;
  }
  if (button[CROSS] == 1) {
    s_mode = 3;
    button[CROSS] = 0;
  }
  if (button[CIRCLE] == 1) {
    s_mode = 4;
    button[CIRCLE] = 0;
  }
  if(button[START] == 1){
    s_mode = 0;
    button[START] = 0;
  }
}*/
void receiveData() {
  //Serial1.begin(9600);
  if (Serial.available()) {
    //Serial.println("Called");
    int data = Serial.read();
    //Serial.print("Data is\t");
    //Serial.println(data);
    if (data == 201) {
      while (!Serial.available());
      LX = Serial
      .read();
      //Serial.print(LX);
      //Serial.print("\t");
    }
    else if (data == 202) {
      while (!Serial.available());
      LY = Serial.read();
      // Serial.print(LY);
      //Serial.print("\t");
    }
    else if (data == 203) {
      while (!Serial.available());
      RX = Serial.read();
      //Serial.print(RX);
      //Serial.print("\t");
    }
    else if (data == 204) {
      while (!Serial.available());
      RY = Serial.read();
      //Serial.println(RY);
    }
    else {
      switch (data) {
        case 237:
          button[TRIANGLE] = 1;
          Serial.print("Triangle is Pressed");
          break;
        case 238:
          button[SQUARE] = 1;
          Serial.print("Square is Pressed");
          break;
        case 239:
          button[CROSS] = 1;
          Serial.print("X is Pressed");
          break;
        case 240:
          button[CIRCLE] = 1;
          Serial.print("Circle is Pressed");
          break;
        case 241:
          button[UP] = 1;
          Serial.print("Up is Pressed");
          walk_front();
          break;

        case 242:
          button[LEFT] = 1;
          Serial.print("Left is Pressed");
          break;

        case 243:
          button[DOWN] = 1;
          Serial.print("Down is Pressed");
          walk_back();
          break;

        case 244:
          button[RIGHT] = 1;
          Serial.print("Right is Pressed");
          break;

        case 231:
          button[L1] = 1;
          Serial.print("L1 is Pressed");
          break;

        case 232:
          button[R1] = 1;
          Serial.print("R1 is Pressed");
          break;

        case 233:
          button[L2] = 1;
          Serial.print("L2 is Pressed");
          break;

        case 234:
          button[R2] = 1;
          Serial.print("R2 is Pressed");
          break;

        case 235:
          button[L3] = 1;
          Serial.print("L3 is Pressed");
          break;

        case 236:
          button[R3] = 1;
          Serial.print("R3 is Pressed");
          break;

        case 245:
          button[START] = 1;
          Serial.print("Start is Pressed");
          break;

        case 246:
          button[SELECT] = 1;
          Serial.print("Select is Pressed");
          break;

      }
    }
  }
}


void delay_ms(int delayTime) {
  int currentTime = millis();
  while (millis() - currentTime <= delayTime) {
    receiveData();
    //ps();
  }
}
